#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put (char ch, Node* node) {
        links[ch - 'a'] = node;                             // Assigning reference node for this char
        // Now new char is created which will point to a new trie/ creates link for this char to the given child node
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;                                        // Use to denote the end of a valid word
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert (string word) {                                     // TC: O(length of word)
        Node* temp = root;
        for (int i=0; i<word.length(); i++) {
            if (!temp->containsKey(word[i])) {
                temp->put(word[i], new Node());
            }

            temp = temp->get(word[i]);                              // // Move to the child node (ref var)
        }
        temp->setEnd();                                             // Mark the last node as end of a word
    }

    bool search (string word) {                                     // TC: O(N)
        Node* temp = root;
        for (int i=0; i<word.length(); i++) {
            if (!temp->containsKey(word[i])) {
                return false;
            }
            temp = temp->get(word[i]);
        }

        return (temp->isEnd() == true);
    }

    bool startsWith (string prefix) {                               // TC: O(N)
        Node* temp = root;
        for (int i=0; i<prefix.length(); i++) {
            if (!temp->containsKey(prefix[i])) {
                return false;
            }
            temp = temp->get(prefix[i]);
        }
        return true;                                        // Don't check end, if we reached valid trie, then word with prefix exists
    }
};

int main() {
    Trie trie;
    int n;

    cout << "Enter number of words to insert: ";
    cin >> n;

    string word;
    cout << "Enter " << n << " words:\n";
    for (int i = 0; i < n; i++) {
        cin >> word;
        trie.insert(word);
    }

    int s;
    cout << "Enter number of words to search: ";
    cin >> s;

    cout << "Enter " << s << " words to search:\n";
    for (int i = 0; i < s; i++) {
        cin >> word;
        if (trie.search(word))
            cout << "'" << word << "' found\n";
        else
            cout << "'" << word << "' not found\n";
    }

    int p;
    cout << "Enter number of prefixes to check: ";
    cin >> p;

    string prefix;
    cout << "Enter " << p << " prefixes:\n";
    for (int i = 0; i < p; i++) {
        cin >> prefix;
        if (trie.startsWith(prefix))
            cout << "Prefix '" << prefix << "' found\n";
        else
            cout << "Prefix '" << prefix << "' not found\n";
    }
     
    return 0;
}