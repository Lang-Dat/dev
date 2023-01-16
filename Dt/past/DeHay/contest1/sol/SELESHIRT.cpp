#include <bits/stdc++.h>
#define ll long long
#define name "SELESHIRT"
#define For(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define Fod(i,b,a,c) for(ll i=b;i>=a;i-=c)
#define inf int(1e9+5)
#define Nmax int(1e5+5)
#define faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
struct hht
{
    ll id,v,l,r,k;
};
hht a[Nmax];
hht b[Nmax];
ll n,m,x,y;
ll res;

bool cmp1 (hht x, hht y)
{
    return x.v<y.v;
}
bool cmp2 (hht x, hht y)
{
    return x.id<y.id;
}

void input()
{
    cin>>n>>m>>x>>y;
    For(i,1,n,1)
    {
        cin>>a[i].v;
        a[i].l=a[i].v-x;
        a[i].r=a[i].v+y;
        a[i].id=i;
    }
    For(i,1,m,1)
    {
        cin>>b[i].v;
        b[i].id=i;
    }
}
void output()
{
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+m,cmp1);
    ll i=1, j=1;
    while(i<=n && j<=m)
    {
        if(a[i].l<=b[j].v && b[j].v<=a[i].r)
        {
            res++;
            a[i].k=b[j].id;
            i++;
            j++;
        }
        else if(b[j].v<a[i].l) j++;
        else i++;
    }
    sort(a+1,a+1+n,cmp2);
    cout<<res<<"\n";
    For(i,1,n,1)
    {
        if(a[i].k!=0) cout<<a[i].id<<"\t"<<a[i].k<<"\n";
    }
}

int main()
{
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    faster
    input();
    output();
    return 0;
}
