/**
 *	author: Lang Dat
 *	create: 26-10-2022 44:23:09
**/
#include <iostream>
using namespace std;

const int LIM = 1e6 + 6;
int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MASACH.INP", "r", stdin);
    freopen("./MASACH.OUT", "w", stdout);

    int n, tmp, best = 0, type;
    std::cin >> n;
    while (std::cin >> tmp) {
        freq[tmp]++;
        if (freq[tmp] > best || (freq[tmp] == best && tmp < type)) {
            best = freq[tmp];
            type = tmp;
        }
    }
    std::cout << type << " " << best;
    return 0;
}