#include<iostream>
#include<vector>
using namespace std;

// Find floor value
int findFloor(vector<int> &nums, int x) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] <= x) {
            ans = nums[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

// Find ceil value
int findCeil(vector<int> &nums, int x) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] >= x) {
            ans = nums[mid];
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> findFloorCeil(vector<int> &nums, int x) {
    int f = findFloor(nums, x);
    int c = findCeil(nums, x);

    return {f, c};
}

int main() {
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 7;

    pair<int, int> ans = findFloorCeil(nums, x);

    cout << "Floor = " << ans.first << endl;
    cout << "Ceil = " << ans.second << endl;

    return 0;
}