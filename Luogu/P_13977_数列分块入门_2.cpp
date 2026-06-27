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


char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}

void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}

int n, q;
const int N = 2e5 + 5;
int B, bel[N], bl[N], br[N];
const int bsz = 420;
ll arr[N], sorted[500][425], lazy[500];

void init() {
	for (int i = 1; i <= bsz; i++) {
		bl[i] = (i - 1) * bsz + 1;
		br[i] = i * bsz;
		if (br[i] >= n) {
			br[i] = n;
			B = i;
			break;
		}
	}
	for (int i = 1; i <= B; i++) {
		for (int j = bl[i]; j <= br[i]; j++) {
			bel[j] = i;
			sorted[i][j - bl[i]] = arr[j];
		}
		sort(sorted[i], sorted[i] + br[i] - bl[i] + 1);
		lazy[i] = 0;
	}
}

void rebuild(int block) {
	for (int j = bl[block]; j <= br[block]; j++) {
		arr[j] += lazy[block];
		sorted[block][j - bl[block]] = arr[j];
	}
	lazy[block] = 0;
	sort(sorted[block], sorted[block] + br[block] - bl[block] + 1);
}

void update(int l, int r, ll v) {
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; i++) {
			arr[i] += v;
		}
		rebuild(bel[l]);
		return;
	}
	for (int i = l; i <= br[bel[l]]; i++) {
		arr[i] += v;
	}
	rebuild(bel[l]);

	for (int i = bl[bel[r]]; i <= r; i++) {
		arr[i] += v;
	}
	rebuild(bel[r]);
	for (int i = bel[l] + 1; i < bel[r]; i++) {
		lazy[i] += v;
	}
}

int query(int l, int r, ll v) { 
	int ans = 0;
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; i++) {
			if (arr[i] + lazy[bel[l]] < v) ans++;			
		}
		return ans;
	}
	for (int i = l; i <= br[bel[l]]; i++) {
		if (arr[i] + lazy[bel[l]] < v) ans++;
	}
	for (int i = bl[bel[r]]; i <= r; i++) {
		if (arr[i] + lazy[bel[r]] < v) ans++;
	}
	for (int i = bel[l] + 1; i < bel[r]; i++) {
		ll target = v - lazy[i];
		int pos = lower_bound(sorted[i], sorted[i] + br[i] - bl[i] + 1, target) - sorted[i];
		ans += pos;
	}
	return ans;
}

main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		arr[i] = read();
	}
	init();
	for (int i = 1; i <= n; i++) {
		int typ;
		typ = read();
		if (typ == 1) {
			int l, r, c;
			l = read(); r = read(); c = read();
			c = 1ll * c * c;
			write(query(l, r, c));
			puts("");
		} else {
			int l, r, c;
			l = read(), r = read(), c = read();
			update(l, r, c);
		}
	}
	//	int t; cin >> t; while (t--) solve();
	return 0;
}