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
const int mod = 1000;

struct Matrix {
    int mat[9][9];
    Matrix() {
        memset(mat, 0, sizeof mat);
    }
    Matrix operator * (Matrix &b) {
        Matrix res;
        rep(i, 1, 8) {
            rep(j, 1, 8) {
                rep(k, 1, 8) {
                    res.mat[i][j] += mat[i][k] * b.mat[k][j];
                    res.mat[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

Matrix qpow(Matrix a, int ex) {
    Matrix res;
    rep(i, 1, 8)  res.mat[i][i] = 1;
    while (ex) {
        if (ex & 1) res = res * a;
        a = a * a;
        ex >>= 1;
    }
    return res;
}
int n;
Matrix init;

void dfs(int now, int step) {
    if (step == 4) {
        init.mat[1][now]++;
        return;
    }
    if (now == 5) return;
    int af = now + 1;
    if (af > 8) af = 1;
    dfs(af, step + 1);
    int bf = now - 1;
    if (bf < 1) bf = 8;
    dfs(bf, step + 1);
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    Matrix base;
    base.mat[2][1] = base.mat[8][1] = base.mat[1][2] = base.mat[3][2] = base.mat[2][3] = base.mat[4][3]
    = base.mat[3][4]  = base.mat[4][5] = base.mat[6][5] = base.mat[7][6]
    = base.mat[6][7] = base.mat[8][7] = base.mat[1][8] = base.mat[7][8] = 1;
    dfs(1, 0);
    //rep(i, 1, 8) cout << init.mat[1][i] << ' ';
    base = qpow(base, n - 4);
    init = init * base;
    cout << init.mat[1][5];
	return 0;
}
