#include<iostream>
#include<vector>
using namespace std;

// Brute Force
// int count_Occurance(vector<int> &nums, int x) {
//     int n = nums.size();
//     int freq = 0;

//     for(int i=0; i<n; i++) {
//         if(nums[i] == x) {
//             freq++;
//         }
//     }
//     return freq;
// }

int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k) {
            first = mid;
            high = mid - 1; // search on left side
        }
        else if (arr[mid] < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k) {
            last = mid;
            low = mid + 1; // search on right side
        }
        else if (arr[mid] < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);

    if (first == -1) {
        return {-1, -1};
    }

    int last = lastOccurrence(arr, n, k);

    return {first, last};
}

int countOccurrence(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);

    if (ans.first == -1) {
        return 0;
    }

    return ans.second - ans.first + 1;
}

int main() {
    vector<int> nums = {2, 2, 3, 3, 3, 3, 4};
    int x = 3;

    cout << "Count of " << x << " = "
         << countOccurrence(nums, nums.size(), x);

    return 0;
}