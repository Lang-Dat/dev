/**
 *	author: Lang Dat
 *	create: 07-11-2022 29:46:07
**/
#include <iostream>
using namespace std;

const int LIM = 1e4 + 5;
int freq[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./QUAYSO.INP", "r", stdin);
    freopen("./QUAYSO.OUT", "w", stdout);
    #endif

    int n, tmp, best = 0, id;
    std::cin >> n;
    while (std::cin >> tmp) {
        freq[tmp]++;
        if (freq[tmp] > best) {
            best = freq[tmp];
            id = tmp;
        }
    }
    std::cout << id << "";
    return 0;
}