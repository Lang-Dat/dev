/**
 *	author : Lăng Trọng Đạt
 *	creater: 01-02-2023 20:14:01
**/
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

// Every positive integer x can be represent uniquely as x=u*p^2 for some positive integer u,p and u as small as possible (u is squarefree number).

static const int LIM_VALUE = 1e7 + 5;
bitset<LIM_VALUE> is_squarefree;
int n;

long long solve() {
    is_squarefree.flip();
    long long res = 0, j;

    for (int i = 1; i <= n; i++)
        if (is_squarefree[i]) {
            for (j = 2; i * j * j <= n; j++)
                is_squarefree[i * j * j] = false;
            res += (j - 1) * (j - 2) / 2;
        }

    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BSQUARE.INP", "r", stdin);
    freopen("./BSQUARE.OUT", "w", stdout);
    #endif

    std::cin >> n;
    std::cout << solve() << "";

    return 0;
}