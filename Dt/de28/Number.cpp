#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
using std::pow;

void find(int n) {
    if (n <= 9) {
        std::cout << n << "\n";
        return;
    }
    int numOfDigit = 1;
    while (n > 9 * pow(10, numOfDigit-1) * numOfDigit) {
        n -= 9 * pow(10, numOfDigit-1) * numOfDigit;
        numOfDigit++;
    }
    // su dung float de tranh bug trong ham pow (vi du: (int)pow(10, 2) = 99 :)))
    int soCuoi = (int)(n / numOfDigit);

    n -= soCuoi*numOfDigit;
    
    if (n < numOfDigit && n != 0) soCuoi++;
    
    soCuoi += pow(10, numOfDigit-1) + 0.1f - 1;
    
    if (soCuoi == pow(10, numOfDigit) + 0.1f)
        numOfDigit++;
    if (n != 0)
        soCuoi /= pow(10, numOfDigit-n);
    std::cout << (int)soCuoi % 10 << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./Number.INP", "r", stdin);
    freopen("./Number.OUT", "w", stdout);

    int n;
    std::cin >> n;
    find(n);

    return 0;
}