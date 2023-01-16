/**
 *	author: Lăng Trọng Đạt
 *	create: 26-12-2022 12:28:22
**/
#include <iostream>
#include <algorithm>
using namespace std;

// static const int LIM = 2*1e5 + 2;
static const int LIM = 17;
static int a[LIM], b[LIM];
static int diff[LIM];
int n;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DISAN.INP", "r", stdin);
    freopen("./DISAN.OUT", "w", stdout);
    #endif

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        diff[i] = a[i] - b[i];
    }
    
    sort(diff, diff + n);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        int ind = (upper_bound(diff + i + 1, diff + n, -diff[i]) - diff);
        count += n - ind;
    }

    std::cout << count << "";
    return 0;
}