/**
 *	author : Lăng Trọng Đạt
 *	creater: 02-02-2023 19:43:34
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

std::unordered_map<int, int> pos = {{0, -1}};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./chiahet7.INP", "r", stdin);
    freopen("./chiahet7.OUT", "w", stdout);

    int n, tmp, best = 0;
    std::cin >> n;
    for (int i = 0, curr_sum = 0; i < n; i++) {
        std::cin >> tmp;
        curr_sum = (curr_sum + tmp) % 7;
        if (pos.count(curr_sum))
            best = max(i - pos[curr_sum], best);
        else 
            pos[curr_sum] = i;
    }

    std::cout << best << "";

    return 0;
}