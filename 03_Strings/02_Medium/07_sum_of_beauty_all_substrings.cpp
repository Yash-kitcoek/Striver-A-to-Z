#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int beauty_of_substring(string s) {
    int n = s.size();
    int totalBeauty = 0;

    for(int i = 0; i < n; i++) {
        vector<int> freq(26, 0);

        for(int j = i; j <n; j++) {
            freq[s[j] - 'a']++;

            int maxFreq = 0, minFreq = INT_MAX;

            for(int k = 0; k < 26; k++) {
                if(freq[k] > 0) {
                    maxFreq = max(maxFreq, freq[k]);
                    minFreq = min(minFreq, freq[k]);
                }
            }
            totalBeauty += (maxFreq - minFreq);
        }
    }
    return totalBeauty;
}

int main() {
    string s = "aabcbaa";

    cout << beauty_of_substring(s);
}