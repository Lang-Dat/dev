#include <bits/stdc++.h>
#define N 100000
#define pii pair<int,int>
using namespace std;
pii a[N+2],b[N+2];
vector <pii> res;
int n,m,x,y;
int tknp(int d, int c, int k)
{
    int vt = 0;
    while (d<=c)
    {
        int g = (d+c)/2;
        if (a[g].first - x <= k && k <= a[g].first + y)
        {
            vt = g;
            c  = g - 1;
        }
        else if (a[g].first - x > k) c = g - 1;
        else if (a[g].first + y < k) d = g + 1;
    }
    return vt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seleshirt.inp","r",stdin);
    freopen("seleshirt.out","w",stdout);
    cin >> n >> m >> x >> y;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int j=1; j<=m; j++)
    {
        cin >> b[j].first;
        b[j].second = j;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int p = 0;
    for (int j=1; j<=m; j++)
    {
        int i = tknp(p+1,n,b[j].first);
        if (i > 0)
        {
            res.push_back({a[i].second, b[j].second});
            p = i;
        }
    }
    cout << res.size() << '\n';
    for (auto P: res)
        cout << P.first << " " << P.second << "\n";
    return 0;
}
