#include<iostream>
#include<vector>
using namespace std;

vector<int> merger_array(vector<int> &arr1, vector<int> &arr2) {
    int i = 0, j = 0;
    vector<int> ans;

    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            if(ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;

        }else if(arr1[i] > arr2[j]) {
            if(ans.empty() || ans.back() != arr2[j]) {
                ans.push_back(arr2[j]);
            }
            j++;
        }else {
            if(ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while(i < arr1.size()) {
        ans.push_back(arr1[i]);

        i++;
    }

    while(j < arr2.size()) {
        ans.push_back(arr2[j]);

        j++;
    }

    return ans;
}

int main() {
    vector<int> arr1 = {1,2,2,3,4,4};
    vector<int> arr2 = {5,6,6,7,8,8};

    vector<int> ans = merger_array(arr1, arr2);

    for(int x : ans) {
        cout << x  << " ";
    }


    return 0;
}