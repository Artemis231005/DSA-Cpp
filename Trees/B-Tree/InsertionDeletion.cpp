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

    void remove(int k) {
        int idx = findKey(k);
        if (idx < n && keys[idx] == k) {
            if (leaf) {
                removeFromLeaf(idx);
            } else {
                removeFromNonLeaf(idx);
            }
        } else {
            if (leaf) {
                cout << "The key " << k << " is not in the tree.\n";
                return;
            }
            bool flag = (idx == n);
            if (children[idx]->n < t) {
                fill(idx);
            }
            if (flag && idx > n) {
                children[idx - 1]->remove(k);
            } else {
                children[idx]->remove(k);
            }
        }
    }

    void removeFromLeaf(int idx) {
        for (int i = idx + 1; i < n; ++i) {
            keys[i - 1] = keys[i];
        }
        n--;
    }

    void removeFromNonLeaf(int idx) {
        int k = keys[idx];
        if (children[idx]->n >= t) {
            int pred = getPred(idx);
            keys[idx] = pred;
            children[idx]->remove(pred);
        } else if (children[idx + 1]->n >= t) {
            int succ = getSucc(idx);
            keys[idx] = succ;
            children[idx + 1]->remove(succ);
        } else {
            merge(idx);
            children[idx]->remove(k);
        }
    }

    int getPred(int idx) {
        BTreeNode *cur = children[idx];
        while (!cur->leaf) {
            cur = cur->children[cur->n];
        }
        return cur->keys[cur->n - 1];
    }

    int getSucc(int idx) {
        BTreeNode *cur = children[idx + 1];
        while (!cur->leaf) {
            cur = cur->children[0];
        }
        return cur->keys[0];
    }

    void fill(int idx) {
        if (idx != 0 && children[idx - 1]->n >= t) {
            borrowFromPrev(idx);
        } else if (idx != n && children[idx + 1]->n >= t) {
            borrowFromNext(idx);
        } else {
            if (idx != n) {
                merge(idx);
            } else {
                merge(idx - 1);
            }
        }
    }

    void borrowFromPrev(int idx) {
        BTreeNode *child = children[idx];
        BTreeNode *sibling = children[idx - 1];
        for (int i = child->n - 1; i >= 0; --i) {
            child->keys[i + 1] = child->keys[i];
        }
        if (!child->leaf) {
            for (int i = child->n; i >= 0; --i) {
                child->children[i + 1] = child->children[i];
            }
        }
        child->keys[0] = keys[idx - 1];
        if (!leaf) {
            child->children[0] = sibling->children[sibling->n];
        }
        keys[idx - 1] = sibling->keys[sibling->n - 1];
        child->n += 1;
        sibling->n -= 1;
    }

    void borrowFromNext(int idx) {
        BTreeNode *child = children[idx];
        BTreeNode *sibling = children[idx + 1];
        child->keys[child->n] = keys[idx];
        if (!(child->leaf)) {
            child->children[child->n + 1] = sibling->children[0];
        }
        keys[idx] = sibling->keys[0];
        for (int i = 1; i < sibling->n; ++i) {
            sibling->keys[i - 1] = sibling->keys[i];
        }
        if (!sibling->leaf) {
            for (int i = 1; i <= sibling->n; ++i) {
                sibling->children[i - 1] = sibling->children[i];
            }
        }
        child->n += 1;
        sibling->n -= 1;
    }

    void merge(int idx) {
        BTreeNode *child = children[idx];
        BTreeNode *sibling = children[idx + 1];
        child->keys[t - 1] = keys[idx];
        for (int i = 0; i < sibling->n; ++i) {
            child->keys[i + t] = sibling->keys[i];
        }
        if (!child->leaf) {
            for (int i = 0; i <= sibling->n; ++i) {
                child->children[i + t] = sibling->children[i];
            }
        }
        for (int i = idx + 1; i < n; ++i) {
            keys[i - 1] = keys[i];
        }
        for (int i = idx + 2; i <= n; ++i) {
            children[i - 1] = children[i];
        }
        child->n += sibling->n + 1;
        n--;
        delete sibling;
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
                BTreeNode *s = new BTreeNode(t, 0);
                s->children[0] = root;
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < k) {
                    i++;
                }
                s->children[i]->insertNonFull(k);
                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }

    void remove(int k) {
        if (!root) {
            cout << "The tree is empty\n";
            return;
        }
        root->remove(k);
        if (root->n == 0) {
            BTreeNode *tmp = root;
            if (root->leaf) {
                root = NULL;
            } else {
                root = root->children[0];
            }
            delete tmp;
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

    cout << "\nDeleting 6: ";
    tree.remove(6);
    tree.traverse();

    cout << "\nDeleting 7: ";
    tree.remove(7);
    tree.traverse();

    cout << "\nDeleting 4: ";
    tree.remove(4);
    tree.traverse();
}
