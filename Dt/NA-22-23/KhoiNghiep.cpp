/**
 *	author: Lang Dat
 *	create: 23-10-2022 00:41:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

struct Company {
    int request, cost;
    int id;
};
// const int LIM = 2*1e5 + 5;
const int LIM = 5;
Company request_s[LIM], cost_s[LIM]; // sorted array according to the request and cost
bool isCooperate[LIM];
int n;
int now = 0; // so cong ty da hop tac
int min_cost = 0, pos = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KhoiNghiep.INP", "r", stdin);
    freopen("./KhoiNghiep.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> request_s[i].request >> request_s[i].cost;
    }
    
    sort(request_s, request_s + n, [](Company &a, Company &b) -> bool {
        return a.request < b.request;
    });
    for (int i = 0; i < n; i++) {
        request_s[i].id = i;
        cost_s[i] = request_s[i];
    }
    sort(cost_s, cost_s + n, [](Company &a, Company &b) -> bool {
        return a.cost < b.cost;
    });

    for (Company c : request_s) {
        if (isCooperate[c.id]) continue;
        if (now < c.request) {
            while (isCooperate[cost_s[pos].id]) {
                pos++;
            }           
            min_cost += cost_s[pos].cost;
            isCooperate[cost_s[pos].id] = true;
        }
        now++;
        isCooperate[c.id] = true;
    }
    std::cout << min_cost;
    return 0;
}