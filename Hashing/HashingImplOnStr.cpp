#include<iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int hash[256] = {0};
    for (int i=0; i<s.size(); i++) {
        hash[s[i]] ++;
    }

    char f;
    cout << "Enter the character whose frequency you want: "; 
    cin >> f;
    cout << "Frequency of " << f << " is: " << hash[f];

    return 0;
}
// You don’t need to subtract '0' or 'a' in this case because you're using a hash[256] array, which directly maps each ASCII character 
// to an index in the array.