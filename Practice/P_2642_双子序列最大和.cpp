#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[1145140], dp2[1145140];
int arr[1145140];

signed main() {
    int n;
    cin >> n;
    memset(dp, -127, sizeof(dp));
    memset(dp2, -127, sizeof(dp2));
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i]);
    }
    for (int i = n; i; i--) {
        dp2[i] = max(dp2[i + 1] + arr[i], arr[i]);
    }
    int ans = -1145141919;
    for (int i = 2; i < n; i++) {
        ans = max(ans, dp[i - 1] + dp2[i + 1]);
    }
    cout << ans;
}
