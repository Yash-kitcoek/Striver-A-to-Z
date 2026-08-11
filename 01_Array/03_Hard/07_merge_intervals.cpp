#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// vector<vector<int>> mergeOverlap(vector<vector<int>> &arr) {
//     int n = arr.size();

//     sort(arr.begin(), arr.end());

//     vector<vector<int>> res;

//     for(int i=0; i<n; i++) {
//         int st = arr[i][0];
//         int end = arr[i][1];

//         if(!res.empty() && res.back()[1] >= end) {
//             continue;
//         }

//         for(int j=i+1; j<n; j++) {
//             if(arr[j][0] <= end) {
//                 end = max(end, arr[j][1]);
//             }
//         }
//         res.push_back({st, end});
//     }
//     return res;
// }

vector<vector<int>> mergeOverlap(vector<vector<int>> arr) {
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(auto curr : arr) {
        if(ans.empty() || curr[0] > ans.back()[1]) {
            ans.push_back(curr);
        }else {
            ans.back()[1] = max(ans.back()[1], curr[1]);
        }
    }
    return ans;
}

int main() {
    
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    vector<vector<int>> res = mergeOverlap(arr);

    for(auto it : res) {
        cout << it[0] << " " << it[1] << endl;
    }

}