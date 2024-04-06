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
int n, k, w[(int)1e5 + 5];

struct HuffmanTreeNode {
  int w, id, fa;
  int children[10];
  bool operator < (const HuffmanTreeNode &a) const {
    return w > a.w;
  }
}arr[(int)1e5 + 5];
priority_queue<HuffmanTreeNode> arrq;

bool huffman(int now) {
  if (now <= 1) return 0;
  int m = k * now - 1;
  rep(i, 1, now) {
    arr[i].w = w[i];
    arr[i].id = i;
    arrq.push(arr[i]);
  }
  HuffmanTreeNode tmp;
  rep(i, now + 1, m) {
    arr[i].id = i;
    arr[i].fa = 0;
    rep(j, 1, k) {
      tmp = arrq.top(); arrq.pop();
      arr[i].w += tmp.w;
      arr[i].children[j] = tmp.id;
      arr[tmp.id].fa = i;
    }
  }
  return 1;
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> k;
  rep(i, 1, n) {
    cin >> w[i];
  }
  sort(w + 1, w + n + 1, greater<int>());
  huffman(n);
  HuffmanTreeNode s = arrq.top();
  queue<int> q;
  q.push(s.id);
  while (!q.empty()) {
    int idx = q.front();
    cout << arr[idx].w << ' ';
    q.pop();
    rep(i, 1, k) {
      if (arr[idx].children[i]) {
        q.push(arr[idx].children[i]);
      }
    }
  }


	return 0;
}
