#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int numberOfPermutations(int n, vector<vector<int>>& requirements) {

    vector<int> need(n, -1);

    for(auto &r : requirements) {
        need[r[0]] = r[1];
    }

    int MAXINV = 400;

    vector<vector<int>> dp(n + 1,
                           vector<int>(MAXINV + 1, 0));

    dp[0][0] = 1;

    for(int len = 1; len <= n; len++) {

        for(int inv = 0; inv <= MAXINV; inv++) {

            long long ways = 0;

            for(int add = 0;
                add <= min(inv, len - 1);
                add++) {

                ways += dp[len - 1][inv - add];
            }

            dp[len][inv] = ways % MOD;
        }

        if(need[len - 1] != -1) {

            int req = need[len - 1];

            for(int inv = 0; inv <= MAXINV; inv++) {

                if(inv != req) {
                    dp[len][inv] = 0;
                }
            }
        }
    }

    long long ans = 0;

    for(int inv = 0; inv <= MAXINV; inv++) {
        ans = (ans + dp[n][inv]) % MOD;
    }

    return ans;
}

int main() {

    int n = 3;

    vector<vector<int>> requirements = {
        {2, 2}
    };

    cout << numberOfPermutations(n, requirements) << endl;

    return 0;
}