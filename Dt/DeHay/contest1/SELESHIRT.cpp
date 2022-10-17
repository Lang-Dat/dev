/**
 *	author: Lang Dat
 *	create: 15.10.2022 03.11.20
 *	[17-10-2022 19:56:20] Bug: nếu thằng nào đó mà không tìm đc áo thì duyệt cho đến khi mô nó tìm đc hoặc là áo đó không thể mặc thì mới cho thằng khác
 O(3*NlogN + N + M)
**/
#include <iostream>
#include <algorithm>
using namespace std;

struct Value {
    int index = 0, val = 0;
    int aoDatDuoc = -1;
};

bool cmp(Value a, Value b) {
        return a.val < b.val;
}
const int LIM = 1e5 + 5;
Value hs[LIM], ao[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SELESHIRT.INP", "r", stdin);
    freopen("./SELESHIRT.OUT", "w", stdout);

    int n, m, x, y, tmp;
    std::cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        hs[i].val = tmp;
        hs[i].index = i;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> tmp;
        ao[i].val = tmp;
        ao[i].index = i;
    }

    sort(hs, hs + n, cmp);
    sort(ao, ao + m, cmp);

    // for (int i = 0; i < n; i++) {
    //     std::cout << hs[i].val << " ";
    // }
    int j = 0;
    int so_hs_nhan_ao = 0;
    for (int i = 0; i < n; i++) {
        for (; j < m;) { 
            if (ao[j].val < hs[i].val - x) j++;
            else if (ao[j].val > hs[i].val + y) break;
            else {
                hs[i].aoDatDuoc = ao[j].index;
                so_hs_nhan_ao++;
                j++;
                break;
            }
        }
    }
    sort(hs, hs + n, [](Value a, Value b) -> bool {
        return a.index < b.index;
    });
    std::cout << so_hs_nhan_ao << "\n";
    for (int i = 0; i < n; i++) {
        if (hs[i].aoDatDuoc != -1) {
            std::cout << hs[i].index + 1 << " " << hs[i].aoDatDuoc + 1 << "\n";
        }
    }
    return 0;
}