#include  <bits/stdc++.h>
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
#define ii  pair<int,int>
#define iii pair<int,ii>
using namespace std;
string st = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
int test;
LL a;
///--------------------------
int random(int l, int r) {
    long long x = 1ll * rand() * rand() * rand() + 1ll * rand() * rand() + rand();
    return int(x % (r - l + 1) + l);
}
///--------------------------
string changenum(int X){
    string XX = "";
    while (X) XX = (char)(X % 10 + '0') + XX, X/=10;
    return XX;
}
///--------------------------
void	make_test(){
	if(test<=12)
    {
        long long n=random(2,1000);
        for (int i=1;i<=n;i++){long long m =random(0,25);
        cout <<st[m];}
    }
     if(test>12 && test<=24)
    {
        long long n=random(2,100000);
        for (int i=1;i<=n;i++){long long m =random(0,25);
        cout <<st[m];}
    }

}
///--------------------------
int main(void) {
    //srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (test = 1; test <= 24; ++test) {
        string name = "hoanvi";
        name += changenum(test);
        cerr << name << endl;
        string inp = name + ".inp";
        freopen(inp.c_str(), "w", stdout);

	    make_test();
        cout << '\n';
    }
    return 0;
}



