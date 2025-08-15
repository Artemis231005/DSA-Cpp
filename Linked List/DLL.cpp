#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node (int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DLL {
    Node* head;
    Node* tail;

    public:
    DLL() {
        head = tail = NULL;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node (data);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int data) {
        if (head == NULL) {
            insertAtHead(data);
            return;
        }

        Node* newNode = new Node (data);

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtPos (int pos, int data) {
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0) {
            insertAtHead(data);
            return;
        }

        Node* temp = head;
        int i = 0;
        while (temp != NULL && i < pos-1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        if (temp->next == NULL) {
            insertAtTail(data);
            return;
        } 
        
        Node* newNode = new Node (data);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;        
    }

    void insertBeforeValue(int value, int data) {
    if (head == NULL) {
        return;
    }

    if (head->data == value) {
        insertAtHead(data);
        return;
    }

    Node* temp = head->next;            // Start from second node
    while (temp && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* newNode = new Node(data);
    Node* prevNode = temp->prev;

    newNode->next = temp;
    newNode->prev = prevNode;
    prevNode->next = newNode;
    temp->prev = newNode;
}


    void deleteHead () {
        if (head == NULL) {
            return;
        } 

        Node* toDelete = head;
        if (head == tail) { 
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete toDelete;
    }

    void deleteTail() {
        if (head == NULL) {
            return;
        } 
        
        Node* toDelete = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete toDelete;
    }

    void deleteAtPos (int pos) {
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0) {
            deleteHead();
            return;
        }

        Node* temp = head;
        int i = 0;
        while (temp != NULL && i < pos-1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* toDelete = temp->next;
        if (toDelete == tail) {
            deleteTail();
            return;
        }
        temp->next = toDelete->next;
        toDelete->next->prev = temp;
        delete toDelete;
    }

    void deleteByValue(int value) {
    if (head == NULL) {
        return;
    } 

    Node* temp = head;
    if (head->data == value) {
        deleteHead();
        return;
    }

    while (temp && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }
    if (temp == tail) {
        deleteTail();
        return;
    }

    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete temp;
}

    void search(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not found" << endl;
    }

    int length() {
        Node* temp = head;
        int len = 0;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DLL list;
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.insertAtPos(2, 25);
    list.display();

    cout << "Insert 15 before 20:\n";
    list.insertBeforeValue(20, 15);
    list.display();

    list.deleteHead();
    list.display();

    list.deleteTail();
    list.display();

    list.deleteAtPos(2);
    list.display();

    cout << "Delete node with value 25:";
    list.deleteByValue(25);
    list.display();

    cout << "\nDoes list contain 30? ";
    list.search(30);

    cout << "Length of the list is: " << list.length() << endl;
    return 0;
}