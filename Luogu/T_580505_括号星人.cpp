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
pair<stg, int> s[(int)1e5 + 5];

bool cp(stg a, stg b) {
  stack<char> a1, b1;
  for (char v : a) {
    if (v == '(') a1.push(v);
    else if (!a1.empty()) a1.pop();
  }
  for (char v : b) {
    if (v == '(') b1.push(v);
    else if (!b1.empty()) b1.pop();
  }
  if (a1.size() == b1.size()) return a > b;

  return a1.size() > b1.size();
}

bool cmp(pair<stg, int> a, pair<stg, int> b) {
  return cp(a.first, b.first);
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) { cin >> s[i].first; s[i].second = i; }
  sort(s + 1, s + n + 1, cmp);
  stg ne;
  rep(i, 1, n) ne += s[i].first;
  stack<char> tmp;
  for (char v : ne) {
  if (v == '(') tmp.push(v);
  else if (!tmp.empty()) tmp.pop();
  }
  if (tmp.size()) cout << -1;
  else {
    rep(i, 1, n) cout << s[i].second << " ";
  }
	return 0;
}
