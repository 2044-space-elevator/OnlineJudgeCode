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
#define int ll

void solve() {
	
}

const int N = 3e5 + 5;

int n, arr[N], tmp[N], ans;

void sortgb(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  sortgb(l, mid);
  sortgb(mid + 1, r);
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= r) {
    if (arr[i] > arr[j]) {
      tmp[k] = arr[i];
      k++;
      i++;
    }
    else {
      ans += mid - i + 1;
      tmp[k] = arr[j];
      k++;
      j++;
    }
  }
  while (i <= mid) {
    tmp[k] = arr[i];
    k++;
    i++;
  } 
  while (j <= r) {
    tmp[k] = arr[j];
    k++;
    j++;
  }
  rep(i, l, r)  {
    arr[i] = tmp[i];
  }
}

main() {
  cin >> n;
  rep(i, 1, n) {
    cin >> arr[i];
  }
  sortgb(1, n);
  cout << ans;
	return 0;
}
