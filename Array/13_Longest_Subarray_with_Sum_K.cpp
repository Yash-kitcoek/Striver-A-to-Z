// for positive array

#include<iostream>
#include<vector>
using namespace std;

int longest_subarr_with_k(vector<int> &nums, int k) {
    int left = 0;
    int sum = 0;
    int maxlen = 0;

    for(int right = 0; right < nums.size(); right++) {
        sum += nums[right]; 

        while(sum > k) {
            sum -= nums[left];
            left++;
        }

        if(sum == k) {
            maxlen = max(maxlen, right - left + 1);
        }
    }
    return maxlen;
}

int main() {
    vector<int> nums = {1,2,1,1,1,1,1};
    int k = 4;

    cout << longest_subarr_with_k(nums, k);
}