#include <iostream>
#include <cstring>
using namespace std;

int dp[105][105][105];
int n, m, d;
int arr[105];

int main() {
    memset(dp, -127, sizeof(dp));
    dp[0][0][0] = 0;
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < d; k++) {
                dp[i][j][k] = max(dp[i - 1][j][k], (j) ? dp[i - 1][j - 1][((k - arr[i]) % d + d) % d] + arr[i] : dp[104][104][0]);
            }
        }
    }
    cout << (dp[n][m][0] < 0 ? -1 : dp[n][m][0]) << endl;
}