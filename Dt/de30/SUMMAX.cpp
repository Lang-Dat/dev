#pragma GCC optimize("O2")
#include <iostream>

int rev(int n, int &sum) {
    int tmp = 0;
    while (n > 0) {
        sum += n % 10;
        tmp = tmp * 10 + n % 10;
        n /= 10;
    }
    return tmp;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SUMMAX.INP", "r", stdin);
    freopen("./SUMMAX.OUT", "w", stdout);

    int n, maxDigitSum = 0, tmp, best;
    std::cin >> n;
    int reverses[n];
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        int sum = 0;
        reverses[i] = rev(tmp, sum);
        if (sum > maxDigitSum) {
            maxDigitSum = sum;
            best = tmp;
        }
    }
    std::cout << best << "\n";
    for (int i : reverses)
        std::cout << i << " ";

    return 0;
}