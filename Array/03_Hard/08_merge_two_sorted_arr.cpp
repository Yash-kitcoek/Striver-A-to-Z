#include<iostream>
#include<vector>
using namespace std;

void merge_if_sorted(vector<int> &nums1,int n, vector<int> &nums2, int m) {
    int i = n-1;
    int j = m-1;
    int k = n + m - 1;

    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        }else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while(j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    for(int val : nums1) {
        cout << val << " ";
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {4,5,6};

    int n = 3;
    int m = 3;

    merge_if_sorted(nums1, n,nums2, m);
}