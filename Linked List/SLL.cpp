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
        if (pos <= 1) {
            insertAtHead(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
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
        if (head == NULL || head->next == NULL) {       // 0 elem or 1 elm in list
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;      // Deleting last elem
        temp->next = NULL;      // Ensuring that last link is to NULL
    }

    bool search(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
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
    list.display();

    cout << "Head Deleted:" << endl;
    list.deleteHead();
    list.display();

    cout << "Tail Deleted:" << endl;
    list.deleteTail();
    list.display();

    int x = 15;
    cout << "Element " << x << " : " << (list.search(x) ? "Found\n" : "Not Found\n");
    return 0;
}
