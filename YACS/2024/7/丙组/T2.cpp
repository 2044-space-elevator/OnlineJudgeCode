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

pair<ll, ll> arr[(int)2e6 + 4];
int n;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
  if (a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}
main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) {
    cin >> arr[i].first; 
  arr[i].second = i;
  }
  sort(arr + 1, arr + n + 1, cmp);
  rep(i, 1, n) {
    cout << arr[i].second << endl;
  }
  return 0;
}