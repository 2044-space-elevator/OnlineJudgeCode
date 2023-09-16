#include <iostream>
#define int long long
using namespace std;

int V,n,arr[1005];
int dp[(int)1e5] = {1};
signed main() {
    cin >> V >> n;
    for (int i = 1; i <= V; i++) {
        cin >> arr[i];
    }   
    for (int i = 1; i <= V; i++) {
        for (int j = arr[i]; j <= n; j++) {
            dp[j] += dp[j - arr[i]];
        }
    }
    cout << dp[n];
}