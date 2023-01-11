/**
 *	author: Lang Dat
 *	create: 29-10-2022 16:27:15
**/
#include <iostream>
using namespace std;

const int LIM = 100*10000 + 10;
int can_be_cnt[100][LIM];
int nums[100];
bool inclu[100];
int n, target;

bool dfs(int pos = 0, int sum = 0) {
    if (pos == n) {
        if (sum == target) {
            std::cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (inclu[i])
                    std::cout << i + 1 << " ";
            }
            return true;
        } 
        return false;
    }
    if (can_be_cnt[pos][sum] == -1) 
        return false;
    inclu[pos] = true;
    if (dfs(pos + 1, sum + nums[pos])) {
        return true;
    } else {
        can_be_cnt[pos][sum + nums[pos]] = -1;
    }
    inclu[pos] = false;
    if (dfs(pos + 1, sum)) {
        return true;
    } else {
        can_be_cnt[pos][sum] = -1;
    }
    return false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SUMS.INP", "r", stdin);
    freopen("./SUMS.OUT", "w", stdout);

    std::cin >> n >> target;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    if (!dfs())
        std::cout << "NO";
    return 0;
}