#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <climits>
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

            if (i < vec.size() && vec[i] != "null") {
                curr->left = new Node(stoi(vec[i]));
                q.push(curr->left);
            }
            i++;

            if (i < vec.size() && vec[i] != "null") {
                curr->right = new Node(stoi(vec[i]));
                q.push(curr->right);
            }
            i++;
        }
    }

    int maxWidth(Node* root) {      // TC: O(N)   SC: O(N)
        if (root == NULL) {
            return 0;
        }

        int ans = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int size = q.size();
            int minIdx = q.front().second;
            int first, last;

            for (int i=0; i<size; i++) {
                int currIdx = q.front().second - minIdx;
                Node* temp = q.front().first;
                q.pop();

                if (i == 0) {
                    first = currIdx;
                }
                if (i == size - 1) {
                    last = currIdx;
                }
                if (temp->left != NULL) {
                    q.push({temp->left, 2*currIdx + 1});
                }
                if (temp->right != NULL) {
                    q.push({temp->right, 2*currIdx + 2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
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

    cout << "Max width of BT is: " << tree.maxWidth(tree.root) << endl;
    return 0;
}
