/**
 *	author: Lang Dat
 *	create: 26-10-2022 12:46:16
**/
#include <iostream>
#include <vector>
using namespace std;

const int LIM = 1e3 + 3;
int countt[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MUAVE.INP", "r", stdin);
    freopen("./MUAVE.OUT", "w", stdout);

    int n, k, m, tmp;
    std::cin >> n >> k >> m;

    std::vector<int> notFree;
    for (int i = 0; i < n && m; i++) {
        std::cin >> tmp;
        if (tmp <= k) {
            countt[i]++;
            m--;
        } else {
            notFree.push_back(i);
        }
    }

    if (!notFree.empty())
        for (int i = 0; m; i++, m--) {
            countt[notFree[i%notFree.size()]]++;
        }
    for (int i = 0; i < n; i++) {
        std::cout << countt[i] << " ";
    }
    return 0;
}