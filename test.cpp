#include <iostream>
#include <queue>
#include <vector>
#include <string>
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

    void insertNode(vector<string>& vec) {
        if (vec.empty() || vec[0] == "null") {
            return;
        }

        root = new Node(stoi(vec[0]));
        queue<Node*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < vec.size()) {
            Node* curr = q.front();
            q.pop();

            if (vec[i] != "null") {
                curr->left = new Node(stoi(vec[i]));
                q.push(curr->left);
            }
            i++;

            if (vec[i] != "null") {
                curr->right = new Node(stoi(vec[i]));
                q.push(curr->right);
            }
            i++;
        }
    }

    vector<int> BoundaryTraversal (Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        if (!isLeafNode(root)) {
            ans.push_back(root->data);
        }
        leftBoundary(root, ans);
        addLeafNodes(root, ans);
        rightBoundary(root, ans);
    }

    bool isLeafNode(Node* node) {
        if (node == NULL) {
            return false;
        }
        if (node->left == NULL && node->right == NULL) {
            return true;
        }
        return false;
    }

    void leftBoundary(Node* root, vector<int> &ans) {
        Node* temp = root->left;

        while(temp) {
            if (!isLeafNode(temp)) {
                ans.push_back(temp->data);
            }
            if (temp->left) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
    }

    void rightBoundary(Node* root, vector<int> &ans) {
        Node* temp = root->right;
        stack<int> st;

        while(temp) {
            if (!isLeafNode(temp)) {
                st.push(temp->data);
            }
            if (temp->right) {
                temp = temp->right;
            } else{
                temp = temp->left;
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }

    void addLeafNodes (Node* root, vector<int> &ans) {
        if (isLeafNode(root)) {
            ans.push_back(root->data);
            return;
        }

        if (root->left) {
            addLeafNodes(root->left, ans);
        }
        if (root->right) {
            addLeafNodes(root->right, ans);
        }
    }
};

int main() {
    BT tree;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<string> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tree.insertNode(arr);

    vector<int> ans = tree.BoundaryTraversal(tree.root);
    cout << "Boundary Traversal: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
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
