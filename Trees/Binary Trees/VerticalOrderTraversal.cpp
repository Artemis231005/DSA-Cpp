#include <iostream>
#include <queue>
#include <map>
#include <set>
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

    // TC: O(N logN) (BFS: O(N), insertion into multiset: O(logN))      SC: O(N) 
    vector<vector<int>> verticalOrderTraversal(Node* root) { 
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> todo;

        if (root == NULL) {
            return {};
        }
        todo.push({root, {0, 0}});

        while(!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            Node* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(temp->data);

            if(temp->left) {
                todo.push({temp->left, {x-1, y+1}});
            }
            if(temp->right) {
                todo.push({temp->right, {x+1, y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto p: nodes) {
            vector<int> col;
            for(auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }

    void dfs(Node* root, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        if (root == NULL) {
            return;
        }

        // preorder
        nodes[x][y].insert(root->data);
        dfs(root->left, x - 1, y + 1, nodes);
        dfs(root->right, x + 1, y + 1, nodes);

        // inorder 
        // dfs(root->left, x - 1, y + 1, nodes);
        // nodes[x][y].insert(root->data);
        // dfs(root->right, x + 1, y + 1, nodes);

        // postorder 
        // dfs(root->left, x - 1, y + 1, nodes);
        // dfs(root->right, x + 1, y + 1, nodes);
        // nodes[x][y].insert(root->data);
    }

    vector<vector<int>> verticalOTthruDFS(Node* root) {
    map<int, map<int, multiset<int>>> nodes;
    dfs(root, 0, 0, nodes);

    vector<vector<int>> ans;
    for (auto &p : nodes) {
        vector<int> col;
        for (auto &q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

};

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

    vector<vector<int>> ans = tree.verticalOTthruDFS(tree.root);
    cout << "The vertical order traversal is: " << endl;
    for(auto &vec: ans) {
        for(auto val: vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
