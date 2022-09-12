#pragma GCC optimize("O2")
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>

using std::vector;

const int LIM = 1e9 + 5;
vector<bool> primes(LIM, true);

void sieveOfEratosthenes(int length, vector<bool> &tmp) {
    for (int p = 2; p < length; p++) {
        if (tmp[p]) {
            for (int i = p * p; i < length; i += p) {
                tmp[i] = false;
                primes[i] = false;
            }
        }
    }
}

void segmentSieve() {
    int length = floor(std::sqrt(LIM)) + 1;
    vector<bool> tmp(length, true);
    sieveOfEratosthenes(length, tmp);

    unsigned int low = length, high = 2 * length;

    while (low < LIM)
    {
        if (high > LIM) high = LIM;
        for (int i = 2; i < length; i++) {
            if (tmp[i]) {
                int lowLimit = floor(low / i) * i;
                if (lowLimit < i)
                    lowLimit += i;
                
                for (int j = lowLimit; j < high; j += i)
                    primes[j] = false;
            }
        }
        low += length;
        high += length;
    }
    

    for (int i = 0; i < LIM; i++) {
        if (primes[i]) std::cout << 1;
        else std::cout << 0;
    }
}  

int main()
{
    Timer time;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("./test.out", "w", stdout);
    segmentSieve();
    std::cout << "\n";
    return 0;
}