#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 1E7 + 5;

#define int long long
int n, m, dep[N], dis[N], crr[N], cnt2 = 1, head2[N], s, t;
int inf = dis[N - 1];
bool vis[N];
struct edge {
    int u, v, w, next;
}EF[M];

void add_edge(int u, int v, int w) {
   EF[++cnt2] = {u, v, w, head2[u]};
   head2[u] = cnt2;
}
bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof dep);
    dep[s] = 1;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = head2[u]; i; i = EF[i].next) {
            int v = EF[i].v;
            if (EF[i].w && dep[v] == 0) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    } 
    if (dep[t] == 0) {
        return 0;
    }
    return 1;
}

int dfs(int u, int dis) {
    if (u == t) return dis;
    for (int i = head2[u]; i; i = EF[i].next) {
        int v = EF[i].v;
        if (dep[v] == dep[u] + 1 && EF[i].w) {
            int mi = dfs(v, min(dis, EF[i].w));
            if (mi) {
                EF[i].w -= mi;
                EF[i ^ 1].w += mi;
                return mi;
            }
        }
    }
    return 0;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        int d;
        while (d = dfs(s, inf)) {
            ans += d;
        }
    }
    return ans;
}
vector<int> Ed[M],W[M];
void spfa() {
    queue<int> q;
    memset(dis, 127, sizeof dis);
    q.push(1);
    vis[1] = 1;
    dis[1] = 0;
    while (q.size()) {
        int u = q.front(); vis[u] = 0;
        q.pop();
        for (int i = 0; i < Ed[u].size(); i++) {
            int v = Ed[u][i], w = W[u][i];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    int t = n * 2 + 1;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Ed[u].push_back(v); W[u].push_back(w);
        Ed[v].push_back(u); W[v].push_back(w);    
    }
    spfa();
    for (int i = 1; i <= n; i++) {
        cin >> crr[i];
    }
    add_edge(s, 1, inf);
    add_edge(1, s, 0);
    add_edge(2 * n, t, inf);
    add_edge(t, 2 * n, 0);
    for (int i = 1; i <= n; i++) {
        if (i != 1 && i != n) {
            add_edge(i, i + n, crr[i]);
            add_edge(i + n, i, 0);
        } else {
            add_edge(i, i + n, inf);
            add_edge(i + n, i, 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < Ed[i].size(); j++) {
            int v = Ed[i][j], w = W[i][j];
            if (dis[v] == dis[i] + w) {
                add_edge(i + n, v, inf);
                add_edge(v, i + n, 0);
            }
        }
    }
    cout << dinic();
}
