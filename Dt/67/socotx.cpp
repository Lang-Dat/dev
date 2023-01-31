#include<bits/stdc++.h>
using namespace std;
long long n, k, a[200001], d = 1, ans = 0, pivot;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   freopen("socot.inp","r",stdin);
   freopen("socot.out","w",stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,greater<long long>());
    //for (int i = 1 ; i <= n ; i++) cout << a[i] << ' ';
    a[n+1] = 0;
    for (int i = 2 ; i <= n + 1 ; i++)
    {
        if (a[i] != a[i-1])
        {
            long long tmp = (i-1) * (a[i-1] - a[i]);
            if (tmp <= k)
            {
                k = k - tmp;
                long long ss = (a[i-1] - a[i]);
                ans += (i-1) * (a[i-1] + a[i] + 1) * ss / 2;
                //cout << ans << '\n';
                if (k == 0) {cout << ans << '\n';return 0;}
            }
            else
            {
                //cout << tmp << ' ' << k << '\n';
                long long ee = k / (i-1);
                k = k - (i-1) * ee;
                long long pi = a[i-1] - ee + 1;
                ans += (i-1) * (a[i-1] + pi) * ee / 2;
                pi--;
                ans += k * pi;
                cout << ans << '\n';
                return 0;
            }
        }
    }
}
