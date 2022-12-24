/**
 *	author: Lăng Trọng Đạt
 *	create: 24-12-2022 04:19:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int prev_pos[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CROSS.INP", "r", stdin);
    freopen("./CROSS.OUT", "w", stdout);
    #endif

    int n, id;
    
    int pos;
    std::cin >> n;
    // db(n)
    int64_t count = 0;
    while (std::cin >> id >> pos) {
        pos++;
        if (prev_pos[id] + pos == 3) count++;
        prev_pos[id] = pos;
    }

    std::cout << count << "";

    return 0;
}