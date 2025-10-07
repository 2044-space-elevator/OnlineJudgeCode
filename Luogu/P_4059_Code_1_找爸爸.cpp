#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define rep(v,b,e) for(int v=b;v<=e;v++)
#define repq(v,b,e) for(int v=b;v<e;v++)
#define rrep(v,e,b) for(int v=b;v>=e;v--)
#define rrepq(v,e,b) for(int v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}

int arr[3005], brr[3005];
ll dp[3005][3005][3];
int dy[5][5];
// 0: 不加
// 1: A
// 2: B

main() {
//	int t; cin >> t; while (t--) solve();
    stg a, b;
    cin >> a >> b;
    repq(i, 0, a.size()) {
        if (a[i] == 'A')    arr[i + 1] = 1;
        if (a[i] == 'T')    arr[i + 1] = 2;
        if (a[i] == 'G')    arr[i + 1] = 3;
        if (a[i] == 'C')    arr[i + 1] = 4;
    }
    repq(i, 0, b.size()) {
        if (b[i] == 'A')    brr[i + 1] = 1;
        if (b[i] == 'T')    brr[i + 1] = 2;
        if (b[i] == 'G')    brr[i + 1] = 3;
        if (b[i] == 'C')    brr[i + 1] = 4;
    }
    rep(i, 1, 4) {
        rep(j, 1, 4) {
            cin >> dy[i][j];
        }
    }
    memset(dp, 128, sizeof dp);
    int A, B;
    cin >> A >> B;
    int n = a.size(), m = b.size();
    dp[0][0][0] = 0;
    dp[0][0][1] = dp[0][0][2] = -A;
    rep(i, 0, n) {
        rep(j, 0, m) {
        if (i > 0 && j > 0)
          dp[i][j][0] = max({dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]}) + dy[arr[i]][brr[j]];
        if (j > 0)
          dp[i][j][1] = max({dp[i][j - 1][1] - B, dp[i][j - 1][0] - A, dp[i][j - 1][2] - A});
        if (i > 0)
          dp[i][j][2] = max({dp[i - 1][j][1] - A, dp[i - 1][j][2] - B, dp[i - 1][j][0] - A});
        }
    }
    cout << max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
	return 0;
}
