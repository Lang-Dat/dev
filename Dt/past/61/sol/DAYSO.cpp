#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
int n, i, j, t;
long int s, l, r, res = 0;
int nums[maxn + 5];
long int sum[maxn + 5];
void sapxep(int dau, int cuoi)
{
    int i, j, t, k;
    i = dau;
    j = cuoi;
    k = sum[(i + j) / 2];
    do
    {
        while (sum[i] < k)
            i = i + 1;
        while (sum[j] > k)
            j = j - 1;
        if (i <= j)
        {
            t = sum[i];
            sum[i] = sum[j];
            sum[j] = t;
            i = i + 1;
            j = j - 1;
        }
    } while (i <= j);
    if (dau < j)
        sapxep(dau, j);
    if (i < cuoi)
        sapxep(i, cuoi);
}
long int calc(long int c)
{
    int i, j;
    long int dem;
    dem = 0;
    j = 0;
    for (i = 0; i <= n; i++)
    {
        while ((j < n) && (sum[j + 1] <= sum[i] + c))
            j = j + 1;
        dem = dem + j - i;
    }
    return dem;
}
int main()
{
    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);
    cin >> n >> l >> r;
    for (i = 1; i <= n; i++)
        cin >> nums[i];
    sum[1] = nums[1];
    for (i = 2; i <= n; i++)
        sum[i] = sum[i - 1] + nums[i];
    sapxep(0, n);
    if (l == 0)
        res = calc(r);
    else
        res = calc(r) - calc(l - 1);
    cout << res;
    return 0;
}
