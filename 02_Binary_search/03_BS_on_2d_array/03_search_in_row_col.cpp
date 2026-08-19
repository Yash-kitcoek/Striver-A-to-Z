#include<iostream>
#include<vector>
using namespace std;

int search(vector<vector<int>> &nums, int target) {
    int n = nums.size();
    int m = nums[0].size();

    int row = 0, col = m-1;

    while(row < n && col >= 0) {
        if(nums[row][col] == target) {
            return true;
        }else if(nums[row][col] > target) {
            col--;
        }else {
            row++;
        }
    }
    return false;

}

int main() {
    vector<vector<int>> nums = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}};

    int target = 12;

    cout << search(nums, target);
}