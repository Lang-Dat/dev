/**
 *	author: Lang Dat
 *	create: 13-11-2022 06:35:19
**/
#include <iostream>
using namespace std;

static const int LIM = 1e6 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BONUS.INP", "r", stdin);
    freopen("./BONUS.OUT", "w", stdout);
    #endif

    int n, sum = 0;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i, min_ = nums[i], max_ = nums[i]; j < n; j++) {
            if (nums[j] < min_) {
                min_ = nums[j];
            } else if (nums[j] > max_) {
                max_ = nums[j];
            }
            sum += max_ - min_;
        }
    }
    std::cout << sum << "";
    return 0;
}