#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class SLL {
private:
    Node* head;

public:
    SLL() {
        head = NULL;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int pos, int data) {
        int len = length();
        if (pos < 1 || pos > len + 1) {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 1) {
            insertAtHead(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;

        for (int i = 1; i < pos - 1; i++) {   // pos -1 as we dont want to go after last elem
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertBeforeVal (int val, int data) {
        if (head == NULL) {                  // cant insert before val if there is no val to begin with
            return;
        }
        if (head->data == val) {
            insertAtHead(data);
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {            // temp->next because we dont wnat to go to last elem
            if (temp->next->data == val) {
                Node* newNode = new Node(data);
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
    }

    void deleteHead () {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;        // use temp to free up memory, as w/o it node still remains, just it is not linked
    }

    void deleteTail () {
        if (head == NULL) {       // 0 elem in list
            return;
        }
        if (head->next == NULL) {
            deleteHead();
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;      // Deleting last elem
        temp->next = NULL;      // Ensuring that last link is to NULL
    }

    void deleteKthElem (int k) {
        int len = length();
        if (k < 1 || k > len) {
            cout << "Invalid position\n";
            return;
        }
        if (k == 1) {
            deleteHead();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < k - 1; i++) {                   // k-1 as 0 based indexing
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void deleteValueElem (int val) {
        if (head == NULL) {
            return;
        }
        if (head->data == val) {
            deleteHead();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL) {          
            if (temp->data == val) {
                prev->next = temp->next;            // temp->next here is same as prev->next->next
                delete temp;                        // free up memory
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            count ++;
        }
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SLL list;
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.insertAtPosition(2, 15);
    list.insertBeforeVal(30, 25);
    list.display();

    cout << "Head Deleted:" << endl;
    list.deleteHead();
    list.display();

    cout << "Tail Deleted:" << endl;
    list.deleteTail();
    list.display();

    int pos;
    cout << "Enter position at which element is to be deleted: ";
    cin >> pos;
    cout << "Element at " << pos << " Deleted" << endl;
    list.deleteKthElem(pos);
    list.display();

    int val;
    cout << "Enter value of element to be deleted: ";
    cin >> val;
    cout << val << " Deleted" << endl;
    list.deleteValueElem(val);
    list.display();

    return 0;
}
