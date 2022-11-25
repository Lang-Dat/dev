/**
 *	author: Lang Dat
 *	create: 18-11-2022 31:36:19
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 2*1e6 + 4;
int tong_uoc[LIM];

void tinh_tong_uoc() {
    for (int i = 1; i < LIM; i++) {
        for (int j = 1; j * i < LIM; j++)
            tong_uoc[i*j] += i;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SORT.INP", "r", stdin);
    freopen("./SORT.OUT", "w", stdout);
    #endif

    tinh_tong_uoc();
    std::vector<int> ans;
    int n, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        if (tong_uoc[tmp] == 2 * tmp) {
            ans.push_back(tmp);
        }
    }    
    sort(ans.begin(), ans.end());
    for (int i : ans)
        std::cout << i << " ";
    return 0;
}