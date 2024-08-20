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
#define int ull
const int N = 2E6 + 10;
int hash1[N], hash2[N], hash3[N];

int hf1(char x) { return x; }
int hf2(char x) { return x * x;}
int hf3(char x) {return x * 114;}

main() {
//	int t; cin >> t; while (t--) solve();
  stg s;
  int n;
  cin >> s >> n;
  s = " " + s;
  repq(i, 1, s.size()) {
    hash1[i] = hash1[i - 1] + hf1(s[i]);
    hash2[i] = hash2[i - 1] + hf2(s[i]);
    hash3[i] = hash3[i - 1] + hf3(s[i]);
  }
  int sum = 0;
  while (n--) {
    stg t;
    cin >> t;
    t = " " + t;
    int hsum1 = 0, hsum2 = 0, hsum3 = 0;
    repq(i, 1, t.size()) {
      hsum1 += hf1(t[i]);
      hsum2 += hf2(t[i]);
      hsum3 += hf3(t[i]);
    }
    repq(i, 1, s.size()) {
      if (i + 7 >= s.size()) break;
      int a1 = hash1[i + 7] - hash1[i - 1], a2 = hash2[i + 7] - hash2[i - 1], a3 = hash3[i + 7] - hash3[i - 1];
      if (a1 == hsum1 && a2 == hsum2 && a3 == hsum3) {
        sum++;
      }
    }
  }
  cout << sum;
	return 0;
}
