/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 57:31:08
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;

    static const int LIM = (n - 2) / 3;
    // std::cout << (LIM*n - 3*LIM*(LIM+1)/2 - 2*((n & 1) ? LIM - LIM/2 : LIM / 2)) / 2 << "";
    int count = 0;
    for (int i = 1; i <= LIM ; i++)
        count += (n - 2*((n - i) % 2 == 0) - 3*i) / 2;
        // count += ((n - i) % 2 == 0);
        // for (int j = i + 1; 2*j < n - i; j++)
        //     count++;
                // if (n - (i + j) > j) count++;

    std::cout << count << "";
    return 0;
}