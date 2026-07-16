#include<iostream>
#include<vector>
using namespace std;

int linear_search(vector<int> &nums, int target){
    int n = nums.size();

    for(int i=0; i<n; i++) {
        if(nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {10,20,30,40,50};
    int target = 40;

    cout << linear_search(nums, target);

    return 0;
}