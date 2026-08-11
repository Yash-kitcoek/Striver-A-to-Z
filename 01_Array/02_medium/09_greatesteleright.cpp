#include<iostream>
#include<vector>
using namespace std;


vector<int> greatestElerightSide(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);

    int maxi = -1;

    for(int i=n-1; i>=0; i--) {
        ans[i] = maxi;
        maxi = max(maxi, nums[i]);
    }
    return ans;
}

int main() {

    vector<int> arr = {17,18,5,4,6,1};

   vector<int> ele = greatestElerightSide(arr);

   for(int val : ele) {
    cout << val << " ";
   }
}