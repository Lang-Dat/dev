/**
 *	author: Lang Dat
 *	create: 20-11-2022 21:55:10
**/
#include <iostream>
#include <math.h>
using namespace std;

#define ull unsigned long long

int decresing(int &n, int i) {
    int tmp = 0;
    while (n % i == 0) {
        n /= i;
        tmp++;
    }
    return tmp;
}
int uoc(int n) {
    int sum = 1;
    sum *= ((ull)(std::pow(2, decresing(n, 2) + 1) + 0.1) - 1) / (double)(2 - 1); 
    sum *= ((ull)(std::pow(3, decresing(n, 3) + 1) + 0.1) - 1) / (double)(3 - 1); 
    for (int i = 5; i * i <= n; i += 6) {
        sum *= ((ull)(std::pow(i, decresing(n, i) + 1) + 0.1) - 1) / (double)(i - 1); 
        sum *= ((ull)(std::pow(i+2, decresing(n, i+2) + 1) + 0.1) - 1) / (double)(i+2 - 1); 
    }
    if (n > 1) sum *= ((ull)(std::pow(n, 1 + 1) + 0.1) - 1) / (double)(n - 1);
    return sum;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);
    #endif
    
    int a, b;
    std::cin >> a >> b;
    cout << (bool)((a == uoc(b)) || (uoc(a) == b));
    return 0;
}