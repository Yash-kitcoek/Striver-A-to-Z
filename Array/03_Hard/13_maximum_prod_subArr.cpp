#include<iostream>
#include<vector>
using namespace std;

//Brute Approach
// int max_prod_subArr(vector<int> &nums) {
//     int n = nums.size();

//     int maxProd = nums[0];

//     for(int i=0; i<n; i++) {
//         int prod = 1;

//         for(int j=i; j<n; j++) {
//             prod *= nums[j];
    
//             maxProd = max(maxProd, prod);
//         }    
//     }
//     return maxProd;
// }

//Optimal Approach
int max_prod_subArr(vector<int>& nums) {

    int maxProd = nums[0];

    int currMax = nums[0];
    int currMin = nums[0];

    for(int i = 1; i < nums.size(); i++) {

        if(nums[i] < 0) {
            swap(currMax, currMin);
        }

        currMax = max(nums[i],
                      currMax * nums[i]);

        currMin = min(nums[i],
                      currMin * nums[i]);

        maxProd = max(maxProd, currMax);
    }

    return maxProd;
}

int main() {
    vector<int> nums = {1,2,3,4,5,0};

    cout << max_prod_subArr(nums);
}