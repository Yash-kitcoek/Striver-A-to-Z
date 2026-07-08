#include<iostream>
#include<vector>
using namespace std;


// TC - O(N^2)
// bool isSorted(vector<int> &arr, int n) {
//     for(int i=0; i<n; i++) {
//         for(int j=i+1; j<n; j++) {
//             if(arr[j] < arr[i]) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

bool isSorted(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) {
        if(arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();

    cout << isSorted(arr, n);
}