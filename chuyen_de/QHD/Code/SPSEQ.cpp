/**
 *	author: Lang Dat
 *	create: 14-11-2022 25:15:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
int nums[LIM], incre[LIM], decre[LIM];
// incre: ĐỘ DÀI DÃY TĂNG DẦN DÀI NHẤT KẾT THÚC TẠI i;
// decre: ĐỘ DÀI DÃY giảm DẦN DÀI NHẤT KẾT THÚC TẠI i;
// 25
// 642 399 341 768 198 921 641 129 765 508 831 137 655 89 215 500 838 853 760 120 211 878 205 102 747 
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SPSEQ.INP", "r", stdin);
    freopen("./SPSEQ.OUT", "w", stdout);
    #endif
    int n, best = 0;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        incre[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                incre[i] = max(incre[j] + 1, incre[i]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        decre[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (nums[j] < nums[i]) {
                decre[i] = max(decre[i], decre[j] + 1);
            }
        }
    }
    for (int i = 0; i < n; i++)
        std::cout << incre[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << decre[i] << " ";
    // 1 2 3 2 1 2 3 4 3 2 1 5 4 1 2 3 2 2 2
    // 1 1 2 3 3 3 4 1 3 2 1 4 3 4 5 5 6 6 4 2 5 6 7 3 4 5 2 6 6 8 6 6 7 9 8 6 7 8 2 9 10 7 10 3 10 10 11 9 12 13 6 12 11 12 10 13 14 14 13 14 3 6 11 15 13 2 15 11 16 4 8 17 14 11 11 18 9 17 16 15 18 19 20 
    // 6 5 6 14 13 12 13 3 10 5 1 12 5 9 10 9 11 10 5 4 8 9 10 4 4 4 3 8 7 10 6 5 8 10 9 4 4 5 2 5 9 4 7 3 6 5 8 4 9 9 3 8 6 6 3 7 8 7 6 6 2 2 5 6 5 1 5 4 5 1 1 5 4 3 2 4 1 3 2 1 1 1 1
    for (int i = 0; i < n; i++) {
        if ((incre[i] + decre[i]) % 2 == 0) {
            best = max(best, incre[i] + decre[i] - 1);
        }
    }
    std::cout << best << "";
    return 0;
}