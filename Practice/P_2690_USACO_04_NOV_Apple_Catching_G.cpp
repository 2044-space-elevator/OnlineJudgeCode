#include <iostream>
using namespace std;

int dp[1005][35], t, w, arr[1005];
int main() {
    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        cin >> arr[i];
    }


    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= min(t, w); j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
            if (arr[i] - 1 == j % 2) {
                dp[i][j] += 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w; i++) {
        // cout << dp[t][i] << ' ';
        ans = max(ans, dp[t][i]);
    }
    cout << ans;
}