/**
 *	author : Lăng Trọng Đạt
 *	creater: 01-02-2023 22:20:21
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long f[11];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./T3E10.INP", "r", stdin);
    freopen("./T3E10.OUT", "w", stdout);
    #endif

    int64_t n, tmp, res = 0;

    std::cin >> n;
    while (std::cin >> tmp) {
        f[tmp]++;
    }

    for (int i = 0; i <= 10; i++) 
        for (int j = i; j <= 10; j++) 
            for (int z = j; z <= 10; z++) 
                if (i + j + z == 10) 
                    if (i == j) 
                        res += f[i] * (f[i]-1) * f[z] / 2;
                    else if (j == z) 
                        res += f[i] * f[j] * (f[j]-1) / 2;
                    else 
                        res += f[i] * f[j] * f[z];

    std::cout << res << "";
    return 0;
}