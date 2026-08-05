#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subArray_with_sum_k(vector<int> &arr, int k) {
    unordered_map<int, int> prefixSum;
    int n = arr.size();

    int currSum = 0;
    int res = 0;

    for(int i=0; i<n; i++) {
        currSum += arr[i];

        if(currSum == k) {
            res++;
        }

        if(prefixSum.find(currSum - k) != prefixSum.end()) {
            res += prefixSum[currSum - k];
        }

        prefixSum[currSum]++;

        
    }

    

    return res;
}

int main() {
    vector<int> arr = {10 ,2 ,-2 ,-20 ,10};

    int k = -10;

   cout <<  subArray_with_sum_k(arr, k);

   return 0;

}