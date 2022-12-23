/**
 *	author: Lang Dat
 *	create: 16.10.2022 02.59.07
**/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    
    string str;
    std::cin >> str;

    for (int i = 0; i < k; i++) {
        string tmp(n, '#');
        for (int i = 0; i < str.size(); i++) {
            tmp[nums[i] - 1] = str[i];
        }
        str = tmp;
    }
    std::cout << str    ;
    return 0;
}