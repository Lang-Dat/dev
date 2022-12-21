/**
 *	author: Lăng Trọng Đạt
 *	create: 21-12-2022 18:57:19
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./HOUSE.INP", "r", stdin);
    freopen("./HOUSE.OUT", "w", stdout);
    #endif

    int n;
    std::string str;

    std::cin >> n >> str;

    int count = 0;
    bool is_prev_chance = false;
    for (int i = 1; i < n; i++) {
        if (str[i] == str[i-1] and !is_prev_chance) {
            count++;
            is_prev_chance = true;
        } else {
            is_prev_chance = false;
        }
    }

    std::cout << count << "";

    return 0;
}