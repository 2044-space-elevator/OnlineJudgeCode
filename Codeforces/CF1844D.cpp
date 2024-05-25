// Problem: Row Major
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1844D
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


void solve() {
	int n;
	cin >> n;
	int minD = 1;
	for (; !(n % minD); minD++);
	rep(i, 1, n) {
		cout << char((i % minD) + 98);
	} 
	cout << endl;
}


int main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
