#include <iostream>
#include <vector>
#include <unordered_map>

void solve(int case_i)
{
    short N, K, temp;
    std::cin >> N >> K;
    // std::vector<int> S(N); // style
    std::unordered_map<short, short> count;
    for (int i = 0; i < N; i++) {
        // std::cin >> S[i];
        std::cin >> temp;
        count[temp]++;
    }
    
    if (2 * K < N) {
        std::cout << "Case #" << case_i << ": " << "NO\n";
        return;
    }
    
    for (auto &p : count) {
        if (p.second > 2) {
            std::cout << "Case #" << case_i << ": " << "NO\n";
            return;
        }
    }
    std::cout << "Case #" << case_i << ": " << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("in.inp", "r", stdin);
    freopen("in.out", "w", stdout);

    int T;
    std::cin >> T;
    // log(T);
    for (int i = 1; i <= T; i++) {
        solve(i);
        // log(i);
    }    

    return 0;
}