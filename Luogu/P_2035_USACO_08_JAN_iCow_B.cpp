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

#define int ll

int arr[1005], n, m;

main() {
//	int t; cin >> t; while (t--) solve();  
  cin >> n >> m;
  int maxest = 0, maxind = 1;
  rep(i, 1, n) { 
    cin >> arr[i];
    if (arr[i] > maxest) {
      maxind = i;
      maxest = arr[i];
    }
  }
  while (m--) {
    cout << maxind << endl;
    rep(i, 1, n) {
      if (i == maxind) {
        continue;
      }
      arr[i] += arr[maxind] / (n - 1);  
    }
    arr[maxind] -= arr[maxind] / (n - 1) * (n - 1);
    rep(i, 1, n) {
      if (arr[maxind] && i != maxind) {
        arr[maxind]--;
        arr[i]++;
      } 
    }
    maxest = 0;
    rep(i, 1, n) {
      if (arr[i] > maxest) {
        maxind = i;
        maxest = arr[i];
      }
    }
  }
  
	return 0;
}
