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

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}


int fa[(int)5e5 + 5];
vct<int> E[(int)5e5 + 5];

void dfs(int u, int f) {
  for (int v : E[u]) {
    if (v == f) continue;
    fa[v] = u; 
    dfs(v, u);
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m, p;
  n = read(); m = read(); p = read();
  repq(i , 1, n) {
    int u, v;
    u = read(); v = read();
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(1, 0);
  rep(i, 1, m) {
    int a, b;
    a = read(); b = read();
    if (a == 1) p = b;
    else if (a == 2) { 
      rep(i, 1, b) {
        if (p == 1) {
          break;
        }
        p = fa[p];
      }
      write(p); putchar('\n');
    }
  }
	return 0;
}
