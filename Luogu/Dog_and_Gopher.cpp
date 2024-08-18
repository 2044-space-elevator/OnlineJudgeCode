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

struct Point {
  double x, y;
  double dist(const Point& b) const {
    return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
  }
};
istream & operator>> (istream &in, Point &A) {
  in >> A.x >> A.y;
  return in;
}
int n;
void solve() {
  Point dog, mouse;
  cin >> mouse >> dog;
  bool flg = 0;
  rep(i, 1, n) {
    Point tmp;
    cin >> tmp;
    if (flg) continue;
    if (mouse.dist(tmp) * 4.0 <= dog.dist(tmp)) {
      cout << "The gopher can escape through the hole at (";
      cout << fixed << setprecision(3) << tmp.x << "," << tmp.y << ").\n";
      flg = 1;
    }
  } 
  if (!flg) cout << "The gopher cannot escape.\n";
}


main() {
  ios::sync_with_stdio(false);
    cin.tie(0);
	while (cin >> n) solve();
	return 0;
}
