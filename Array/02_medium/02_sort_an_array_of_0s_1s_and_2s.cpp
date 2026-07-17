#include<iostream>
#include<vector>
using namespace std;

void sort_zero_one_twos(vector<int> &nums) {
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low++, mid++;
        }else if(nums[mid] == 1) {
            mid++;
        }else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2,0,2,1,1,0};

    sort_zero_one_twos(nums);

    for(int val : nums) {
        cout << val << " ";
    }

  return 0;
}