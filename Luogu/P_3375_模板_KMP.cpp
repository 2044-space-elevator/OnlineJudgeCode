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

stg s1, s2;
int pi[(int)1e6 + 5];

void boarder() {
    int ptr1 = 0, ptr2 = -1;
    pi[0] = -1;
    while (ptr1 < s2.length()) {
        if (ptr2 == -1 || s2[ptr1] == s2[ptr2]) {
            pi[++ptr1] = ++ptr2;
        } else {
            ptr2 = pi[ptr2];
        }
    }
}

int len1, len2;

void KMP() {
    len1 = s1.length(), len2 = s2.length();
    int ptr1 = 0, ptr2 = 0;
    while (ptr1 < len1) {
        if (ptr2 == -1 || s1[ptr1] == s2[ptr2]) {
            ptr1++, ptr2++;
        } else {
            ptr2 = pi[ptr2];
        }
        if (ptr2 == len2) {
            cout << ptr1 - len2 + 1 << endl;
            ptr2 = pi[ptr2];
        }
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> s1 >> s2;
    boarder();
    KMP();
    rep(i, 1, s2.length()) {
        cout << pi[i] << ' ';
    }
    
	return 0;
}
