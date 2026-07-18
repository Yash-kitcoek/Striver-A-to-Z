#include<iostream>
#include<vector>
using namespace std;

int majority_element(vector<int> &nums) {
    int n = nums.size();

    int element = 0;
    int count = 0;
    

    for(int i=0; i<n; i++) {
        if(count == 0) {
            element = nums[i];
        }

        if(nums[i] == element) {
            count++;
        }else {
            count--;
        }
    }
    return element;
}

int main() {
    vector<int> nums = {1,2,1,1,2,22,2,3};

   cout << majority_element(nums);
}