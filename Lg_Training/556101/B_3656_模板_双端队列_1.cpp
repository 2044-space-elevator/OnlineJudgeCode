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

deque<int> dql[1145141];

void solve() {
  stg op;
  cin >> op;
  if (op == "pop_back") {
    int x;
    cin >> x;
    if (dql[x].size()) dql[x].pop_back();
  }
  if (op == "push_back") {
    int x, y;
    cin >> x >> y;
    dql[x].push_back(y);
  }
  if (op == "push_front") {
    int x, y;
    cin >> x >> y;
    dql[x].push_front(y);
  }
  if (op == "pop_front") {
    int x;
    cin >> x;
    if (dql[x].size()) dql[x].pop_front();
  }
  if (op == "size") {
    int x;
    cin >> x;
    cout << dql[x].size() << endl;
  }
  if (op == "front") {
    int x;
    cin >> x;
    cout << dql[x].front() << endl;
  }
  if (op == "back") {
    int x;
    cin >> x;
    cout << dql[x].back() << endl;
  }
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
