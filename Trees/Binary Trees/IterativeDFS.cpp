#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BT {
public:
    Node* root;

    BT() {
        root = NULL;
    }

    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == NULL) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    void preOrder(Node* root) {     // TC: O(N) (each node is visited)  SC: O(N) (worst)
        if (root == NULL) {
            return;
        }

        stack<Node*> st;
        st.push(root);

        while(!st.empty()) {
            Node* temp = st.top();
            st.pop();

            cout << temp->data << " ";
            if (temp->right != NULL) {
                st.push(temp->right);
            }
            if (temp->left != NULL) {
                st.push(temp->left);
            }
        }
    }

    void inOrder(Node* root) {     // TC: O(N) (each node is visited)  SC: O(N) (worst)
        if (root == NULL) {
            return;
        }

        stack<Node*> st;
        Node* temp = root;

        while (temp != NULL || !st.empty()) {
            // Reach leftmost node
            while (temp != NULL) {
                st.push(temp);
                temp = temp->left;
            }

            temp = st.top();
            st.pop();
            cout << temp->data << " ";

            // Go towards right 
            temp = temp->right;
        }        
    }

    void postOrder2Stack(Node* root) {     // TC: O(N) (each node is visited)  SC: O(N) (worst)
        if (root == NULL) {
            return;
        }

        stack<Node*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            Node* temp = st1.top();
            st1.pop();
            st2.push(temp);

            if (temp->left != NULL) {
                st1.push(temp->left);
            }
            if (temp->right != NULL) {
                st1.push(temp->right);
            }
        }

        while (!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }
    }
};

int main() {
    BT tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(7);
    tree.insertNode(8);
    tree.insertNode(9);
    tree.insertNode(10);
    
    cout << "Pre-order traversal: ";
    tree.preOrder(tree.root);
    cout << "\nIn-order traversal: ";
    tree.inOrder(tree.root);
    cout << "\nPost-order traversal: ";
    tree.postOrder2Stack(tree.root);
    return 0;
}
