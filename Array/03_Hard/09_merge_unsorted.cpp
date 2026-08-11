#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge_if_not_sort(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();

    int left = n-1;
    int right = 0;

    while(left >= 0 && right < m) {
        if(nums1[left] > nums2[right]) {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }else {
            break;
        }
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    for(int val : nums1) {
        cout << val << " ";
    }
    cout << endl;   

    for(int val1 : nums2) {
        cout << val1 << " ";
    }

}

int main() {
    vector<int> nums1 = {2, 4, 7, 10};
    vector<int> nums2 = {2, 3};

    merge_if_not_sort(nums1, nums2);
}