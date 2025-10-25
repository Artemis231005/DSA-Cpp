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

            if (temp->right) {
                st.push(temp->right);
            }
            if (temp->left) {
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

        while(!st.empty() || temp != NULL) {
            while (temp!= NULL) {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            cout << temp->data << " ";

            temp = temp->right;
        }
    }

    void postOrder2Stack(Node* root) {     // TC: O(N) (each node is visited)  SC: O(2N) (worst)
        if (root == NULL) {
            return;
        }
        stack <Node*> st1, st2;
        st1.push(root);

        while(!st1.empty()) {
            Node* temp = st1.top();
            st1.pop();
            st2.push(temp);

            if (temp->left) {
                st1.push(temp->left);
            }
            if (temp->right) {
                st1.push(temp->right);
            }
        }

        while(!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }
    }

    void postOrder1Stack(Node* root) {      // TC: O(2N) (pushing & pooping N nodes in stack)   SC: O(N)
        if (root == NULL) {
            return;
        }
        stack<Node*> st;
        Node* curr = root;
        Node* temp;

        while(!st.empty() || curr != NULL) {
            if (curr != NULL) {
                st.push(curr);
                curr =curr->left;
            } else  {
                temp = st.top()->right;

                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        cout << temp->data << " ";
                    }
                } else {
                    curr = temp;
                }
            }
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
    cout << "\nPost-order traversal using 2 stacks: ";
    tree.postOrder2Stack(tree.root);
    cout << "\nPost-order traversal using 1 stack: ";
    tree.postOrder1Stack(tree.root);
    return 0;
}



// #include <iostream>
// using namespace std;

// class Node {
//     public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

// class BST {
// public:
//     Node* root;

//     BST() {
//         root = NULL;
//     }

//     void insertNode(int val) {    
//         Node* newNode = new Node(val);
//         if (root == NULL) {
//             root = newNode;
//             return;
//         }

//         Node* temp = root;
//         while (temp != NULL) {
//             if (temp->data < val) {
//                 if (temp->right != NULL) {
//                     temp = temp->right;
//                 } else {
//                     temp->right = newNode;
//                     return;
//                 }
//             } else {
//                 if (temp->left != NULL) {
//                     temp = temp->left;
//                 } else {
//                     temp->left = newNode;
//                     return;
//                 }
//             }
//         }
//     }
// };

// int main() {
//     BST tree;
//     tree.insertNode(6);
//     tree.insertNode(3);
//     tree.insertNode(8);
//     tree.insertNode(2);
//     tree.insertNode(4);
//     tree.insertNode(7);

//     return 0;
// }
