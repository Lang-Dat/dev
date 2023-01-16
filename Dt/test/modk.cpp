#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
long long n, a[500001], ans = 0, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("modk.inp","r",stdin);
    // freopen("modk.out","w",stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        a[i] = a[i] % k;
        db(a[i])
        a[i] = (a[i] + k) % k;
        m[a[i]]++;
    }
    if (m[0] > 0) ans++;
    for (int i = 1 ; i <= k / 2 ; i++)
    {
        if (k % 2 == 0 && i == k / 2)
        {
            if (m[i] > 0)
            {
                ans++;
            }
        }
        else
        {
            ans += max(m[i], m[k-i]);
        }
    }
    cout << ans;
}
