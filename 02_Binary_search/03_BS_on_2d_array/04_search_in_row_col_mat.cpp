#include<iostream>
#include<vector>
using namespace std;

pair<int,int>  search(vector<vector<int>> mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int row = 0;
    int col = m-1;

    while(row <= n && col >= 0) {
        if(mat[row][col] == target) {
            return {row, col};
        }else if(mat[row][col] > target) {
            col--;
        }else {
            row++;
        }
    }
}

int main() {
    vector<vector<int>> mat = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24}};
    int target = 14;

    pair<int, int> result = search(mat,target);

    if (result.first != -1)
        cout << "Found at (" << result.first << ", "
             << result.second << ") (0-indexed)" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}