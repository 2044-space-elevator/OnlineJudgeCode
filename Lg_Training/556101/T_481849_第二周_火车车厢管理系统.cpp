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
list<int> lst{1};
list<int>::iterator pt[(int)1e6 + 5];

list<int>::iterator find(int x) {
  list<int>::iterator itr;
  for (itr = lst.begin(); itr != lst.end(); itr++) {
    if (*itr == x) {
      break;
    }
  }
  return itr;
}

void solve() {
  int op;
  cin >> op;
  list<int>::iterator itr;
  if (op == 1) {
    int x, y;
    cin >> x >> y;
    itr = pt[x];
    itr++;
    lst.insert(itr, y);
    itr--;
    pt[y] = itr;
  } else if (op == 2) {
    int x;
    cin >> x;
    itr = pt[x];
    itr++;
    if (itr == lst.end()) cout << "0\n";
    else cout << *itr << endl;
  } else if (op == 3) {
    int x;
    cin >> x;
    itr = pt[x];
    itr++;
    lst.erase(itr);
  }
}


main() {
  ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
  pt[1] = lst.begin();
	int t; cin >> t; while (t--) solve();
	return 0;
}
