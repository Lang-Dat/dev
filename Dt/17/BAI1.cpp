/**
 *	author: Lăng Trọng Đạt
 *	create: 06-12-2022 47:56:20
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 1e3 + 3;
int tong_cot[LIM];
int freq_tong_hang[LIM*(int)1e3];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);
    #endif

    int n, tmp, count = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tong_hang = 0;
        for (int j = 0; j < n; j++) {
            std::cin >> tmp;
            tong_cot[j] += tmp;
            tong_hang += tmp;
        }
        freq_tong_hang[tong_hang]++;
    }

    for (int i = 0; i < n; i++) {
        count += freq_tong_hang[tong_cot[i]];
    }

    std::cout << count << "";
    return 0;
}