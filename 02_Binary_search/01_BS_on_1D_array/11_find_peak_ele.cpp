#include<iostream>
#include<vector>
using namespace std;

int peak_ele(vector<int> &nums) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] > nums[mid + 1]) {
            high = mid;
        }else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {4,5,8,7,1,2};

    cout << peak_ele(nums);
}