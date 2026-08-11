#include<iostream>
#include<vector>
using namespace std;

vector<int> traversal_matrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<int> ans;

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;

    while(top <= bottom && left <= right) {

        for(int j = left; j <= right; j++) {
            ans.push_back(mat[top][j]);
        }
        top++;

        for(int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--;

        if(top <= bottom) {
            for(int j = right; j >= left; j--) {
                ans.push_back(mat[bottom][j]);
            }
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> ans = traversal_matrix(matrix);

    for(int val : ans) {
        cout << val << " ";
    }

    return 0;
}