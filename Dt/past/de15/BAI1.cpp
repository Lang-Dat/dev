#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 10109999 - 10102010 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    int n, tmp, sum = 0;
    std::cin >> n;
    while(std::cin >> tmp)
        nums[tmp - 10102010]++;    
    for (int i : nums)
        if (i > 0 && i <= 5) sum += 100;
        else if (i > 5) sum += 100 + i - 5;

    std::cout << sum;
    return 0;
}