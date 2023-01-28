/**
 *	author : Lăng Trọng Đạt
 *	creater: 28-01-2023 08:02:11
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 5e3 + 5;
static int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DENMAU.INP", "r", stdin);
    freopen("./DENMAU/test01/DENMAU.INP", "r", stdin);
    freopen("./DENMAU.OUT", "w", stdout);
    #endif

    int n, tmp;
    int maximum = -1;
    std::vector<int> groups;
    std::cin >> n;
    while (std::cin >> tmp) {
        if (groups.empty() or tmp != groups.back()) {
            groups.push_back(tmp);
            freq[tmp]++;
            maximum = max(maximum, freq[tmp]);
        }
    }

    db(groups.size(), maximum);
    std::cout << groups.size() - maximum << "";
    return 0;
}