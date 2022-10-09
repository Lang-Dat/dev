#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DLN.INP", "r", stdin);
    // freopen("./TEST/DLN/TEST12/DLN.INP", "r", stdin);
    freopen("./DLN.OUT", "w", stdout);

    int n, best_count = 0;
    std::string str, best = "";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> str;
        int count = 0;
        for (char c : str)
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                count++;
        if (count > best_count) {
            best = str;
            best_count = count;
        }
    }
    std::cout << best;
    return 0;
}