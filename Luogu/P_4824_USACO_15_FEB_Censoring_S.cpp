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

stg s, t;
int pi[(int)1e6 + 5];
int res[(int)1e6 + 5], st[(int)1e6 + 5], top = 0;
stg ans;

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> s >> t;
	int ls = s.size(); int lt = t.size();
	s = " " + s; t = " " + t;
	int j = 0;
	rep(i, 1, lt) {
		while (j && t[j] != t[i]) {
			j = pi[j];
		}	
		if (t[j + 1] == t[i]) j++;
		pi[i + 1] = j;
	}	
	j = 0;
	rep(i, 1, ls) {
		while (j && t[j + 1] != s[i]) {
			j = pi[j];
		}
		if (t[j + 1] == s[i]) j++;
		res[i] = j;
		st[++top] = i;
		if (j == lt) {
			top -= lt;
			j = res[st[top]];
		}
	}
	rep(i, 1, top) {
		cout << s[st[i]];
	}
	return 0;
}
