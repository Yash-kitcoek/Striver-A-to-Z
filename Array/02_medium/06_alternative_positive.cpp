// Leetcode 2149

#include<iostream>
#include<vector>
using namespace std;


vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();
    int pos = 0;
    int neg = 1;
    vector<int> ans(n);
    
    for(int x : nums) {
        if(x > 0) {
            ans[pos] = x;
            pos += 2;
        }
        else {
            ans[neg] = x;
            neg += 2;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {3,1,-2,-5,2,-4};

    vector<int> newArray = rearrangeArray(nums);


    for(int val : newArray) {
        cout << val << " ";
    }


    return 0;
}