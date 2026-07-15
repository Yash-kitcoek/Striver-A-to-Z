#include<iostream>
#include<vector>
using namespace std;

int consecutive(vector<int> &nums) {
    int n = nums.size();

    int count = 0;
    int maxcount = 0;

    for(int num : nums) {
        if(num == 1) {
        count++;
        maxcount = max(maxcount, count);
        }else {
        count = 0;
       }
    }
    return maxcount;
}

int main() {
    vector<int> nums = {1,1,0,1,1,1};

    cout << consecutive(nums);
}