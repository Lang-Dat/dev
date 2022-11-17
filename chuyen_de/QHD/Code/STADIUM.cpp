/**
 *	author: Lang Dat
 *	create: 17-11-2022 22:45:13
**/
#include <iostream>
#include <algorithm>
using namespace std;

struct Client {
    int money = 0, start = - 1, end = -1;
    int maxValue = 0; // số tiền lớn nhất có được nếu chọn người này
};
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./STADIUM.INP", "r", stdin);
    freopen("./STADIUM.OUT", "w", stdout);
    #endif

    int n, best = 0;
    std::cin >> n;
    Client c[n]; // c:clients 
    for (int i = 0; i < n; i++) {
        std::cin >> c[i].start >> c[i].end >> c[i].money;
        c[i].maxValue = c[i].money;
    }
    
    sort(c, c + n, [](Client &a, Client &b) -> bool {
        if (a.end != b.end) return a.end < b.end;
        return a.start > b.start;
    });

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (c[i].start > c[j].end) {
                c[i].maxValue = max(c[i].maxValue, c[j].maxValue + c[i].money);
            }
        }
        best = max(best, c[i].maxValue);
    }
    std::cout << best << "";
    return 0;
}