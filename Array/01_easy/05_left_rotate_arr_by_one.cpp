#include<iostream>
#include<vector>
using namespace std;

void rotate_by_one(vector<int> &arr) {
    int n = arr.size();

    int last = arr[n-1];

    for(int i = n-1; i > 0; i--) {
        arr[i] = arr[i-1];
    }

    arr[0] = last;

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

}

int main() {

    vector<int> arr = {1,2,3,4,5};

    rotate_by_one(arr);
}