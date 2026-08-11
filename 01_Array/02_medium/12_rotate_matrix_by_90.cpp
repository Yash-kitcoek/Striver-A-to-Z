#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> rotate_by_90_clockwise(vector<vector<int>> &mat) {
    int n = mat.size();

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for(int i=0; i<n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }

    return mat;
}


vector<vector<int>> rotate_by_90_anticlockwise(vector<vector<int>> &mat) {
    int n = mat.size();

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

   for(int j=0; j<n; j++) {
    int st = 0, end = n-1;
        
        while(st < end) {
            swap(mat[st][j], mat[end][j]);
            st++;
            end--;
        }
   }

    return mat;
}

int main() {

    vector<vector<int>> mat = {{1,2,3},
                                {4,5,6},
                                {7,8,9}};

    vector<vector<int>> ans = rotate_by_90_clockwise(mat);

    vector<vector<int>> ans2 = rotate_by_90_anticlockwise(mat);

    
    for(auto row : ans) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;

}