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

ll mod, k, n;
struct Matrix {
    ll mat[3][3];
    Matrix() {
        memset(mat, 0, sizeof mat);
    }
    Matrix operator * (const Matrix b) {
        Matrix ans;
        rep(i, 1, 2) {
            rep(j, 1, 2) {
                rep(k, 1, 2) {
                    ans.mat[i][j] += mat[i][k] * b.mat[k][j] % mod;
                    ans.mat[i][j] += mod;
                    ans.mat[i][j] %= mod;
                }
            }
        }
        return ans;
    }
}fst, dw;

Matrix qpow(Matrix a, ll b) {
    Matrix res;
    rep(i, 1, 2) res.mat[i][i] = 1;
    while (b) {
        if (b & 1) res =  res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

main() {
//	intt; cin >> t; while (t--) solve();
    cin >> mod >> k >> n;
    k %= mod;
    if (n == 0) { cout << 2; return 0; }
    else if (n == 1) { cout << k; return 0; }
    else if (n == 2) { cout << (k * k - 2) % mod; return 0; }
    fst.mat[1][1] = (k * k - 2) % mod;
    fst.mat[1][2] = k; 
    dw.mat[1][1] = k;
    dw.mat[1][2] = 1;
    dw.mat[2][1] = -1;
    fst = fst * qpow(dw, n - 2);
    cout << fst.mat[1][1];
	return 0;
}

// git log --author=='username' --pretty=tformat: --numstat | awk '{add += $1; sub += $2; loc += $1 - $2; }
// END { printf "added $s, deleted %s, total %s\n", add, sub, loc"}' 