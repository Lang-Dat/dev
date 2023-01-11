/**
 *	author: Lang Dat
 *	create: 29-10-2022 07:13:16
**/
#include <iostream>
#include <unordered_set>
using namespace std;

const int MOD = 13051984;
std::unordered_set<int> bi_hong;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./STEP.INP", "r", stdin);
    freopen("./STEP.OUT", "w", stdout);

    int n, k, hong;
    std::cin >> n >> k;

    for (int i = 0; i < k; i++) {
        std::cin >> hong;
        bi_hong.insert(hong);
    }
    int prev = 1, curr = 2;

    if (bi_hong.count(1)) {
        prev = 0, curr = 1;
    }
    if (bi_hong.count(2)) {
        curr = 0;
    }
    for (int i = 3; i <= n; i++) {
        if (bi_hong.count(i)) {
            prev = curr;
            curr = 0;
        } else {
            int tmp = curr;
            curr = (curr + prev) % MOD;
            prev = tmp;
        }
    }    

    std::cout << curr % MOD << "";
    return 0;
}