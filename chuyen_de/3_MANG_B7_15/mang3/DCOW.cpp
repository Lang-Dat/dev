/**
 *	author: Lăng Trọng Đạt
 *	create: 24-12-2022 34:47:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1005;
static int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DCOW.INP", "r", stdin);
    freopen("./DCOW.OUT", "w", stdout);
    #endif

    int n, tmp;
    std::cin >> n;
    //int freq[n];
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        freq[tmp]++;
    }
    int64_t count = 0;

    for (int i : freq)
        count += (i - 1) * i / 2;

    std::cout << count << "";

    return 0;
}