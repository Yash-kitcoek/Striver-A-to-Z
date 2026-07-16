#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longest_subarray_sum(vector<int> &nums, int k ) {
    unordered_map<long long, int> mp;
    int sum = 0;
    int maxlen = 0;

    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];

        if(sum == k) {
            maxlen =  i + 1;
        }

        if(mp.find(sum-k) != mp.end()) {
            maxlen = max(maxlen, i-mp[sum - k]);
        }

        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    return maxlen;
}

int main() {
    vector<int> nums = {10, 5, 2, 7, 1, -10};

    int k = 15;

   cout <<   longest_subarray_sum(nums, k);

   return 0;
}