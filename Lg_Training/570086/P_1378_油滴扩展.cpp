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

const double pi = 3.141592653589793;

int n, zx, yx, sy, xy;
int objx[10], objy[10];
double radius[10];
double ans = 0;

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double Rand() {
  return (double)rand() / RAND_MAX;
}

double get() {
  double sum = 0;
  rep(i, 1, n) {
    radius[i] = 
      min(
        {
          abs(yx - objx[i]),
          abs(zx - objx[i]),
          abs(sy - objy[i]),
          abs(xy - objy[i])
        }
      );
    repq(j, 1, i) {
      double di = dis(objx[i], objy[i], objx[j], objy[j]);
      if (di >= radius[j]) { 
        radius[i] = min(radius[i], di - radius[j]);
      } else radius[i] = 0;
    }
    sum += radius[i] * radius[i] * pi;
  }
  return abs(yx - zx) * abs(sy - xy) - sum; 
}

void sa() {
  double t = 1000;
  while (t > 1e-12) {
    int a = rand() % n + 1;
    int b = rand() % n + 1;
    swap(objx[a], objx[b]); swap(objy[a], objy[b]);
    double tmp = get();
    if (tmp < ans) {
      ans = tmp;
    } else if (exp((ans - tmp) / t) < Rand()){
      swap(objx[a], objx[b]); swap(objy[a], objy[b]);
    }
    t *= 0.996;
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  srand(time(NULL));
  cin >> n; 
  cin >> zx >> sy >> yx >> xy;
  if (yx > zx) swap(yx,zx);
  if (sy > xy) swap(sy, xy);
  rep(i, 1, n) cin >> objx[i] >> objy[i];
  ans = get();
  while((double)clock() / CLOCKS_PER_SEC <= 0.9) sa();
  printf("%.0lf\n", ans);
	return 0;
}
