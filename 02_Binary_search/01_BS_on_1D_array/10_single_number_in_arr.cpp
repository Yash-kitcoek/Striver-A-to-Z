#include<iostream>
#include<vector>
using namespace std;

//Brute force - O(n)
// int single_number(vector<int> &nums) {
//     int n = nums.size();

//     int ans = 0;

//     for(int val : nums) {
//         ans ^= val;
//     }

//     return ans;
// }

// Optimal

int single_number(vector<int> &nums) {
    int n = nums.size();

    int low = 0;
    int high = n - 1;

    while(low < high) {
        int mid = low + (high - low ) / 2;

        if(mid % 2 ==  1) {
            mid--;
        }

        if(nums[mid] == nums[mid + 1]) {
            low = mid + 2;
        }else {
            high = mid;
        }
    }
    return nums[low];
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};

    cout << single_number(nums);
}