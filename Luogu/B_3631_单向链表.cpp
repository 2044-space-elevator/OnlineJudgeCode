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

struct l {
  int prev = 0, dat = 0, nxt = 0;
}li[(int)1e5 + 5];
int cnt = 0;
int pos[(int)1e6 + 5];

void add(int x, int y) {
  li[++cnt].dat = y;
  li[cnt].prev = pos[x];
  li[cnt].nxt = li[pos[x]].nxt;
  li[li[pos[x]].nxt].prev = cnt;
  li[pos[x]].nxt = cnt;
  pos[y] = cnt;
}

void erase(int x) {
  li[li[pos[x]].prev].nxt = li[pos[x]].nxt;
  li[li[pos[x]].nxt].prev = li[pos[x]].prev;
  pos[x] = 0;
}

int search(int x) { return li[li[pos[x]].nxt].dat; }

void solve() {
  int op;
  cin >> op;
  if (op == 1) {
    int x, y;
    cin >> x >> y; 
    add(x, y); 
  }
  if (op == 2) {
    int x;
    cin >> x;
    cout << search(x) << "\n";
  }
  if (op == 3) {
    int x; cin >> x;
    erase(li[li[pos[x]].nxt].dat);
  }
}

main() {
  add(0, 1);
	int t; cin >> t; while (t--) solve();
	return 0;
}
