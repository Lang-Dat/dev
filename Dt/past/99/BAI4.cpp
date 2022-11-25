/**
 *	author: Lang Dat
 *	create: 20-11-2022 25:25:11
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long
struct Client
{
    ull start, end, cost = -1;
    ull max_val = 0, count = 1;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    Client c[n]; // clients
    for (int i = 0; i < n; i++) {
        std::cin >> c[i].start >> c[i].end >> c[i].cost;
        c[i].max_val = c[i].cost;
    }
    
    sort(c, c + n, [](Client &a, Client &b) -> bool {
        return a.end < b.end;
    });
    
    int best = 0, count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (c[j].end < c[i].start && 
                c[j].max_val + c[i].cost > c[i].max_val) {
                c[i].max_val = c[j].max_val + c[i].cost;
                c[i].count   = c[j].count + 1;
            }
        }
        if (c[i].max_val > best) {
            best = c[i].max_val;
            count = c[i].count;
        }
    }
    std::cout << count << " " << best;
    return 0;
}