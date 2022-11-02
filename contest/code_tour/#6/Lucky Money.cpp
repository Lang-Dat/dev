/**
 *	author: Lang Dat
 *	create: 29-10-2022 13:07:21
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ull unsigned long long
const int LIM = 3*1e5;
std::vector<ull> tien;
ull bao[LIM];
ull ans = 0;

void rerange(int start, int n) {
    int end = upper_bound(tien.begin() + start, tien.end(), tien[start]) - tien.begin();
    // db(end, tien[end])
    if (end == start) return;
    std::vector<int> tmp(tien.begin() + start, tien.begin() + end);
    tien.erase(tien.begin() + start, tien.begin() + end);
    
    int ind = upper_bound(tien.begin(), tien.begin() + start, tmp[0]) - tien.begin();
    tien.insert(tien.begin() + ind, tmp.begin(), tmp.end());
    ans++;
    rerange(ind + tmp.size() + 1, tmp.size());
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./Lucky Money.INP", "r", stdin);
    // freopen("./Lucky Money.OUT", "w", stdout);
    tien.reserve(LIM);
    int q, n;
    std::cin >> q;
    while (std::cin >> n) {
        for (int i = 0; i < n; i++)
            std::cin >> bao[i];
        
        int ind = upper_bound(tien.begin(), tien.end(), bao[0]) - tien.begin();
        // db(ind)
        tien.insert(tien.begin() + ind, bao, bao + n);
        ans++;
        // for (int i : tien)
        //     std::cout << i << " ";
        // std::cout << "\n";
        rerange(ind + n + 1, n);
        std::cout << ans << "\n";
    }
    return 0;
}