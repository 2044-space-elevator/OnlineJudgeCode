// Problem: Perfect Square
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1881C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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


char _map[(int)1e3 + 5][(int)1e3 + 5];
void solve() {
	int n;
	cin >> n;
	rep(i, 1, n) {
		rep(j, 1, n) {
			cin >> (_map[i][j] -= 'a');
		}
	}
	int res = 0;
	rep(i, 1, n >> 1) {
		rep(j, 1, n >> 1) {
			// m[i][j] 的旋转 90 度在 m[j][n - i + 1]
			// 180 度在 m[n - i + 1][j]
			// 270 度在 m[n - j + 1][i]
			initializer_list<int> tmp = {
				_map[i][j],
				_map[n - j + 1][i],
				_map[j][n - i + 1],
				_map[n - i + 1][n - j + 1]
			};
			res += max(tmp) * 4 - (accumulate(tmp.begin(), tmp.end(), 0));
		}
	}
	cout << res << endl;
}


int main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
