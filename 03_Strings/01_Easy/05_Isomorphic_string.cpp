#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Brute force :- O(n^2), O(1)
// bool isIsomorphic(string &s1, string &s2) {
//     int n = s1.size();
//     int m = s2.size();

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<i; j++) {
//             if(s1[i] == s1[j] != s2[i] == s2[j]) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }


//Optimal - O(n), O(1)
bool isIsomorphic(string &s1, string &s2) {

    if(s1.size() != s2.size()) {
        return false;
    }

    int m1[256] = {0};
    int m2[256] = {0};

    for(int i=0; i<s1.size(); i++) {
        if(m1[s1[i]] != m2[s2[i]]) {
            return false;
        }

        m1[s1[i]] = i+1;
        m2[s2[i]] = i+1;
    }
    return true;
}

int main() {
    string s1 = "hello";
    string s2 = "Gello";

    cout << isIsomorphic(s1,s2);


}