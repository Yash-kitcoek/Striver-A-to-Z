#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& mat) {
        bool setRowZero = false;
        bool setcolZero = false;

        int n = mat.size();
        int m = mat[0].size();

        for(int j = 0; j < m; j++) {
            if(mat[0][j] == 0) {
                setRowZero = true;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 0) {
                setcolZero = true;
                break;
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j < m; j++) {
                if(mat[i][j] == 0) {
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
            }
        }

        for(int i=1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[0][j] == 0 || mat[i][0] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        if(setRowZero) {
            for(int j=0; j<m; j++) {
                mat[0][j] = 0;
            }
        }

        if(setcolZero) {
            for(int i=0; i<n; i++) {
                mat[i][0] = 0;
            }
        }

        for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() { 
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};

    setZeroes(mat);

    
    

}
