#include<iostream>
#include<vector>
using namespace std;

int largest(vector<int> &arr) {
    int max = arr[0];
    int n = arr.size();

    for(int i=0; i<n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    vector<int> arr = {10,20,30};

   cout <<  largest(arr);

}