#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <unordered_set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NT.INP", "r", stdin);
    freopen("./NT.OUT", "w", stdout);

    int N, M;
    while (std::cin >> N >> M)
    {
        std::unordered_set<int> nt;
        for (int i = 2; i <= std::sqrt(N); i++) {
            if (N % i == 0) nt.insert(i);
            while (N % i == 0)
                N /= i;
        }
        if (N > 1) nt.insert(N);
        for (int i = 2; i <= std::sqrt(M); i++) {
            if (M % i == 0 && nt.count(i)) nt.erase(i);
            else if (M % i == 0 && !nt.count(i)) {
                std::cout << "No" << "\n";
                goto cnt;
            }
            while(M % i == 0)
                M /= i;
        }
        if (M > 1 && nt.count(M)) nt.erase(M);
        else if (M > 1 && !nt.count(M)) {
            std::cout << "No" << "\n";
            goto cnt;
        }
         
        if (nt.empty()) std::cout << "Yes" << "\n";
        else std::cout << "No" << "\n"; 
        cnt:;
    }
    

    return 0;
}