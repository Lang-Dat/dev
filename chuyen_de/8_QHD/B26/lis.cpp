#include <bits/stdc++.h>
#define N 100
#define inf int(1e9)
using namespace std;
int a[N+3], F[N+3], vet[N+3];
int n;
vector <int> x;
int main()
{
    freopen("lis.inp","r",stdin);
    freopen("lis.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    a[0] = -inf; a[n+1] = inf;
    F[0] = 1;
    for (int i=1; i<=n+1; i++)
        for (int j=0; j<i; j++)
        if (a[j] < a[i] && F[i] < F[j] + 1)
        {
            F[i] = F[j] + 1;
            vet[i] = j;
        }
    cout << F[n+1] - 2 << "\n";
    for (int j=n+1; j > 0; j = vet[j])
        x.push_back(a[j]);
    for (int j=x.size() - 1; j>0; j--)
        cout << x[j] << " ";
    return 0;
}
