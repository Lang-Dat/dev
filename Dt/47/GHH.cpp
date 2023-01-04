/**
 *	author: Lăng Trọng Đạt
 *	create: 04-01-2023 23:55:07
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

std::vector<int> ans;
static const int LIM = 1e6 + 5;
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
    freopen("./GHH.INP", "r", stdin);
    freopen("./GHH.OUT", "w", stdout);
    #endif

    tinh_tong_uoc();

    int n, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        if (2*tmp <= tong_uoc[tmp])
            ans.push_back(tmp);
    }    

    std::cout << ans.size() << "\n";
    for (int i : ans)
        std::cout << i << "\n";

    return 0;
}