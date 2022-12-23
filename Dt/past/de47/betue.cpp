#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

const int LIM = 3*1e5;
int so_qua[LIM];
int n, m, sum = 0, best = 0;

void recursion(int start = 0) {
    int diem_roi = sum / n;
    for (; start < m; start++, n--) {
        if (so_qua[start] <= diem_roi) {
            sum -= so_qua[start];
        } else {
            so_qua[start] -= diem_roi;
            sum -= diem_roi;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./betue.INP", "r", stdin);
    freopen("./betue.OUT", "w", stdout);

    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> so_qua[i];
        sum += so_qua[i];
    }
    std::sort(so_qua, so_qua + m);
    
    return 0;
}