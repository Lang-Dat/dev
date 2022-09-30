#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long

struct Client {
    ull start = 0, end = 0;
    int cost = 0;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    int n;
    std::cin >> n;
    Client clients[n];
    for (int i = 0; i < n; i++)
        std::cin >> clients[i].start >> clients[i].end >> clients[i].cost;

    std::sort(clients, clients + n, [](Client c1, Client c2) -> bool {
        return c1.end < c2.end;
    });

    std::vector<int> count(n, 1);
    ull max = 0, soKhach = 0;
    for (int i = 0; i < n; i++) {
        ull c = clients[i].cost;
        for (int j = 0; j < i; j++)
            if (clients[i].start > clients[j].end && 
                clients[j].cost + c > clients[i].cost) {
                clients[i].cost = clients[j].cost + c;
                count[i] = count[j] + 1;
            }
        if (clients[i].cost > max) {
            max = clients[i].cost;
            soKhach = count[i];
        }
    }
    std::cout << soKhach << " " << max;
    return 0;
}