#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void getElements(vector<int> &arr, int n) {
    int small = INT_MAX,  second_small = INT_MAX;
    int large = INT_MIN,  second_large = INT_MIN;

    for(int i=0; i<n; i++) {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }

    for(int i= 0; i<n; i++) {
        if(arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }

        if(arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }

    cout << "Second Large : " << second_large << endl;
    cout << "second Small : " << second_small << endl;
}

using namespace std;

int main() {
    vector<int> arr = {10,20,30,40,50};

    int n = arr.size();

    getElements(arr, n);
}