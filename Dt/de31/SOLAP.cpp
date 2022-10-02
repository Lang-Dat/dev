#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_set>

std::unordered_set<int> s;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SOLAP.INP", "r", stdin);
    freopen("./SOLAP.OUT", "w", stdout);

    int n, tmp;
    std::cin >> n;
    while (std::cin >> tmp)
        if (!s.count(tmp))
            s.insert(tmp);
    std::cout << s.size() << " ";

    return 0;
}