#include<iostream>
#include<vector>
#include<string>
using namespace std;

int substring_count(string &s) {
    int n = s.size();
    
    vector<int> freq(3, 0);

    int l = 0, ans = 0;

    for(int r = 0; r < n; r++) {
        freq[s[r] - 'a']++;

        while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
            ans += (s.size() - r);

            freq[s[l] - 'a']--;
            l++;
        }
    }


    return ans;
}

int main() {
    string s = "abcabc";

    cout << substring_count(s);
}