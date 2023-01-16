/**
 *	author: Lăng Trọng Đạt
 *	create: 31-12-2022 18:24:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./count3.INP", "r", stdin);
    freopen("./count3.OUT", "w", stdout);
    #endif

    int count = 0;
    int n;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i, ones = 0, twos = 0; j < n; j++) {
            (nums[j] == 1) ? ones++ : twos++;
            count += (ones == twos);
        }
    }

    std::cout << count << "";
    return 0;
}