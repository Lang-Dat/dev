#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fore(i,a)  for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i-1))&1)
#define fi  first
#define se  second
#define LL  long long

#define iii pair<int,ii>
using namespace std;
string st = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
long long n;
string s,s1;
int ch=0;
bool kt(string stt)
{
     char tg;
     int nn=stt.size();
     for (int l=nn; l>=2; l--)
        for (int ii=0 ;ii <= nn-l;ii++)
            if (stt[ii]<stt[ii+1]) { swap(stt[ii],stt[ii+1]);}

    if (st.find(stt)==-1) return 0;
    else return 1;
}


long long  bcnn(long long X, long long Y)
{
return (X/__gcd(X,Y)*Y);
}
///-----------------------------
string  changenum(int X){
    string XX = "";
    while (X) XX = (char)(X % 10 + '0') + XX, X/=10;
    return XX;
}
///-----------------------------
void    solve()
{

    cin>>s; n=s.size();

    int cs=0,m=0;
    for (int k=26; k>=1; k--)
       {ch=0;
       for (int i =0 ; i<=n-k; i++)
          {
            s1=s.substr(i,k);
            if (kt(s1)==1){cout<<s1; ch=1;break;}
          }
        if (ch==1)break;
       }
}
///-----------------------------
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int test = 1; test <= 24; ++test) {
        string name = "hoanvi";
        name += changenum(test);
        cerr << name << endl;
        string inp = name + ".inp";
        string out = name + ".out";
        freopen(inp.c_str(), "r", stdin);
        freopen(out.c_str(), "w", stdout);
        solve();
        cout << '\n';
    }
    return 0;
}


