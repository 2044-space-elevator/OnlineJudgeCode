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

int n, arr[(int)1e5 + 5], STmax[(int)1e5 + 5][32], STmin[(int)1e5 + 5][32], tmp[(int)1e5 + 5];
stack<int> st;

int STmaxSearch(int l, int r) {
  int k = log2(r - l + 1);
	int ll = STmax[l][k], rr = STmax[r - (1 << k) + 1][k];
	if (arr[ll] > arr[rr]) return ll;
	else return rr;
}
int STminSearch(int l, int r) {
  int k = log2(r - l + 1);
  return min(STmin[l][k], STmin[r - (1 << k) + 1][k]);
}
bool check(int i, int j) {
    if (arr[i] == STminSearch(i, j) && arr[j] == STmaxSearch(i, j)
    && arr[i] != STminSearch(i + 1, j) && arr[j] != STmaxSearch(i, j - 1)) {
      return 1;
    }
    return 0;
}
main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, n) STmax[i][0] = STmin[i][0] = i;  
	rrep(i, 1, n + 1) {
		while (st.size() && arr[i] < arr[st.top()]) st.pop();
		if (st.size()) tmp[i] = st.top();
		if (st.size() && arr[i] <= arr[st.top()]) continue;
		st.push(i);
	}
  rep(j, 1, log2(n)) {
    rep(i, 1, n - (1 << j) + 1) {
			int l = STmax[i][j - 1], r = STmax[i + (1 << (j - 1))][j - 1];
			if (arr[l] > arr[r]) {
				STmax[i][j] = l;
			} else {
				STmax[i][j] = r;
			}
    }
  }
	int ans = 0;
	rep(i, 1, n) {
		if (i + 1 <= tmp[i] - 1) ans = max({ans, 0, STmaxSearch(i + 1, tmp[i] - 1) - i + 1});
	}
	cout << ans;
	return 0;
}
