#include<iostream>
#include<vector>
using namespace std;

const int BUFFER_SIZE = 1 << 20;
char inbuf[BUFFER_SIZE], *p1 = inbuf, *p2 = inbuf;
inline char getchar_fast() {
    if (p1 == p2) {
        p2 = (p1 = inbuf) + fread(inbuf, 1, BUFFER_SIZE, stdin);
        if (p1 == p2) return EOF;
    }
    return *p1++;
}
inline int read() {
    int x = 0;
    char ch = getchar_fast();
    while (ch < '0' || ch > '9') ch = getchar_fast();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar_fast();
    }
    return x;
}

char outbuf[BUFFER_SIZE];
int outpos = 0;
inline void putchar_fast(char c) {
    outbuf[outpos++] = c;
    if (outpos == BUFFER_SIZE) {
        fwrite(outbuf, 1, BUFFER_SIZE, stdout);
        outpos = 0;
    }
}
inline void write(int x) {
    if (x < 0) putchar_fast('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar_fast(x % 10 + '0');
}

const int N=1e3+5;
const int MAXP=4*N*N+5;
int mx[MAXP], tag[MAXP]; // tag=-1 表示没有统一标记

#define max4(a,b,c,d) (max(max(a,b),max(c,d)))
void pushup(int p,int l,int r,int u,int d) { 
    int res=(tag[p]==-1?0:tag[p]); 
    int mx1=(l<r?mx[(p<<2)]:0), mx2=(l<r?mx[(p<<2)|1]:0); 
    int mx3=(u<d?mx[(p<<2)|2]:0), mx4=(u<d?mx[(p<<2)|3]:0); 
    if(l<r && u<d) res=max4(max(res,mx1),mx2,mx3,mx4); 
    else if(l<r) res=max(res,max(mx1,mx2)); 
    else if(u<d) res=max(res,max(mx3,mx4)); 
    mx[p]=res; 
}

void modify(int p,int l,int r,int u,int d,int ql,int qr,int qu,int qd,int val){
    if(ql<=l && r<=qr && qu<=u && d<=qd){
        tag[p]=val; mx[p]=val; return;
    }
    if(r<ql || qr<l || d<qu || qd<u) return;
    int ml=(l+r)>>1, mu=(u+d)>>1;
    if(l<=ml && u<=mu) modify(p<<2,l,ml,u,mu,ql,qr,qu,qd,val);
    if(l<=ml && mu<d) modify((p<<2)|1,l,ml,mu+1,d,ql,qr,qu,qd,val);
    if(ml<r && u<=mu) modify((p<<2)|2,ml+1,r,u,mu,ql,qr,qu,qd,val);
    if(ml<r && mu<d) modify((p<<2)|3,ml+1,r,mu+1,d,ql,qr,qu,qd,val);
    pushup(p,l,r,u,d);
}

int query(int p,int l,int r,int u,int d,int ql,int qr,int qu,int qd){
    if(ql<=l && r<=qr && qu<=u && d<=qd) return mx[p];
    if(r<ql || qr<l || d<qu || qd<u) return 0;
    if(tag[p]!=-1 && mx[p]==tag[p]) return tag[p];
    int res=(tag[p]==-1?0:tag[p]);
    int ml=(l+r)>>1, mu=(u+d)>>1;
    if(l<=ml && u<=mu) res=max(res,query(p<<2,l,ml,u,mu,ql,qr,qu,qd));
    if(l<=ml && mu<d) res=max(res,query((p<<2)|1,l,ml,mu+1,d,ql,qr,qu,qd));
    if(ml<r && u<=mu) res=max(res,query((p<<2)|2,ml+1,r,u,mu,ql,qr,qu,qd));
    if(ml<r && mu<d) res=max(res,query((p<<2)|3,ml+1,r,mu+1,d,ql,qr,qu,qd));
    return res;
}

signed main(){
    int d=read(),s=read(),n=read();
    for(int i=0;i<MAXP;i++) tag[i]=-1;
    for(int i=1;i<=n;i++){
        int dd=read(),ss=read(),ww=read(),xx=read(),yy=read();
        int ql=xx+1,qr=xx+dd,qu=yy+1,qd=yy+ss;
        int h=query(1,1,d,1,s,ql,qr,qu,qd)+ww;
        modify(1,1,d,1,s,ql,qr,qu,qd,h);
    }
    write(query(1,1,d,1,s,1,d,1,s));
    putchar_fast('\n');
    fwrite(outbuf,1,outpos,stdout);
    return 0;
}