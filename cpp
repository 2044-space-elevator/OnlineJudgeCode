#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

const int base1 = 131;
const int base2 = 131;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

vector<ll> P1, P2;
vector<ll> H1, H2;
vector<ll> H1_rev, H2_rev;
string s;
int n;

void precompute() {
    // 预处理幂次数组
    P1.resize(n + 1);
    P2.resize(n + 1);
    P1[0] = 1;
    P2[0] = 1;
    for (int i = 1; i <= n; i++) {
        P1[i] = (P1[i - 1] * base1) % mod1;
        P2[i] = (P2[i - 1] * base2) % mod2;
    }

    // 预处理字符串 s 的前缀哈希
    H1.resize(n + 1);
    H2.resize(n + 1);
    H1[0] = 0;
    H2[0] = 0;
    for (int i = 1; i <= n; i++) {
        H1[i] = (H1[i - 1] * base1 + s[i - 1]) % mod1;
        H2[i] = (H2[i - 1] * base2 + s[i - 1]) % mod2;
    }

    // 预处理反转字符串 s' 的前缀哈希
    H1_rev.resize(n + 1);
    H2_rev.resize(n + 1);
    H1_rev[0] = 0;
    H2_rev[0] = 0;
    for (int i = 1; i <= n; i++) {
        H1_rev[i] = (H1_rev[i - 1] * base1 + s[n - i]) % mod1;
        H2_rev[i] = (H2_rev[i - 1] * base2 + s[n - i]) % mod2;
    }
}

bool is_palindrome(int l, int r) {
    // 转换为 0-based 索引
    int l0 = l - 1, r0 = r - 1;
    int len = r0 - l0 + 1;

    // 计算正向哈希值
    ll hash1_f = (H1[r0 + 1] - H1[l0] * P1[len] % mod1) % mod1;
    if (hash1_f < 0) hash1_f += mod1;
    ll hash2_f = (H2[r0 + 1] - H2[l0] * P2[len] % mod2) % mod2;
    if (hash2_f < 0) hash2_f += mod2;

    // 计算反向哈希值
    ll hash1_r = (H1_rev[n - l0] - H1_rev[n - 1 - r0] * P1[len] % mod1) % mod1;
    if (hash1_r < 0) hash1_r += mod1;
    ll hash2_r = (H2_rev[n - l0] - H2_rev[n - 1 - r0] * P2[len] % mod2) % mod2;
    if (hash2_r < 0) hash2_r += mod2;

    return (hash1_f == hash1_r) && (hash2_f == hash2_r);
}

int main() {
    // 读入字符串和查询次数
    cin >> s;
    n = s.length();
    precompute();

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (is_palindrome(l, r)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}