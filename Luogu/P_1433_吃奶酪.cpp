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
int n;
int per[16];
double x[16], y[16];
bool vis[16];

double dist(int a, int b) {
  return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}
double ans = INT_MAX;
double Rand() {
  return (double)rand() / RAND_MAX;
}

double get() {
  double sum = 0;
  rep(i, 1, n) {
    sum += dist(per[i], per[i - 1]); 
  }
  return sum;
}

void sa() {
  double t = 1e5;
  while (t > 1e-4) {
    int a = rand() % n + 1;
    int b = rand() % n + 1;
    swap(per[a], per[b]);
    double tmp = get();
    if (tmp < ans) {
      ans = tmp;
    } else if (pow(2.718281828, (ans - tmp) / t) < Rand()) {
      swap(per[a], per[b]);
    }
    t *= 0.997;
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
srand(time(NULL));
  cin >> n;
  rep(i, 1, n) {
    cin >>  x[i] >> y[i];
    per[i] = i;
  }
  ans = get();
  while ((double)clock() / CLOCKS_PER_SEC <= 0.97) sa();
  printf("%.2lf", ans);
	return 0;
}
