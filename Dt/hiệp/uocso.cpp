#include <bits/stdc++.h>
#include <debug.h>
#define N 100000
#define ll long long
using namespace std;
ll p[N];
ll res;
void phantich(int a, int &x)
{
    int i = 2;
    while (i*i <= a)
    {
        while (a % i == 0)
        {
            a /= i;
            p[i]++;
        }
        i++;
    }
    x = a;
}

int main()
{
    // freopen("uocso.inp","r",stdin);
    // freopen("uocso.out","w",stdout);
    int n;
    cin >> n;
    while (n--)
    {
        memset(p,0,sizeof(p));
        int a, b, x = 0, y = 0;
        cin >> a >> b;
        phantich(a,x);
        phantich(b,y);
        res = 1;
        for (int i=1; i<N;i++)
        if (p[i] > 0) res *= (p[i] + 1);
        if (x > 1 && y > 1)
        {
            log(x, y)
            if (x == y) res *= 3;
            else res *= 4;
        }
        else    if (x > 1 || y > 1) res *= 2;
        cout << res << '\n';
    }
    return 0;
}
