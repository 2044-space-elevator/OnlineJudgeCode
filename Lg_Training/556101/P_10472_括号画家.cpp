#include <bits/stdc++.h>
using namespace std;

stack<char> stk;
map<char, char> ys;

int main() {
    ys['('] = ')';
    ys['['] = ']';
    ys['{'] = '}';
    string s;
    cin >> s;
    int ans = 0;
    int tmp = 0;
    for (char v : s) {
        if (stk.size()) {
            if (stk.top() == ys[stk.top()]) {
                tmp += 2;
                stk.pop();
            } else stk.push(v);
        } else {
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    cout << ans;
}