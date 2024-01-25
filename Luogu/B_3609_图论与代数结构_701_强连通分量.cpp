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

const int N = 1e4 + 10, M = 1e5 + 10;
int n, m, low[N], scc[N], st1[N], st2[N], head[N], cnt, st_size1, st_size2, sccsum;
/**
 * low                进入顶点时间
 * scc                所属 scc
 * st1/st2            所属堆栈
 * head               存图的辅助数组，记录该点下一条出边
 * cnt                图的边数
 * st_size1/st_size2  栈的长度
 * sccsum             SCC个数
*/
bool output_vis[N];
struct edge {
  int u, v, next;
}E[M];
vct<int> res[N];

void add(int u, int v) {
  E[++cnt] = {u, v, head[u]};
  head[u] = cnt;
}

void input() {
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v;
    cin >> u >> v;
    add(u, v);
  }
  cnt = 0;
  // cnt 清空，garbow函数进行回收（
}

void garbow(int u) {
  st1[++st_size1] = u;
  st2[++st_size2] = u;
  low[u] = ++cnt;
  for (int i = head[u]; i; i = E[i].next) {
    int v = E[i].v;
    // 老套路
    if (!low[v]) {
      garbow(v);
    }
    else if (!scc[v]) {
      while (low[st2[st_size2]] > low[v]) {
        st_size2--;
      }
    }
  }
  if (st2[st_size2] == u) {
    st_size2--;
    sccsum++;
    do {
      scc[st1[st_size1]] = sccsum;
    }while (st1[st_size1--] != u);
  }
}


main() {
//	int t; cin >> t; while (t--) solve();
  input();
  rep(i, 1, n) {
    if (!low[i]) {
      garbow(i);
    }
  }
  cout << sccsum << endl;
  rep(i, 1, n) {
    res[scc[i]].push_back(i);
  }
  rep(i, 1, n) {
    sort(res[i].begin(), res[i].end());
  }
  rep(i, 1, n) {
    if (!output_vis[scc[i]]) {
      for (int v : res[scc[i]]) {
        cout << v << ' ';
      }
      output_vis[scc[i]] = 1;
      cout << endl;
    }
  }
	return 0;
}
