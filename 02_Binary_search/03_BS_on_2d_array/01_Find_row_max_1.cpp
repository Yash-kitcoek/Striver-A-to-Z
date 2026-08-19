#include<iostream> 
#include<vector> 
using namespace std; 
 
vector<int> maximum_1(vector<vector<int>> &nums) { 
    int n = nums.size(); 
    int m = nums[0].size(); 
 
    int index = -1;   
    int maxCount = 0; 
 
    for(int i = 0; i < n; i++) { 
        int count = 0; 

        for(int j = 0; j < m; j++) { 
            count += nums[i][j]; 
        } 
 
        if(count > maxCount) { 
            maxCount = count; 
            index = i; 
        } 
    } 

    return {index, maxCount}; 
} 
 
int main(){ 
    vector<vector<int>> nums = {{1,1,1},{0,0,1},{0,0,0}}; 
 
    vector<int> ans = maximum_1(nums); 
 
    cout << "Row: " << ans[0] << ", MaxCount: " << ans[1] << endl; 
}