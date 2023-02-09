#include <iostream>
#include <unordered_map>
#include <algorithm>

std::unordered_map<int, int> mp; // mp[i]: dãy cấp số cộng dài nhất với công sai là d kết thúc tại i

int main() {
    freopen("CongSaiD.inp", "r", stdin);
    freopen("CongSaiD.out", "w", stdout);

    int n, d, tmp, ans = 0;
    std::cin >> n >> d;
    while (std::cin >> tmp) {
        mp[tmp] = std::max(mp[tmp], mp[tmp - d] + 1);
        ans = std::max(ans, mp[tmp]);
    }
    std::cout << n - ans;
}
