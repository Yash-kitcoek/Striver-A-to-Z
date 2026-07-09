#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int remove_duplicates(vector<int> &nums) {
    unordered_set<int> seen;

    int index = 0;

    for(int num : nums) {
        if(seen.find(num) == seen.end()) {
            seen.insert(num);

            nums[index] = num;

            index++;
        }
    }
    return index;
}


int main() {
    vector<int> nums = {0,0,1,1,4,4,5,5};

    int k = remove_duplicates(nums);

    cout << k << endl;

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
}