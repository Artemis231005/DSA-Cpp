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

    void preInPostTraversal (Node* root) {      // TC: O(3N or N) (each node is pushed & popped at most 3 times)  SC: O(N)
        stack<pair<Node*, int>> st;
        st.push({root, 1});
        vector<int> pre, in, post;

        if (root == NULL) {
            return;
        }

        while(!st.empty()) {
            auto it = st.top();
            st.pop();

            // pre 
            if (it.second  == 1) {
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);

                // go to left side 
                if(it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }

            // InOrder
            else if(it.second == 2) {
                in.push_back(it.first->data);
                it.second++;
                st.push(it);

                // Go to right
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }

            // Post
            else {
                post.push_back(it.first->data);
            }
        }

        cout << "Pre-order traversal: ";
        for (int x : pre) {
            cout << x << " ";
        }
        cout << "\nIn-order traversal: ";
        for (int x : in) {
            cout << x << " ";
        }
        cout << "\nPost-order traversal: ";
        for (int x : post) {
            cout << x << " ";
        }
        cout << endl;
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
    
    tree.preInPostTraversal(tree.root);
    return 0;
}
