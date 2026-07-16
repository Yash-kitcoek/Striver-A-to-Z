#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> two_sum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;

    for(int i=0; i<nums.size(); i++) {
        int complement = target - nums[i];

        if(mp.count(complement)){
            return {mp[complement], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

   vector<int> ans =  two_sum(nums, target);

   for(int val : ans) {
    cout << val << " ";
   }

    
}