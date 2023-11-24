// Problem: P2701 [USACO5.3] 巨大的牛棚Big Barn
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2701
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Coding by 2044_space_elevator

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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool arr[1005][1005];
int dp[1005][1005];

void solve() {
	
}


int main() {
//	int t; cin >> t; while (t--) solve();
	int n, T;
	cin >> n >> T;
	rep(i, 1, T) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}
	int ans = 0;
	rep(i, 1, n) {
		rep(j, 1, n) {
			if (arr[i][j] == 0) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}
