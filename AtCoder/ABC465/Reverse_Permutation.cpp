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

deque<int> q;

main() {
	stg s;
	cin >> s >> s;
	s = " " + s;
	bool rev = 0;
	repq(i, 1, s.size()) {
		if (!rev) {
			q.push_back(i);
		} else q.push_front(i);
		if (s[i] == 'o') rev = !rev;
	}
	if (!rev) {
		while (q.size()) {
			cout << q.front() << ' ';
			q.pop_front();
		}
	} else {
		while (q.size()) {
			cout << q.back() << ' ' ;
			q.pop_back();
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
