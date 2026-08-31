#include<iostream>
#include<string>
using namespace std;

int max_parenthesis(string s) {
    int count = 0;
    int ans = 0;

    for(char ch : s) {
        if(ch == '(') {
            count++;
            ans = max(ans, count);
        }else if(ch == ')') {
            count--;
        }
    }
    return ans;
}

int main() {
    string s = "(1+(2*3)+((8)/4))+1";

    cout << max_parenthesis(s);
}