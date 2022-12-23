/**
 *	author: Lăng Trọng Đạt
 *	create: 21-12-2022 21:27:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int gold[LIM], sliver[LIM], bronze[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./OLYMPIC.INP", "r", stdin);
    freopen("./OLYMPIC.OUT", "w", stdout);
    #endif

    int n, q, l, r, tmp;
    std::cin >> n >> q;
    //int nums[n];
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        gold[i] = gold[i-1] + (tmp == 1);
        sliver[i] = sliver[i-1] + (tmp == 2);
        bronze[i] = bronze[i-1] + (tmp == 3);
    }
        
    while (std::cin >> l >> r) 
        std::cout << gold[r] - gold[l - 1] << " " <<
                     sliver[r] - sliver[l - 1] << " " <<
                     bronze[r] - bronze[l - 1] << "\n";
    return 0;
}