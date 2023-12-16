// Problem: P1439 【模板】最长公共子序列
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1439
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

int n, arr[114514];
map<int,int> mapA;
vector<int> dp;
vector<int>::iterator it;

int main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n;
	rep(i, 1, n) {
		int x;
		cin >> x;
		mapA[x] = i;
	}
	rep(i, 1, n) {
		int x;
		cin >> x; 
		arr[i] = mapA[x];
	}
	int ans = 0;
	rep(i, 1, n) {
		it = lower_bound(dp.begin(), dp.end(), arr[i]);
		if (it == dp.end()) {
			dp.push_back(arr[i]);
		} else {
			*it = arr[i];
		}
	}
	cout << dp.size() << endl;
	return 0;
}
