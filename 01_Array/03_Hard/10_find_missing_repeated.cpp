#include<iostream>
#include<vector>
using namespace std;

//brute force
// vector<int> repeated_missing(vector<vector<int>> &grid) {
//     int n = grid.size();
//     int N = n * n;

//     vector<int> freq(N+1, 0);

//     for(auto &row : grid) {
//         for(int num : row) {
//             freq[num]++;
//         }
//     }

//     int repeated = -1, missing = -1;
    
//     for(int i= 1; i<=N; i++) {
//         if(freq[i] == 2) repeated = i;
//         if(freq[i] == 0) missing = i;
//     }

//     return {repeated, missing};
// }

//optimal
vector<int> repeated_missing(vector<vector<int>> &grid) {
    int n = grid.size();
    int N = n * n;

    long long actualSum = 0;
    long long actualsqSum = 0;

    for(auto & row : grid) {
        for(int num : row) {
            actualSum += num;
            actualsqSum += 1LL * num * num;
        }
    }

    long long expectedSum = N * (N + 1)/2;
    long long expectedsqSum = N * (N+1) *(2*N+1)/6;

    long long diff = actualSum - expectedSum;
    long long sqdiff = actualsqSum - expectedsqSum;

    long long sumXY = sqdiff / diff;

    long long repeated = (diff + sumXY) / 2;
    long long missing = sumXY - repeated;

    return {(int)repeated, (int)missing};
}

int main() {
    vector<vector<int>> grid = {{1,3},
                                {2,2}};

    vector<int> ans = repeated_missing(grid);

    cout << ans[0] << endl;
    cout << ans[1] << endl;
}