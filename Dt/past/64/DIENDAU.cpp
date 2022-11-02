/**
 *	author: Lang Dat
 *	create: 21-10-2022 03:29:19
**/
#include <iostream>
#include <numeric>
using namespace std;

const int LIM = 1e3 + 3;
int nums[LIM];
bool isPositive[LIM];
int n, target, sum = 0;

bool dfs(int pos = 0, int currSum = 0) {
    if (pos == n) {
                // db(currSum, pos, currSum + nums[pos], nums[pos])
        if (2 * currSum  == sum + target) {
            for (int i = 0; i < n; i++) {
                if ((nums[i] < 0 && isPositive[i]) ||
                    (nums[i] > 0 && !isPositive[i])) {
                    std::cout << " - ";
                } else if (i != 0) {
                    std::cout << " + ";
                }
                std::cout << nums[i];
            }
            return true;
        } else {
            return false;
        }
    }
    isPositive[pos] = true;
    if (dfs(pos + 1, currSum + nums[pos])) return true;
    isPositive[pos] = false;
    return dfs(pos + 1, currSum);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DIENDAU.INP", "r", stdin);
    freopen("./DIENDAU.OUT", "w", stdout);

    std::cin >> n >> target;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        sum += nums[i];
    }
    if ((sum + target) % 2 == 1) {
        std::cout << 0;
        return 0;
    }
    if (!dfs()) {
        std::cout << "0";
    }
    return 0;
}