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

const int N = 1e6 + 5;
int h, w, q;
int fa[N];
struct {
	int xi, yi;
	char c;
}ques[N];
vector<vector<char> > ans;

int find (int x) {
	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

void solve() {
	
}

int ma[N];

main() {
	cin >> h >> w >> q;
	rep(i, 1, h + 1) fa[i] = i;
	ans.resize(h + 1);
	rep(i, 1, h) ans[i].resize(w + 1);
	rep(i, 1, h) {
		ma[i] = 1;
		rep(j, 1, w) {
			ans[i][j] = 'A';
		}
	}
	rep(i, 1, q) {
		cin >> ques[i].xi >> ques[i].yi >> ques[i].c;
	} 
	rrep(i, 1, q) {
		int x = find(1);
		int X = ques[i].xi;
		int Y = ques[i].yi;
		while (x <= X) {
			if (ma[x] <= Y) {
				rep(j, ma[x], Y) {
					ans[x][j] = ques[i].c;
				}
				ma[x] = Y + 1;
				if (ma[x] == w + 1) {
					fa[x] = find(x + 1);
				}
			}
			x = find(x + 1);
		}
	}
	rep(i, 1, h) {
		rep(j, 1, w) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
