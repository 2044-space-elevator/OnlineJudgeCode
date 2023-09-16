#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            int tmptmp = j - i + 1;
            string tmp = s.substr(i, j - i + 1);
            string tmp2 = tmp;
            reverse(tmp2.begin(), tmp2.end());
            if (tmp2 != tmp) {
                tmptmp = 0;
            }
            res = max(res, tmptmp);
        }
    }
    cout << res;
}
// j = s.size() - 1
// i = 1
