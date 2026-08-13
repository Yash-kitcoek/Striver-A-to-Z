#include<iostream>
#include<vector>
using namespace std;

// brute force
// int last_occurance(vector<int> &nums, int key) {
//     int n = nums.size();

//     for(int i=n-1; i >=0; i--) {
//         if(nums[i] == key) {
//             return i;
//         }
//     }
//     return -1;

// }

//OPtimal
int last_occurance(vector<int> &nums, int key) {
    int n = nums.size();

    int res = -1;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] == key) {
            res = mid;
            low = mid + 1;
        }else if(key < nums[mid]) {
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {3, 4, 13, 13, 13, 20, 40};
    int key = 13;

    cout << last_occurance(nums, key);
}