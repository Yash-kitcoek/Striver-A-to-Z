#include<iostream>
#include<string>
#include<climits>
using namespace std;

int string_to_int(string s) {
    int n = s.size();
    int i = 0;

    while(i < n && s[i] == ' ') {
        i++;
    }


    int sign = 1;
    if(i < n && s[i] == '+' && s[i] == '-') {
        sign = s[i] == -1 ? -1 : 1;
        i++;
    }

    long long num = 0;

    while(i < n && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');

        i++;

        if(sign == 1 && num >= INT_MAX) return INT_MAX;
        if(sign == -1 && num <= INT_MIN) return INT_MIN;
    }

    return (int) num * sign;

}

int main() {
    string s = "404 error not found";

    cout << string_to_int(s);
}