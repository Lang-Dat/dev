#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

std::vector<int> sums;
std::vector<int> splitPoints;

bool isVaild(int first, int last, int val) {
    splitPoints.push_back(first+1);
    int tmp = first;
    for (int i = tmp + 1; i < last; i++) {
        if (sums[i] - sums[tmp] == val) {
            splitPoints.push_back(i + 1);
            tmp = i;
        }
    }
    if (sums[last] - sums[splitPoints.back()-1] == val) {
        splitPoints.push_back(last + 1);
        return true;
    }
    else {splitPoints.clear(); return false;}
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    int n, tmp;
    std::cin >> n;
    sums.resize(n+1);
    sums[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        sums[i] = sums[i-1] + tmp;
    }

    for (int first = 1, last = n - 1; first < last;) {
        if (sums[first] > sums[n] - sums[last]) last--;
        else if (sums[first] < sums[n] - sums[last]) first++;
        else if (sums[first] == sums[n] - sums[last] && isVaild(first, last, sums[first])) {
            std::cout << 1 << " ";
            for (int i : splitPoints)
                std::cout << i << " ";
            return 0;
        }
        else first++;
    }
    std::cout << 1;
    return 0;
}