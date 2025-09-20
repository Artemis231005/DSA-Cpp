#include <iostream>
#include <queue>
#include<stack>
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

    vector<int> preOrder (Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        stack<Node*> st;
        st.push(root);

        while(!st.empty()) {
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);

            if (temp->right != NULL) {
                st.push(temp->right);
            }
            if (temp->left != NULL) {
                st.push(temp->left);
            }
        }

        return ans;
    }

    vector<int> inOrder(Node* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }

        stack<Node*> st;
        Node* temp = root;

        while (temp != NULL || !st.empty()) {
            while(temp != NULL) {
                st.push(temp);
                temp = temp->left;
            }

            temp = st.top();
            st.pop();
            ans.push_back(temp->data);

            temp = temp->right;
        }
        return ans;
    }

    vector<int> postOrder2Stack(Node* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
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
            ans.push_back(st2.top()->data);
            st2.pop();
        }
    }

    vector<int> postOrder1Stack(Node* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }

        stack<Node*> st;
        Node* temp;
        Node* curr = root;

        while(curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                temp = st.top()->right;

                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }
        
    }
};

void display(vector<int> ans) {
    for(int i: ans) {
        cout << i << " ";
    }
    cout << endl;
} 

int main() {
    BT tree;
    int n, val;
    cout << "Enter no of nodes that you want to enter: ";
    cin >> n;

    cout << "Enter the values in the node: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        tree.insertNode(val);
    }

    vector<int> ans = tree.preOrder(tree.root);
    display(ans);
    ans = tree.inOrder(tree.root);
    display(ans);
    ans = tree.postOrder2Stack(tree.root);
    display(ans);
    ans = tree.postOrder1Stack(tree.root);
    display(ans);
    return 0;
}

// #include <iostream>
// #include <queue>
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

// class BT {
// public:
//     Node* root;

//     BT() {
//         root = NULL;
//     }

//     void insertNode(int value) {
//         Node* newNode = new Node(value);
//         if (root == NULL) {
//             root = newNode;
//             return;
//         }

//         queue<Node*> q;
//         q.push(root);

//         while (!q.empty()) {
//             Node* temp = q.front();
//             q.pop();

//             if (temp->left == NULL) {
//                 temp->left = newNode;
//                 return;
//             } else {
//                 q.push(temp->left);
//             }

//             if (temp->right == NULL) {
//                 temp->right = newNode;
//                 return;
//             } else {
//                 q.push(temp->right);
//             }
//         }
//     }
// };

// int main() {
//     BT tree;
//     int n, val;
//     cout << "Enter no of nodes that you want to enter: ";
//     cin >> n;

//     cout << "Enter the values in the node: ";
//     for (int i=0; i<n; i++) {
//         cin >> val;
//         tree.insertNode(val);
//     }
//     return 0;
// }
