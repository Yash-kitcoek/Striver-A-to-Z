#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force
// vector<vector<int>> three_sum(vector<int> &nums) {
//     int n = nums.size();
//     vector<vector<int>> res;

//     for(int i=0; i<n; i++) {
//         for(int j = i+1; j<n; j++) {
//             for(int k = j+1; k < n; k++) {
//                 if(nums[i] + nums[j] + nums[k] == 0) {
//                     res.push_back({nums[i], nums[j], nums[k]});
//                 }
//             }
//         }
//     }
//     return res;
// }

// optimal approach
vector<vector<int>> three_sum(vector<int> &nums) {
    int n = nums.size();

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++) {
        int left = i+1;
        int right = n - 1;

        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum < 0) {
                left++;
            }else if(sum > 0) {
                right--;
            }
            else {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while(left < right &&  nums[left] == nums[left-1]) {
                    left++;
                }
                while(left < right && nums[right] == nums[right+1]) {
                    right--;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {0, -1, 2, -3, 1};

    vector<vector<int>> ans = three_sum(nums);

    for(auto it : ans) {
        for(int val : it) {
            cout << val << " ";
        }
        cout << endl;
    }

    

    return 0;
}