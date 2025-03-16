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

int n;
const int N = 3e6 + 5;
vct<int> E[N];
struct trie {
  int nex[(int)3e6 + 5][26], cnt = 0;
  bool end[N];
  void insert(stg s) {
    int p = 0;
    repq(i, 0, s.size()) {
      int c = s[i] - 'a';
      if (!nex[p][c]) { nex[p][c] = ++cnt;

      E[p].push_back(nex[p][c]);
      E[nex[p][c]].push_back(p);
      }
      p = nex[p][c]; 
    }
    end[p] = true;
  }
}Trie;
int d[N];
int cur = 0;

void dfs(int u, int fa) {
  for (int v : E[u]) {
    if (v == fa) continue;
    d[v] = d[u] + 1;

    if (d[v] > d[cur] && Trie.end[v]) cur = v;
    dfs(v, u);
  }
}


main() {
//	int t; cin >> t; while (t--) solve();
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("C:\\Users\\S.X.Y\\Downloads\\.in", "r", stdin);
cin >> n;
rep(i, 1, n) {
  stg s;
  cin >> s;
  Trie.insert(s);
}
//cout << Trie.end[6];
  dfs(0, -1);
  d[cur] = 0;
  dfs(cur, 0);
  cout << d[cur] << endl;
	return 0;
}
