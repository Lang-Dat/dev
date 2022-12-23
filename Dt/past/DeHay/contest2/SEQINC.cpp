/**
 *	author: Lang Dat
 *	create: 23-10-2022 13:27:07
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SEQINC.INP", "r", stdin);
    freopen("./SEQINC.OUT", "w", stdout);

    ull n, q, prevSum = 0, so_chan = 0, so_le = 0, type, add, tmp;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        prevSum += tmp;
        (tmp % 2 == 0) ? so_chan++ : so_le++;
    }
    while (std::cin >> type >> add) {
        if (type == 0) {
            prevSum += add * so_chan;
            std::cout << prevSum << "\n";
            if (add % 2 == 1) {
                so_le += so_chan;
                so_chan = 0;
            }           
        } else if (type == 1) {
            prevSum += add * so_le;
            std::cout << prevSum << "\n";
            if (add % 2 == 1) {
                so_chan += so_le;
                so_le = 0;
            }           
        }
    }
    return 0;
}