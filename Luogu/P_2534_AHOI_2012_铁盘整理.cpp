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
int n, arr[20], tmp[20], limit;

int hhx() {
	int cnt = 0;
	rep(i, 1, n) cnt += abs(arr[i + 1] - arr[i]) != 1;
	return cnt;
}

void dfs(int x, int hx, int depth) {
	if (depth == limit) {
		if (!hhx()) {
			cout << depth;
			exit(0);
		} 
		return;
	}
	rep(i, 2, n) {
		if (i == x) continue;
		if (abs(arr[i + 1] - arr[i]) == 1) continue;
		int tmp = hx;
		reverse(arr + 1, arr + i + 1);
		tmp -= abs(arr[i] - arr[i + 1]) == 1;
		if (tmp + depth <= limit)
		dfs(i, tmp, depth + 1);
		reverse(arr + 1, arr + i + 1);
	}
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i];
		tmp[i] = arr[i];
	}
	arr[n + 1] = n + 1;
	sort(tmp + 1, tmp + n + 1);
	int k = unique(tmp + 1, tmp + n + 1) - (tmp + 1);
	rep(i, 1, n) {
		arr[i] = lower_bound(tmp + 1, tmp + k + 1, arr[i]) - (tmp);
	}
	int eva = hhx();
	for (; ; limit++) {
		dfs(1, hhx(), 0);
	}
	return 0;
}
