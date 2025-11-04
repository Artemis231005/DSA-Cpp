#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, u, v;
    cout << "Enter the values of n and m: ";
    cin >> n >> m;

    vector<int> adj[100];

    cout << "Enter the edges: " << endl;
    for (int i=0; i<m; i++) { 
        cin >> u >> v;                      
        adj[u].push_back(v);                        
        adj[v].push_back(u);
    }
    return 0;
}

#include <iostream>
using namespace std;

class BTreeNode {
public:
    int *keys;
    int t; 
    BTreeNode **children;
    int n;
    int leaf;

    BTreeNode(int temp, int boolLeaf) {
        t = temp;
        leaf = boolLeaf;
        keys = new int[2 * t - 1];
        children = new BTreeNode *[2 * t];
        n = 0;
    }

    void traverse() {
        int i;
        for (i = 0; i < n; i++) {
            if (leaf == 0) {
                children[i]->traverse();
            }
            cout << keys[i] << " ";
        }
        if (leaf == 0) {
            children[i]->traverse();
        }
    }

    int findKey(int k) {
        int idx = 0;
        while (idx < n && keys[idx] < k) {
            ++idx;
        }
        return idx;
    }

    void insertNonFull(int k) {
        int i = n - 1;
        if (leaf == 1) {
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            n = n + 1;
        } else {
            while (i >= 0 && keys[i] > k) {
                i--;
            }
            if (children[i + 1]->n == 2 * t - 1) {
                splitChild(i + 1, children[i + 1]);
                if (keys[i + 1] < k) {
                    i++;
                }
            }
            children[i + 1]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode *y) {
        BTreeNode *z = new BTreeNode(y->t, y->leaf);
        z->n = t - 1;
        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t];
        }
        if (y->leaf == 0) {
            for (int j = 0; j < t; j++) {
                z->children[j] = y->children[j + t];
            }
        }
        y->n = t - 1;
        for (int j = n; j >= i + 1; j--) {
            children[j + 1] = children[j];
        }
        children[i + 1] = z;
        for (int j = n - 1; j >= i; j--) {
            keys[j + 1] = keys[j];
        }
        keys[i] = y->keys[t - 1];
        n = n + 1;
    }
};

class BTree {
public:
    BTreeNode *root;
    int t;

    BTree(int temp) {
        root = NULL;
        t = temp;
    }

    void traverse() {
        if (root != NULL) {
            root->traverse();
        }
    }

    void insert(int k) {
        if (root == NULL) {
            root = new BTreeNode(t, 1);
            root->keys[0] = k;
            root->n = 1;
        } else {
            if (root->n == 2 * t - 1) {
                BTreeNode *newRoot = new BTreeNode(t, 0);
                newRoot->children[0] = root;
                newRoot->splitChild(0, root);
                int i = 0;
                if (newRoot->keys[0] < k) {
                    i++;
                }
                newRoot->children[i]->insertNonFull(k);
                root = newRoot;
            } else {
                root->insertNonFull(k);
            }
        }
    }
};

int main() {
    BTree tree(3); 
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    cout << "Traversal of the B-Tree is: ";
    tree.traverse();
}
