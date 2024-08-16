#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
typedef long long ll;
#define int ll
#define rep(v,b,e) for(int v=b;v<=e;v++)
#define repq(v,b,e) for(int v=b;v<e;v++)
#define rrep(v,e,b) for(int v=b;v>=e;v--)
#define rrepq(v,e,b) for(int v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef unsigned long long ull;

int NormalFib[(int)1e7 + 7];

const ll MOD = 1e9 + 7;

struct Matrix {
  ll m[5][5];
  Matrix() {
    memset(m, 0, sizeof(m));
  }
  Matrix operator*(const Matrix& b) const {
    Matrix rns;
    rep(i, 1, 2) { rep(j, 1, 2) { rep(k, 1, 2) {
      rns.m[i][j] += m[i][k] % MOD * b.m[k][j] % MOD;
      rns.m[i][j] %= MOD;
    } } }
    return rns;
  }
}ans, base;

void MatrixInit() {
  base.m[1][1] = base.m[1][2] = base.m[2][1] = 1;
  base.m[2][2] = ans.m[2][1] = ans.m[2][2] = 0;
  ans.m[1][1] = ans.m[1][2] = 1;
}

void qpow(ll b) {
  while (b) {
    if (b & 1) ans = ans * base;
    base = base * base;
    b >>= 1;
  }
}
void NormalFibInit() {
  NormalFib[0] = NormalFib[1] = 1;
  rep(i, 2, INT_MAX) {
    NormalFib[i] = NormalFib[i - 1] + NormalFib[i - 2];
    if (NormalFib[i] >= MOD) {
      break;
    }
  }
}

ll fastpow(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b & 1) r *= a % MOD;
    a = a * a % MOD;
    a %= MOD;
    r %= MOD;
    b >>= 1;
  }
  return r % MOD;
}

void solve() {
  MatrixInit();
  ll n;
  cin >> n;
  ll a = n;
  rep(i, 1, 100) {
    if (NormalFib[i] >= MOD) {
      break;
    }
    if (a >= NormalFib[i]) a++; else break;
  }
  ll b;
  if (n >= 2) {
    qpow(n - 2);
    b = ans.m[1][1];
  } else b = 1;
  cout << fastpow(a, b) << '\n';

}


main() {
  NormalFibInit();
	int t; cin >> t; while (t--) solve();
	return 0;
}
