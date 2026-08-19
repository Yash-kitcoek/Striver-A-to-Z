#include<iostream>
#include<vector>
using namespace std;

bool search(vector<vector<int>> &nums, int target) {
    int n = nums.size();
    int m = nums[0].size();

    int low = 0;
    int high = n * m - 1;

    while(low <= high) {
        int mid = low + (high - low)/2;

        int row = mid / m;
        int col = mid % m;

        if(nums[row][col] == target) {
            return true;
        }else if(target > nums[row][col]) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> nums = {{1, 5, 9},{14, 20, 21},{30, 34, 43}};
    int target = 34;

    cout << search(nums, target);
}