#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node* links[26];
    // bool flag = false;                                   // no need for flag

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
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    int countDistinctSubstr(string &word) {
        int cnt = 0;
        
        for(int i=0; i<word.size(); i++) {
            Node* temp = root;
            for (int j=i; j<word.size(); j++) {
                if(!temp->containsKey(word[j])) {
                    cnt++;
                    temp->put(word[j], new Node());
                }
                temp = temp->get(word[j]);
            }
        }
        return cnt + 1;                                 // + 1 for empty str
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
        int distinct = trie.countDistinctSubstr(word);
        cout << "Number of distinct substrings in '" << word << "': " << distinct << endl;
    }
     
    return 0;
}