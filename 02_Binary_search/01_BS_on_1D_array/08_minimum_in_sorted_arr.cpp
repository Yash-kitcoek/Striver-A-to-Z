#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

//Brute force
// int minimum_ele(vector<int> &nums) {
//     int n = nums.size();

//     int MinVal = INT_MAX;

//     for(int i = 0; i<n; i++) {

//         MinVal = min(MinVal, nums[i]);
//     }

//     return MinVal;
// }

// Optimal

int minimum_ele(vector<int> &nums) {
    int n = nums.size();

    int start = 0;
    int end = n-1;

    while(start < end) {
        int mid = start + (end - start) / 2;

        if(nums[mid] > nums[end]) {
            start = mid + 1;
        }else {
            end = mid;
        }
        
    }
    return nums[end];
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2,3};

    cout << minimum_ele(nums);
}