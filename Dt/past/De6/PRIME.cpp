#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

bool isPalindrome(int n) {
    int rev = 0, tmp = n;
    while (tmp > 0)
    {
        rev = rev*10 + tmp%10;
        tmp /= 10;
    }
    return rev == n;
}

bool isPrime(int n) {
    if (n <= 3) return n >1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("PRIME.INP", "r", stdin);
    freopen("PRIME.OUT", "w", stdout);

    int A, B, count = 0;;
    std::cin >> A >> B;

    int primes[93] = {10301,10501,10601,11311,11411,12421,12721,12821,13331,13831,13931,14341,14741,15451,15551,16061,16361,16561,16661,17471,17971,18181,18481,19391,19891,19991,30103,30203,30403,30703,30803,31013,31513,32323,32423,33533,34543,34843,35053,35153,35353,35753,36263,36563,37273,37573,38083,38183,38783,39293,70207,70507,70607,71317,71917,72227,72727,73037,73237,73637,74047,74747,75557,76367,76667,77377,77477,77977,78487,78787,78887,79397,79697,79997,90709,91019,93139,93239,93739,94049,94349,94649,94849,94949,95959,96269,96469,96769,97379,97579,97879,98389,98689};
    // for (int i = A; i <= B; i++) {
    //     if (isPrime(i) && isPalindrome(i)) {
    //         std::cout << i << ",";   
    //         count++;
    //     }
    // }
    for (int i = 0; i < 93 && primes[i] <= B; i++)
        if (primes[i] >= A)
            count++;
    std::cout << count;
    return 0;
}