#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Optimal- O(n), O(1)
bool isRotate_string(string s, string goal) {
    if(s.size() != goal.size()) {
        return false;
    }

    string temp = s + s;

    return temp.find(goal) != string ::npos;
}

//Brute force - O(n^2)/ O(n)
// bool isRotate_string(string s, string goal) {

//     if(s.size() != goal.size()) {
//         return false;
//     }
    
//     for(int i=0; i<s.size(); i++) {
//         string roated = s.substr(i) + s.substr(0, i);

//         if(roated == goal) {
//             return true;
//         }
//     }
//     return false;
// }

int main() {
    string s = "goal";
    string goal = "oalg";

    cout << isRotate_string(s, goal);
}