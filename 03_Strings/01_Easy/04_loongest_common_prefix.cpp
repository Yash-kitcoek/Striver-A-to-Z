#include<iostream>
#include<vector>
#include<string>
using namespace std;


string largest_common_perfix(vector<string> &strs) {
    int n = strs.size();

    string prefix = strs[0];

    for(int i = 1; i < n; i++) {
        int j = 0;

        while(j < prefix.size() && j < strs.size() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);

        if(prefix.empty()) {
            return "";
        }
    }
    return prefix;
}

int main() {
    vector<string> strs = {"flower", "flight", "flow"};

    cout << largest_common_perfix(strs);
}