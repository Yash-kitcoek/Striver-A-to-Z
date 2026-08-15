#include<iostream>
#include<vector>
using namespace std;

int rotation_count_in_rotated_arr(vector<int> &nums) {
    int n = nums.size();

    int low = 0;
    int high = n-1;

    while(low < high) {
        int mid = low + (high - low)/2;

        if(nums[mid] > nums[high]) {
            low = mid + 1;
        }else {
            high = mid;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {15, 18, 2, 3, 6, 12};

    cout << rotation_count_in_rotated_arr(nums);
}