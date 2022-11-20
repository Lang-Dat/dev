/**
 *	author: Lang Dat
 *	create: 20-11-2022 02:07:13
**/
#include <iostream>
#include <cmath>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);
    #endif

    ull lcm, gcd, product;
    std::cin >> gcd >> lcm;

    product = lcm*gcd;
    
    for (int i = (int)sqrt(product)/gcd*gcd; i > 0; i -= gcd) {
        if (product % i == 0) {
            std::cout << i << " " <<  product / i << "";
            return 0;
        }
    }
    return 0;
}