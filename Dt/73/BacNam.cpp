/**
 *	author: Lang Dat
 *	create: 23-10-2022 14:27:10
**/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int process(std::vector<int> &nums) {
    int num_of_circle = 0;
    std::unordered_set<int> prev;
    for (int i : nums) {
        if (!prev.count(i - 2)) {
            num_of_circle++;
        } 
        prev.insert(i);
    }
    return num_of_circle;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BacNam.INP", "r", stdin);
    // freopen("./BacNam.OUT", "w", stdout);

    int n, tmp;
    std::vector<int> chan, le;
    std::cin >> n;
    chan.reserve(n / 2);
    le.reserve(n / 2);
    while (std::cin >> tmp) {
        if (tmp % 2 == 0) {
            chan.push_back(tmp);
        } else {
            le.push_back(tmp);
        }
    }
    std::cout << process(le) << "\n";
    std::cout << process(chan);
    return 0;
}