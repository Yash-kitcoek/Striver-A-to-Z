#include<iostream>
#include<vector>
using namespace std;

//brute force;
// vector<int> majority_element2(vector<int> &nums) {
//     int n = nums.size();

//     vector<int> res;

//     for(int i=0; i<n; i++) {
//         int count = 0;

//         for(int j=i; j<n; j++) {
//             if(nums[j] == nums[i]) {
//                 count++;
//             }
//         }

//         if(count > n/3) {

//             if(res.size() == 0 ||  nums[i] != res[0]) {
//                 res.push_back(nums[i]);
//             }

//             if(res.size() == 2) {
//                 if(res[0] > res[1]) {
//                     swap(res[0], res[1]);
//                 }
//             }
//         }
//     }
//     return res;
// }

// Optimal Approach
vector<int> majority_element2(vector<int> &nums) {
    int n = nums.size();

    int ele1 = 1, ele2 = 1;
    int cnt1 = 0, cnt2 = 0;

    for(int num : nums) {
        if(num == ele1) {
            cnt1++;
        }
        else if(num == ele2) {
            cnt2++;
        }
        else if(cnt1 == 0) {
            ele1 = num;
            cnt1 = 1;
        }
        else if(cnt2 == 0) {
            ele2 = num;
            cnt2 = 1;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    for(int num : nums) {
        if(num == ele1)cnt1++;
        else if(num == ele2)cnt2++;
    }

        vector<int> ans;

        if(cnt1 > n/3) ans.push_back(ele1);
        if(cnt2 > n/3) ans.push_back(ele2);
    
        return ans;
}


int main() {
    vector<int> nums = {2, 2, 3, 1, 3, 2, 1, 1};

    vector<int> ans = majority_element2(nums);

    for(int val : ans) {
        cout << val << " ";
    }

    return 0;
}