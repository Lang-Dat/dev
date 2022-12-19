/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 44:28:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 3*1e6 + 5;
static int64_t tong_uoc[LIM];

void tinh_tong_uoc() {
    for (int i = 1; i < LIM; i++) {
        for (int j = 1; j * i < LIM; j++)
            tong_uoc[i*j] += i;
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./sodacbiet.OUT", "w", stdout);
    freopen("./sodacbiet.INP", "r", stdin);
    #endif

    tinh_tong_uoc();

    int64_t l, r;
    std::cin >> l >> r;

    int count = 0;
    for (int i = l; i <= r; i++)
        count += tong_uoc[i] > 2*i;

    std::cout << count << "";

    return 0;
}