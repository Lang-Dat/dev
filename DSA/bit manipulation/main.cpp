#include <iostream>
#include <bitset>

int main()
{   
    std::bitset<64> n;
    int i;
    std::cin >> i;
    n = 1LL << i;
    logl(n);
    logl(n.to_ullong());
}