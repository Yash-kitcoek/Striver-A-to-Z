#include<iostream>
#include<cmath>
using namespace std;

//brute force
// int nth_root(int n, int m) {
//     for(int i = 0; i <= m; i++) {
//         long power = (long) pow(i, n);

//         if(power == m) {
//             return i;
//         }

//         if(power > m) {
//             break;
//         }
//     }
//     return -1;
// }

// Optimal

int nth_root(int n, int m) {
    int low = 1;
    int high = m;

    while(low <= high) {
        int ans = 1;

        int mid = low + (high - low) / 2;

        for(int i = 0; i < n; i++) {
            ans *= mid;
            if(ans > m) {
                break;
            }
        }

        if(ans == m) {
            return mid;
        }

        if(ans < m) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    return -1;
}

int main()  {
    int n = 3, m = 27;

    cout << nth_root(n, m);
}