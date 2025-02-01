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

int n, m, r;
int arr[1005][1005];
int henmin[1005][1005];
int mi[1005][1005];
int henmax[1005][1005];
int ma[1005][1005];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m>> r;
  rep(i, 1, n) {
    rep(j, 1, m) {
      cin >> arr[i][j];
    }
  }
  deque<int> q;
  rep(i, 1, n) {
    rep(j, 1, m) {
      if (q.size() && q.front() + r < j + 1) q.pop_front();
      while (q.size() && arr[i][q.back()] > arr[i][j]) q.pop_back();
      q.push_back(j);
      if (j >= r) henmin[i][j] = arr[i][q.front()];
    }
    q.clear();
  }
  rep(i, 1, n) {
    rep(j, 1, m) { 
      if (q.size() && q.front() + r < j + 1) q.pop_front();
      while (q.size() && arr[i][q.back()] < arr[i][j]) q.pop_back();
      q.push_back(j);
      if (j >= r) henmax[i][j] = arr[i][q.front()];
    }
    q.clear();
  }
  #ifndef ONLINE_JUDGE
  rep(i, 1, n) {
    rep(j, 1, m) {
      cout << henmax[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
  rep(i, 1, n) {
    rep(j, 1, m) {
      cout << henmin[i][j] << ' ';
    }
    cout << endl;
  }
  #endif
  rep(j, r, m) {
    rep(i, 1, n) {
      if (q.size() && q.front() + r < i + 1) q.pop_front();
      while (q.size() && henmin[q.back()][j] > henmin[i][j]) q.pop_back();
      q.push_back(i);
      if (i >= r) mi[i][j] = henmin[q.front()][j];
    }
    q.clear();
  }
  rep(j, r, m) {
    rep(i, 1, n) {
      if (q.size() && q.front() + r < i + 1) q.pop_front();
      while (q.size() && henmax[q.back()][j] < henmax[i][j]) q.pop_back();
      q.push_back(i);
      if (i >= r) ma[i][j] = henmax[q.front()][j];
    }
    q.clear();
  }
  int ans = INT_MAX;
  rep(i, r, n) rep(j, r, m) {
    ans = min(ans, ma[i][j] - mi[i][j]);
  }
  cout << ans;
	return 0;
}
