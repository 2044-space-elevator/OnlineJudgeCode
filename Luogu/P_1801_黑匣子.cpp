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

priority_queue<int, vector<int>, greater<int> > q2;
priority_queue<int> q;
int arr[(int)2e5 + 5];
int qry[(int)2e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) cin >> arr[i];
  int last = 1;
  rep(i, 1, m) {
    int x;
    cin >> x;
    rep(j, last, x) {
      q.push(arr[j]);
      if (q.size() == i)
        q2.push(q.top()), q.pop();
    }
    last = x + 1;
    cout << q2.top() << endl;
    q.push(q2.top()), q2.pop();
  }
	return 0;
}
