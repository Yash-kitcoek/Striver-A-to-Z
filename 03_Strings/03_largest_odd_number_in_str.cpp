#include<iostream>
#include<string>
using namespace std;

string largest_odd_num(string &s) {
    int n = s.size();
    int idx = -1;

    for(int i = n-1; i >= 0; i--) {
        if((s[i] - '0') % 2 == 1) {
            idx = i;
            break;
        }
    }

    int i=0;
    while(i <= idx && s[i] == '0')i++;

    return s.substr(i, idx-i+1);
}

int main() {

    string s = "594";

    cout << largest_odd_num(s);
}