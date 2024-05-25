// Problem: C - Count xxx
// Contest: AtCoder - Ｓｋｙ Inc, Programming Contest 2023（AtCoder Beginner Contest 329）
// URL: https://atcoder.jp/contests/abc329/tasks/abc329_c
// Memory Limit: 1024 MB
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

void solve() {
	
}

int charmap[127];

int main() {
//	int t; cin >> t; while (t--) solve();
	int tmp; stg a;
	cin >> tmp >> a;
	tmp = 1;
	int ans = 0;
	repq(i, 1, a.size()) {
		if (a[i] != a[i - 1]) {
			charmap[a[i - 1]] = max(charmap[a[i - 1]], tmp);
			tmp = 1;
			continue;
		}
		tmp++;
	}
	charmap[a[a.size() - 1]] = max(charmap[a[a.size() - 1]], tmp);
	// 最后一个不要忘记加上
	repq(i, 1, 126) {
		ans += charmap[i];
	}
	cout << ans;
	return 0;
}
