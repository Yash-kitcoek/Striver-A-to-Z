#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//brute force
// int maxlength_of_subarr(vector<int> &nums) {
//     int n = nums.size();
//     int maxlen = 0;

//     for(int i=0; i<n; i++) {
//         int currSum = 0;

//         for(int j=i; j<n; j++) {
//             currSum += nums[j];

//             if(currSum == 0) {
//             maxlen = max(maxlen, j-i+1);
//             }
//         }
//     }
//     return maxlen;
// }

//Optimal

int maxlength_of_subarr(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int maxlen = 0;
    int prefixSum = 0;

    for(int i=0; i<n; i++) {
        prefixSum += nums[i];

        if(prefixSum == 0) {
            maxlen = i+1;
        }

        if(mp.find(prefixSum) != mp.end()) {
            maxlen = max(maxlen, i-mp[prefixSum]);
        }else {
            mp[prefixSum] = i;
        }

    }
    return maxlen;
}

int main() {
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10};

    cout << maxlength_of_subarr(nums);
}