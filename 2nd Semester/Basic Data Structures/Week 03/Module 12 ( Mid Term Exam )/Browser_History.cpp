#include <bits/stdc++.h>
using namespace std;

int main() {
    list<string> ll;
    list<string>::iterator it;
    list<string>::iterator temp;
    string s;
    cin >> s;
    while (s != "end") {
        ll.push_back(s);
        cin >> s;
    }
    int q;
    cin >> q;
    cin.ignore();
    while (q--) {
        string command;
        getline(cin, command);
        stringstream ss(command);
        string word;
        ss >> word;
        if (word == "visit") {
            ss >> word;
            it = find(ll.begin(), ll.end(), word);
            if (it != ll.end()) {
                cout << word << endl;
                temp = it;
            } else {
                cout << "Not Available" << endl;
                it = temp;
            }
        } else if (word == "prev") {
            if (it != ll.end()) {
                it--;
                if(it != ll.end()) {
                    cout << *it << endl;
                    temp = it;
                } else {
                    cout << "Not Available" << endl;
                    it = temp;
                }
                
            } else {
                cout << "Not Available" << endl;
            } 
        } else if (word == "next") {
            if (it != ll.end()) {
                it++;
                if(it != ll.end()) {
                    cout << *it << endl;
                    temp = it;
                } else {
                    cout << "Not Available" << endl;
                    it = temp;
                }
                
            } else {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}