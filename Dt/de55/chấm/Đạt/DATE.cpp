#pragma GCC optimize("O2")
#include <iostream>
#include <set>

const std::set<int> baMuoiNgay = {4, 6, 9, 11};
const std::set<int> baMotNgay = {1, 3, 5, 7, 8, 10, 12};
bool isVaild(int d, int m, int y) {
    if (m > 12 || d < 0 || d > 31) return false;
    if (y % 4 == 0 && m == 2 && d > 29)
        return false;
    else if (y % 4 != 0 && m == 2 && d > 28)
        return false;

    else if (baMuoiNgay.count(m) && d > 30)
        return false;

    else if (baMotNgay.count(m) && d > 31) return false;
    
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("DATE.INP", "r", stdin);
    // freopen("../../de55/Botest/DATE/Test02/DATE.INP", "r", stdin);
    freopen("DATE.OUT", "w", stdout);

    int n, d, m, y;
    std::cin >> n;
    while(n--) {
        std::cin >> d >> m >> y;
        if (isVaild(d, m, y))
            std::cout << "TRUE\n";
        else
            std::cout << "FALSE\n";
    }

    return 0;
}