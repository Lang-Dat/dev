#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

std::vector<int> biggest;
std::unordered_set<int> soDuocChon;
int max = 0;

void tinhSoUoc(int n) {
    int count = 0;
    for (int i = 1; i <= std::sqrt(n); i++)
        if (n % i == 0 && i * i != n) {
            if (soDuocChon.count(i)) count++;
            if (soDuocChon.count(n / i)) count++;
        }
        else if (n % i == 0 && i * i == n && soDuocChon.count(i))
            count++;

    if (count == max)
        biggest.push_back(n);
    else if (count > max) {
        max = count;
        biggest.clear();
        biggest.push_back(n);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./GAME.INP", "r", stdin);
    freopen("./GAME.OUT", "w", stdout);

    int n, tmp;
    std::cin >> n;
    while(std::cin >> tmp) soDuocChon.insert(tmp);
    for (auto &i : soDuocChon)
        tinhSoUoc(i);
    std::sort(biggest.begin(), biggest.end());
    for (int i : biggest)
        std::cout << i << " ";
    return 0;
}