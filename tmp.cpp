#include <bits/stdc++.h>//万能头文件
using namespace std;
const int L = 500;//设置高精度乘法长度为500左右
string mul(string a,string b)//高精度乘法a,b,均为非负整数
{
    string s;
    int na[L],nb[L],nc[L],La=a.size(),Lb=b.size();//na存储被乘数，nb存储乘数，nc存储积
    fill(na,na+L,0);fill(nb,nb+L,0);fill(nc,nc+L,0);//将na,nb,nc都置为0
    for(int i=La-1;i>=0;i--) na[La-i]=a[i]-'0';//将字符串表示的大整形数转成i整形数组表示的大整形数
    for(int i=Lb-1;i>=0;i--) nb[Lb-i]=b[i]-'0';
    for(int i=1;i<=La;i++)
        for(int j=1;j<=Lb;j++)
        nc[i+j-1]+=na[i]*nb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）
    for(int i=1;i<=La+Lb;i++)
        nc[i+1]+=nc[i]/10,nc[i]%=10;//统一处理进位
    if(nc[La+Lb]) s+=nc[La+Lb]+'0';//判断第i+j位上的数字是不是0
    for(int i=La+Lb-1;i>=1;i--)
        s+=nc[i]+'0';//将整形数组转成字符串
    return s;
}
string f ( int x ){//f函数用来把任意一个整型数字转化为字符串的形式。
        int i = 0, j;
        string p = "";
        char ch[10], t;
        do{
            ch[i] = x % 10 + '0';
            x /= 10;
            i++;
        }while ( x != 0 );//只要x不为0，就去掉末位。
        ch[i] = '\0';
        for ( j = 0, i--; j <= i/2; j++, i-- ){
            t = ch[j];
            ch[j] = ch[i];
            ch[i] = t;
        }
        return ch;//返回这个字符串
}
int n, c = 1, ans[1001];//ans数组用来存拆分的数字
string s[1001], m = "1";//s数组用来存每一个数字的字符串，方便做高精度乘法，m存总乘积，初值为“1”。
int main(){
    scanf ( "%d", &n );
    if ( n <= 4 ){
        printf ( "%d\n%d\n", n, n );
        return 0;
    }//特判，如果n小于5，自己本身就是最优解。
    for ( int i = 2; i <= n; i++ ){//2到n循环
        if ( n >= i )
        n -= i, ans[c++] = i, s[c-1] = f(i);//每拆分出1个数，n就减去这个数，在用s数组存下等同于这个数的字符串
        else break;//不能再拆分就终止循环
    }
    for ( int i = c - 1; i >= 1; i-- )//逆序倒推
    if ( n > 0 ) ans[i]++, s[i] = f(ans[i]), n--;//多的数分担给其他数
    if ( n > 0 ) ans[c-1]++, s[c-1] = f(ans[c-1]);//如果还多，就分担给最后一个数
    for ( int i = 1 ; i < c ; i++ ){
        cout << ans[i] << " ";//输出每个拆分数
        m = mul ( s[i], m );//每次都将等同于这个数的字符串乘给m
    }
    cout << endl << m;//输出总乘积
    return 0;
}