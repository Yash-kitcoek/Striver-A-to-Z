#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leaders(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans;

    int maxi = nums[n-1];
    ans.push_back(maxi);

    for(int i = n-2; i >= 0; i--) {
        if(nums[i] > maxi) {
            ans.push_back(nums[i]);
            maxi = nums[i];
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums = {16, 17, 4, 3, 5, 2};

   vector<int> result =  leaders(nums);

   for(int val : result) {
    cout << val << " ";
   }
}