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

    void postOrder2Stack(Node* root) {     // TC: O(N) (each node is visited)  SC: O(2N) (worst)
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

        // We need 2 stacks as we can't move from child to parent in tree
        // We basically do modified preorder traversal ie left and right swapped in normal preorder(root → right → left) in st1 and then 
        // reverse it to get postorder (left → right → root)
    }

    void postOrder1Stack(Node* root) {      // TC: O(2N) (pushing & pooping N nodes in stack)   SC: O(N)
        if (root == NULL) {
            return;
        }

        Node* temp;
        Node* curr = root;
        stack<Node*> st;

        while(curr!=NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                temp = st.top()->right;

                if(temp == NULL) {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";

                    while(!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        cout <<temp->data << " ";
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
