/**
 *	author: Lăng Trọng Đạt
 *	create: 17-12-2022 54:19:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 150;
static int nums[LIM];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("NGHICHTHE1.INP", "r", stdin);
    // freopen("../../../chuyen_de/3_MANG_B7_15/array1D_1/NGHICHTHE1/test2/NGHICHTHE1.INP", "r", stdin);
    freopen("./NGHICHTHE1.OUT", "w", stdout);
    #endif 

    int n;
    std::cin >> n;
    // int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < i; j++)
            if (nums[j] > nums[i])
                count++;

        std::cout << count << " ";
    }
    return 0;
}