#include<iostream>
#include<vector>
using namespace std;

int missing_number(vector<int> &nums) {
    int n = nums.size();
    
    int xor1 = 0;
    int xor2 = 0;

    for(int i=0; i<=n; i++) {
        xor1 ^= i;
    }

    for(int num : nums) {
        xor2 ^= num;
    }

    return xor1 ^ xor2;
}

int main() {
    vector<int> nums = {0,1,2,3,5};

    cout << missing_number(nums);
}