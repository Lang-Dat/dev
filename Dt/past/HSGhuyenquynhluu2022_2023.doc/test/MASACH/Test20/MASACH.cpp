#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nmax 1000005
using namespace std;
int a[nmax],n,x;
int main()
{
    fast;
    freopen("MASACH.INP","r",stdin);
    freopen("MASACH.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        a[x]++;
    }
    int ans=a[1];
    for(int i=2; i<=n; i++)
        ans=max(ans,a[i]);
    for(int i=1; i<=n; i++)
        if(ans==a[i])
        {
            cout<<i<<" "<<ans;
            break;
        }
    return 0;
}
