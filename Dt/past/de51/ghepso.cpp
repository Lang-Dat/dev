#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> ans;
std::vector<int> number; // single digits

bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
int v_to_int(std::vector<int> number) {
    // convert vector contain single digit to integer
    int num = 0;
    for (int i : number) {
        num = num * 10 + i;
    }
    return num;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ghepso.INP", "r", stdin);
    freopen("./ghepso.OUT", "w", stdout);

    int n, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        number.push_back(tmp);
    }

    std::sort(number.begin(), number.end());
    do
    {
        int num = v_to_int(number);
        if (isPrime(num)) {
            ans.push_back(num);
        }
    } while (std::next_permutation(number.begin(), number.end()));

    if (ans.size() == 0) {
        std::cout << "-1";
    } else {
        for (int i : ans) {
            std::cout << i << "\n";
        }
    } 
    return 0;
}