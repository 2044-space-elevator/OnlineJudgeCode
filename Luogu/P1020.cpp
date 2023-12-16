// Problem: P1020 [NOIP1999 普及组] 导弹拦截
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1020
// Memory Limit: 128 MB
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

vector<int> arr, dp;

void calf() {
	for (int v : arr) {
		vector<int>::iterator it;
		it = lower_bound(dp.begin(), dp.end(), v);
		if (it == dp.end()) {
			dp.push_back(v);
		} else {
			*it = v;
		}
	}
}

int ans = 0;int n;

int binary(vector<int> vct, int x) {
	int l = 0, r = vct.size() - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (x > vct[mid]) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

void cals() {
	dp.push_back(arr.front());
	repq(i, 1, arr.size()) {
		int v = arr[i];
		int it;
		// cout << binary(dp, v) << endl;
		if (v <= dp.back()) {
			dp.push_back(v);
		} else {
			// cout << *it << ' ' << dp.size() << endl;
			it = binary(dp, v);
			dp[it] = v;
		}
	}
}

int main() {
//	int t; cin >> t; while (t--) solve();
	int x;
	while (cin >> x) {
		arr.push_back(x);
	}
	n = arr.size();
	calf();
	int ans2 = dp.size();
	dp.clear();
	cals(); 
	ans = dp.size();
	cout << ans<< endl << ans2 << endl;
	return 0;
}
