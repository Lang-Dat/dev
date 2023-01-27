/**
 *	author : Lăng Trọng Đạt
 *	creater: 27-01-2023 19:17:48
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e4 + 5;
static int freq[LIM];
int n, tmp, best = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);
    #endif

    std::cin >> n;
    while (std::cin >> tmp) {
        freq[tmp]++;
        best = max(freq[tmp], best);
    }

    std::cout << best << "";
    
    return 0;
}