// Problem: D. Divide and Equalize
// Contest: Codeforces - Codeforces Round 903 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1881/D
// Memory Limit: 256 MB
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
	map<int, int> primeMap;
	int n;
	cin >> n;
	rep(i, 1, n) {
		int x;
		cin >> x;
		rep(i, 2, sqrt(x)) {
			while (x % i == 0) {
				primeMap[i]++;
				x /= i;
			}
		}
		primeMap[x] += x > 1;
	}
	for (auto [trash, useful] : primeMap) {
		if (useful % n) {
			RTN
			return;
		}
	}
	RTY
	return;
}


int main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
