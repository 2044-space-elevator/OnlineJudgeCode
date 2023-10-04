// Writen by 2044_space_elevator
#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mod = 1e9 + 9;
    int ans = 1;
    int exp = n - 1;
    while (exp) {
        if (exp & 1) {
            ans *= n;
            ans %= mod;
        }
        n *= n;
        n %= mod;
        exp >>= 1;
    } 
    cout << ans << endl;
    // For many test cases
    
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}