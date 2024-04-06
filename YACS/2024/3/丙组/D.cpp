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


struct record {
  int price;
  int times;
};
vct<record> input_buy, input_sell, output_buy, output_sell;
map<int, int> buy, sell;

bool cmp1(record a, record b) {
  return a.price < b.price;
}

bool cmp2(record a, record b) {
  return a.price > b.price;
}

main() {
  //  int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) {
    record tmp;
    stg op;
    int price, times;
    cin >> op >> price >> times;
    if (op == "BUY") {
      input_buy.push_back((record){price, times});
    }
    if (op == "SELL") {
      input_sell.push_back((record){price, times});
    }
  }
  sort(input_buy.begin(), input_buy.end(), cmp1);
  sort(input_sell.begin(), input_sell.end(), cmp2);
  for (auto [price, times] : input_buy) {
    buy[price] += times;
  }
  for (auto [price, times] : input_sell) {
    sell[price] += times;
  }
  for (auto [price, times] : buy) {
    output_buy.push_back({price, times});
  }
  for (auto [price, times] : sell) {
    output_sell.push_back({price, times});
  }
  sort(output_buy.begin(), output_buy.end(), cmp1);
  sort(output_sell.begin(), output_sell.end(), cmp2);
  cout << output_buy.size() + output_sell.size() << endl;
  for (auto [price, times] : output_buy) {
    cout << "BUY " << price << ' ' << times << endl;
  }
  for (auto [price, times] : output_sell) {
    cout << "SELL " << price << " " << times << endl;
  }
  return 0;
}