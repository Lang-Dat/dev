#include <iostream>
// #include<bits/stdc++.h>
using namespace std;
long long l, r, i, s=0, a[10000000], j=1000000000+7, m=0;
void sang(long long n)
{
    Timer time;
    fill(a+1, a+1+n, 1);
    a[1]=0;
    for(long long i=2; i<=n; i++)
    if(a[i]==1)
    for(long long j=i*i; j<=n; j+=i) a[j]=0;
    std::cout << "Anh tuan: ";
}
void sieve(int n) {
	Timer time;
	std::vector<int> prime(n + 1, 1);
	for (int i = 2; i * i <= n; i++)
		if (prime[i])
			for (int j = i * i; j <= n; j++)
				prime[j] = 0;
}
int main()
{
    // freopen("NT.inp", "r", stdin);
    // freopen("NT.out", "w", stdout);
    // cin>>l>>r;
    int n;
    std::cin >> n;
    sieve(n);
    sang(n);
    // for(i=l; i<=r; i++)
    // if(a[i]==1)
    // {
    //     s++;
    //     m+=((s%j)*(i%j))%j;
    //     m%=j;
    // }
    std::cout<<m;
}
