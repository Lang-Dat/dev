#include<bits/stdc++.h>
using namespace std;
long long chon1 = 1, n, chon = 1;
const long long MOD = 1e9;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("lineup.inp","r",stdin);
    freopen("lineup.out","w",stdout);
    cin >> n;
    if (n == 3) {cout << 3;return 0;}
    long long t = n-1;
    chon1 = 1;
    while (1)
    {
       chon1 = (chon1*t) % MOD;
       if (t - 2 <= 0) break;
       else
       {
           t = t - 2;
       }
    }
    chon1 = (n - 1) % MOD;
    t = n - 3;
    while (1)
    {
        chon = (chon * t) % MOD;
        if (t - 2 <= 0) break;else t = t - 2;
    }
    cout << (chon1+chon) % MOD;
//    cout << s;
}
