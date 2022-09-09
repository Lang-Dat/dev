#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

const int LIM = 1e9 + 5;
std::vector<bool> fib(LIM, false);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("FIBO.INP", "r", stdin);
    freopen("FIBO.OUT", "w", stdout);

    fib[0] = true; fib[1] = true;
    int i = 1, j  = 2; // i = 1; j = 2;
    for (int _ = 0; i < LIM && j < LIM; _++) {
        fib[j] = true;
        int temp = j;
        j += i;
        i = temp;
    }
    int num, count = 0;
    while (std::cin >> num)
    {
        if (fib[num]) {
            std::cout << num << " ";
            count++;
        }
    }
    std::cout << "\n" << count;
    

    return 0;
}