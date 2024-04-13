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

stack<stg> st1;
stack<double> st2;

main() {
//	int t; cin >> t; while (t--) solve();
  stg s;
  while (cin >> s) {
    st1.push(s);;
  }
  while (st1.size()) {
    stg x = st1.top(); st1.pop();
    if (x == "+") {
      double num1 = st2.top();
      st2.pop();
      double num2 = st2.top();
       
      st2.pop();
      st2.push(num1 + num2);
    } else if (x == "-") {

      double num1 = st2.top();
      st2.pop();
      double num2 = st2.top();
      st2.pop();
      st2.push(num1 - num2);
    } else if (x == "*") {
       
      double num1 = st2.top();
      st2.pop();
      double num2 = st2.top();
      st2.pop();
      st2.push(num1 * num2);
    } else if (x == "/") {
      double num1 = st2.top();
      st2.pop();
      double num2 = st2.top();
      st2.pop();
      st2.push(num1 / num2);
    } else {
      st2.push(stod(x));
    }
  }
  printf("%f\n", st2.top());
	return 0;
}
