#include<iostream>
#include<vector>
using namespace std;

void move_zero(vector<int> &nums, int n) {
    int j = 0;

    for(int i=0; i<n; i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }

    for(int i=0; i<n; i++) {
        cout << nums[i] << " ";
    }
}

int main() {
    vector<int> nums = {0,1,0,3,12};
    int n = nums.size();

    move_zero(nums, n);

}