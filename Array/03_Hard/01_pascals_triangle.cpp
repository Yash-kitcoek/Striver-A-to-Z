// leetcode 118

#include<iostream>
#include<vector>
using namespace std;

// create all the rows
// vector<vector<int>> pasacals_triangle(int numRows) {
//     vector<vector<int>> ans;

//     for(int row = 0; row < numRows; row++) {
//         vector<int> currRow;
//         long long val = 1;

//         for(int col = 0; col <= row; col++) {
//             currRow.push_back(val);
//             val = val * (row - col) / (col + 1);
//         }

//         ans.push_back(currRow);
//     }

//     return ans;
// }

// if want to create the nth row only

// vector<int> pasacals_triangle(int numRows) {
//     vector<int> ans;
//     long long val = 1;

//     ans.push_back(val);
    
//     for(int col = 1; col < numRows; col++) {
//         val = val * (numRows - col) / col;

//         ans.push_back(val);
//     }
//     return ans;
// }


int main() {
    int numRows = 5;

    // vector<vector<int>> ans = pasacals_triangle(numRows);

    // vector<int> ans = pasacals_triangle(numRows);
    // for all the rows
    // for(auto num : ans) {
    //     for(int nums : num) {
    //         cout << nums << " ";
    //     }
    //     cout << endl;
    // }


   // for a single nth row
    // for(int num : ans) {
    //     cout << num << " ";
    // }

    return 0;
}