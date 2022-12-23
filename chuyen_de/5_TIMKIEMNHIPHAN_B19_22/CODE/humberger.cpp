/**
 *	author: Lăng Trọng Đạt
 *	create: 19-12-2022 26:11:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR for (int i = 0; i < 3; i++)

int64_t so_luong[3], trong_bep[3], cost[3];
string str;
int64_t money;

bool check(int64_t so_banh) {
    // kiem tra xem co lam duoc n banh hay khong
    int64_t require = 0;
    FOR
        if (so_luong[i]*so_banh > trong_bep[i]) 
            require += (so_luong[i]*so_banh - trong_bep[i]) * cost[i];
            
    return require <= money;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./humberger.OUT", "w", stdout);
    freopen("./humberger.INP", "r", stdin);
    #endif

    cin >> str;
    FOR std::cin >> trong_bep[i];
    FOR std::cin >> cost[i];
    cin >> money;


    for (char c : str)
        if (c == 'B') so_luong[0]++;
        else if (c == 'S') so_luong[1]++;
        else so_luong[2]++;

    int64_t low = 0, high = 2*1e12;
    int64_t best = 0; // số bánh nhiều nhất có thể
    while (low <= high) {
        int64_t mid = (low + high) / 2;
        if (check(mid)) {
            low = mid + 1;
            best = mid;
        } else {
            high = mid - 1;
        }
    }

    std::cout << best << "";
    return 0;
}