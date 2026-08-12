#include<iostream>
#include<vector>
using namespace std;

//Brute force
// int lower_bound(vector<int> &arr, int target) {
//     int n = arr.size();

//     for(int i=0; i<n; i++) {
//         if(arr[i] >= target) {
//             return i;
//         }
//     }
//     return n;
    
// }

// Optimal
int lower_bound(vector<int> &arr, int target) {
    int n = arr.size();


    int left = 0;
    int right = n-1;
    int ans = n;

    while(left <= right) {
        int mid = (left + right)/2;
        
        if(arr[mid] >= target) {
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};
    int target = 9;

    cout << lower_bound(arr, target);

    return 0;
}