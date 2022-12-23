/**
 *	author: Lăng Trọng Đạt
 *	create: 20-12-2022 32:00:18
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int nam[LIM], nu[LIM];
bool is_take[LIM];

int counting(int *low, int *high, int low_start, int low_end, int high_start, int high_end) {
    int count = 0;
    for (int i = low_start, j = high_end; i <= low_end; i++) {
        while (j >= high_start and high[j] >= std::abs(low[i]))
            j--;
        if (j >= high_start) {
            count++;
            j--;
        }
    }

    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DANCING.OUT", "w", stdout);
    freopen("./DANCING.INP", "r", stdin);
    #endif

    int n;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nam[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> nu[i];
    }
    sort(nam, nam + n);
    sort(nu, nu + n);

    int s_nam = lower_bound(nam, nam + n, 0) - nam, // điểm mà nam[s_nam] >= 0
        s_nu = lower_bound(nu, nu + n, 0) - nu;
    int count = 0;
    if (s_nam > 0 and s_nu < n)
        count += counting(nam, nu, 0, s_nam - 1, s_nu, n - 1);
    
    if (s_nam < n and s_nu > 0)
        count += counting(nu, nam, 0, s_nu - 1, s_nam, n - 1);

    std::cout << count << "";
    return 0;
}