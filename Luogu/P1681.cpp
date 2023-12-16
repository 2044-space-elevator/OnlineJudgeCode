// Problem: P1681 最大正方形II
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1681
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

void solve() {
	
}

int n, m, arr[1505][1505], dp[1505][1505];

int main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m;
	rep(i, 1, n) {
		rep(j, 1, m) {
			cin >> arr[i][j];
		}
	}
	int ans = 1;
	rep(i, 1, n) {
		rep(j, 1, m) {
			if (arr[i][j] != arr[i - 1][j] && arr[i][j] != arr[i][j - 1]) {
				dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans + 1;
	return 0;
}
