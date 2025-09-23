#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <string>
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

    int maxPathSumCalculate (Node* root) {
        int maxSum = INT_MIN;           // INT_MIN so that we can handle negative values and possible negative path sum
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

    int maxPathSumHelper (Node* node, int &maxSum) {
        if (node == NULL) {
            return 0;
        }

        int lsum = max(0, maxPathSumHelper(node->left, maxSum)); // 0 used so that we can ignore -ve value if it comes from leaf node
        int rsum = max(0, maxPathSumHelper(node->right, maxSum));
        // If both sides are -ve, still better to take as 0 and ence return node->data since that will still be longest path (just that single node)
        maxSum = max (maxSum, node->data + lsum + rsum);

        return max(lsum, rsum) + node->data;
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

    int maxPathSum = tree.maxPathSumCalculate(tree.root);
    cout << "Maximum path sum for this tree is: " << maxPathSum << endl;
    return 0;
}
