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
Point pt[1005];
int n;
void solve() {
  Point dog, mouse;
  // cin >> mouse >> dog;
  cin >> mouse.x >> mouse.y >> dog.x >> dog.y;
  rep(i, 1, n) {
    // cin >> pt[i];
    cin >> pt[i].x >> pt[i].y;
  }
  rep(i, 1, n) {
    if (mouse.dist(pt[i]) * 4.0 <= dog.dist(pt[i])) {
      cout << "The gopher can escape through the hole at (";
      cout << fixed << setprecision(3) << pt[i].x << "," << pt[i].y << ").\n";
      return;
    }
  } 
  cout << "The gopher cannot escape.\n";
}


main() {
  ios::sync_with_stdio(false);
    cin.tie(0);
	while (cin >> n) solve();
	return 0;
}
