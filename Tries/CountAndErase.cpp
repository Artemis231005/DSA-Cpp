#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* links[26];
    int cntendWith = 0;
    int cntPrefix = 0;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put (char ch, Node* node) {
        links[ch - 'a'] = node;                             
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void increaseEndWith() {
        cntendWith++;                                       
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void decreaseEndWith() {
        cntendWith--;
    }

    void decreasePrefix() {
        cntPrefix--;
    }
};

class Trie {                                                    // TC: O(N) for functions
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert (string word) {                                     
        Node* temp = root;
        for (int i=0; i<word.size(); i++) {
            if (!temp->containsKey(word[i])) {
                temp->put(word[i], new Node());
            }
            temp = temp->get(word[i]);
            temp->increasePrefix();
        }
        temp->increaseEndWith();
    }

    int countWordsEqualTo(string &word) {
        Node* temp = root;
        for (int i=0; i<word.size(); i++) {
            if(temp->containsKey(word[i])) {
                temp = temp->get(word[i]);
            } else {
                return 0;
            }
        }
        return temp->cntendWith;
    }

    int countWordsStartingWith(string &word) {
        Node* temp = root;
        for (int i=0; i<word.size(); i++) {
            if(temp->containsKey(word[i])) {
                temp = temp->get(word[i]);
            } else {
                return 0;
            }
        }
        return temp->cntPrefix;
    }

    void erase(string &word) {
        Node* temp = root;
        for (int i=0; i<word.size(); i++) {
            if(temp->containsKey(word[i])) {
                temp = temp->get(word[i]);
                temp->decreasePrefix();
            } else {
                return;
            }
        }
        temp->decreaseEndWith();
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

    cout << "Enter a word to count its occurrences: ";
    cin >> word;
    cout << "Count of word '" << word << "': " << trie.countWordsEqualTo(word) << endl;

    cout << "Enter a prefix to count words starting with it: ";
    cin >> word;
    cout << "Words starting with '" << word << "': " << trie.countWordsStartingWith(word) << endl;

    cout << "Enter a word to erase: ";
    cin >> word;
    trie.erase(word);
    cout << "After erasing, count of word '" << word << "': " << trie.countWordsEqualTo(word) << endl;

    return 0;
}