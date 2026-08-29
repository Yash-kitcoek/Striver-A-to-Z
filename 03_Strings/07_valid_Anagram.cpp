#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size() != t.size()) {
        return false;
    }

    int freq[256] = {0};

    for(int i=0; i<s.size(); i++) {
        freq[s[i]]++;
        freq[t[i]]--;
    }

    for(int i=0; i<256; i++) {
        if(freq[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {

    string s = "yash";
    string t = "aysh";

    cout << isAnagram(s, t);
}