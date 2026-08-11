#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// brute force
// int subArray_with_xor(vector<int> &nums, int k) {
//     int n = nums.size();
//     long count = 0;

//     for(int i=0; i<n; i++) {
//         int xr = 0;

//         for(int j=i; j<n; j++) {
//             xr ^= nums[j];

//             if(xr == k) {
//                 count++;
//             }
//         }
//     }

//     return count;
// }

// Optimal

int subArray_with_xor(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    long count = 0;

    int xr = 0;

    mp[0] = 1;

    for(int i=0; i<n; i++) {
        xr ^= nums[i];

        int required = xr ^ k;


        count += mp[required];


        mp[xr]++;

    }
    return count;

}


int main() {
    vector<int> nums = {4,2,2,6,4};

    int k = 6;

   cout <<  subArray_with_xor(nums, k);
}