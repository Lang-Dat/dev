/**
 *	author : Lăng Trọng Đạt
 *	creater: 27-01-2023 19:31:05
**/
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);
    #endif

    int p, q;
    std::cin >> p >> q;

    std::cout << (p / q) << "";
    p %= q;
    
    if (p != 0) std::cout << ".";
    
    std::unordered_set<int> seen;
    string decimal_part = "";
    
    while (!seen.count(p) and p != 0)
    {
        seen.insert(p);
        p *= 10;
        decimal_part += p / q + '0';
        p = p % q;
        // db(p, decimal_part)
    } 

    if (seen.count(p)) {
        p *= 10;
        for (char c : decimal_part) {
            if (c - '0' == p / q)
                std::cout << "(";
            std::cout << c << "";
        }
        std::cout << ")";
    } else {
        std::cout << decimal_part << "";
    }
    return 0; 
}