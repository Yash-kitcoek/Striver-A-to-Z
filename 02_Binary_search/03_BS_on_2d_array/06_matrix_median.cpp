#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//optimal

int matrix_median(vector<vector<int>> &mat) {

    int r = mat.size();
    int c = mat[0].size();

    // Minimum and maximum value in the matrix
    int low = mat[0][0];
    int high = mat[0][c - 1];

    for (int i = 0; i < r; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][c - 1]);
    }

    // Number of elements that should be before the median
    int required = (r * c) / 2;

    while (low < high) {

        int mid = low + (high - low) / 2;

        // Count elements <= mid
        int count = 0;

        for (int i = 0; i < r; i++) {
            count += upper_bound(
                mat[i].begin(),
                mat[i].end(),
                mid
            ) - mat[i].begin();
        }

        // Median is greater than mid
        if (count <= required) {
            low = mid + 1;
        }
        // mid can be the median
        else {
            high = mid;
        }
    }

    return low;
}

//Brute force - O(nlogn), O(n)
// int matrix_median(vector<vector<int>> &mat) {
//     int n = mat.size();
//     int m = mat[0].size();

//     vector<int> ans;

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             ans.push_back(mat[i][j]);
//         }
//     }

//     sort(ans.begin(), ans.end());

//     return ans[(n * m)/2];

// }

int main() {
    vector<vector<int>> mat = {{1, 3, 5},
                               {2, 6, 9},
                               {3, 6, 9}};

    cout << matrix_median(mat);                           
}