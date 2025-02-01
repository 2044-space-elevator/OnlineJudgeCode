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

#define int ull
int n;
struct BinaryTree {
  int l, r;
}tree[(int)1e7 + 5];
int fa[(int)1e7 + 5];
int arr[(int)1e7 + 5];
stack<int> st;

main() {
//	int t; cin >> t; while (t--) solve();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  rep(i, 1, n) {
    int x;
    cin >> x;
    arr[i] = x;
    if (st.size() && x > arr[st.top()]) {
      if (tree[st.top()].r) tree[st.top()].l = i;
      else tree[st.top()].r = i;
      fa[i] = st.top();
    }
    while (st.size() && x < arr[st.top()]) {
      tree[fa[st.top()]].r = i;
      fa[i] = fa[st.top()];
      tree[st.top()].r = tree[i].l;
      fa[tree[i].l] = st.top();
      tree[i].l = st.top();
      fa[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  int ans1 = 0, ans2 = 0;
  rep(i, 1, n) {
    ans1 ^= i * (tree[i].l + 1);
    ans2 ^= i * (tree[i].r + 1);
  }
  cout << ans1 << " " << ans2;
	return 0;
}
