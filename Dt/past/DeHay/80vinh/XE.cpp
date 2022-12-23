/**
 *	author: Lang Dat
 *	create: 27-10-2022 22:22:07
**/
#include <iostream>
using namespace std;

const int LIM = 10109999 - 10101111 + 10;
int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./XE.INP", "r", stdin);
    freopen("./XE.OUT", "w", stdout);

    int n, tmp, sum = 0;
    std::cin >> n;
    while (std::cin >> tmp)
        freq[tmp-10101111]++;

    for (int i : freq) {
        if (i > 0) {
            sum += 100;
        }
        if (i > 5)
            sum += i - 5;
    }

    std::cout << sum << "";
    return 0;
}