/**
 *	author: Lăng Trọng Đạt
 *	create: 26-12-2022 12:28:22
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2*1e5 + 2;
static int a[LIM], b[LIM];
int n;

int bruce_force() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            count += (a[i] + a[j] > b[i] + b[j]);
        }
    }

    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DISAN.INP", "r", stdin);
    freopen("./DISAN_trau.OUT", "w", stdout);
    #endif

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    

    std::cout << bruce_force() << "";
    return 0;
}