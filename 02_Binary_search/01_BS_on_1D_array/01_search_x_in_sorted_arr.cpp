#include<iostream>
#include<vector>
using namespace std;

bool binary_search(vector<int> &arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high)/2;

        if(arr[mid] == target) {
            return true;
        }else if(target > arr[mid]) {
            low = mid+1;
        }else {
            high = mid-1;
        }
    }
    return false;
    
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;

    cout << binary_search(arr, target);
}