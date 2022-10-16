/**
 *	author: Lang Dat
 *	create: 16-10-2022 06:30:12
**/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);

    int N, M, K, tmp, count = 0;
    std::vector<int> khChiaHet;
    std::cin >> N >> K >> M;
    while (std::cin >> tmp) {
        if (tmp % M == 0) {
            if (K - tmp / M >= 0) {
                K -= tmp / M;
                count += tmp / M - 1;
            } else {
                count += K;
                std::cout << count;
                return 0;
            }
        } else if (tmp > M) {
            khChiaHet.push_back(tmp);
        }
    }
    for (int i = 0; i < khChiaHet.size() && K > 0; i++) {
        if (K - khChiaHet[i] / M >= 0) {
            count += khChiaHet[i] / M;
            K -= khChiaHet[i] / M;
        } else {
            count += K;
            break;
        }
    }
    if (K >= 0) std::cout << count;
    else std::cout << "-1";
    return 0;
}