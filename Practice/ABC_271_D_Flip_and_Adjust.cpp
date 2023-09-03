#include <iostream>
using namespace std;

int arr[105], brr[105], dp[105][(int)1e6][2];
char ans[1005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> brr[i];
    }
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = arr[i]; j <= m; j++) {
            dp[i][j][0] |= dp[i - 1][j - arr[i]][1] || dp[i - 1][j - arr[i]][0]; 
        }
        for (int j = brr[i]; j <= m; j++) {
            dp[i][j][1] |= dp[i - 1][j - brr[i]][1] || dp[i - 1][j - brr[i]][0];
        }
    }
    cout << (dp[n][m][0] || dp[n][m][1] ? "Yes\n" : ("No\n"));
    if (dp[n][m][0] || dp[n][m][1]) {
        for (int i = n; i; i--) {
            if (!dp[i][m][0]) {
                m -= brr[i];
                ans[i] = 'T';
            } else if (dp[i][m][0]) {
                m -= arr[i];
                ans[i] = 'H';
            }
        }
#define rep for(int i=1;i<=n;i++)
    rep {
        cout << ans[i];
    }
    cout << endl;
    }
}