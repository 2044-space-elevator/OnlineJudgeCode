#include <bits/stdc++.h>
using namespace std;

bool isPrefix(string a, string b) {
    if (b.find(a) == 0) {
        return 1;
    }
    return 0;
}

bool isSuffix(string a, string b) {
    reverse(b.begin(), b.end());
    reverse(a.begin(), a.end());
    if (b.find(a) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    bool prefix = isPrefix(a, b);
    bool suffix = isSuffix(a, b);
    if (prefix && suffix) {
        cout << 0 << endl;
    } else if (prefix && !suffix) {
        cout << 1 << endl;
    } else if (!prefix && suffix) {
        cout << 2 << endl;
    } else if (!prefix && !suffix) {
        cout << 3 << endl;
    }
}