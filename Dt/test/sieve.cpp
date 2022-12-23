#include <iostream>
#include <vector>
#include <cstring>
const int LIM = 3 * 1e6;


// Checks whether x is prime or composite
bool ifnotPrime(int prime[], int x)
{
	// checking whether the value of element
	// is set or not. Using prime[x/64], we find
	// the slot in prime array. To find the bit
	// number, we divide x by 2 and take its mod
	// with 32.
	return (prime[x/64] & (1 << ((x >> 1) & 31)));
}

// Marks x composite in prime[]
bool makeComposite(int prime[], int x)
{
	// Set a bit corresponding to given element.
	// Using prime[x/64], we find the slot in prime
	// array. To find the bit number, we divide x
	// by 2 and take its mod with 32.
	prime[x/64] |= (1 << ((x >> 1) & 31));
}

// Prints all prime numbers smaller than n.
void bitWiseSieve(int n)
{
    Timer timer;
	// Assuming that n takes 32 bits, we reduce
	// size to n/64 from n/2.
	int prime[n/64];

	// Initializing values to 0 .
	memset(prime, 0, sizeof(prime));

	// 2 is the only even prime so we can ignore that
	// loop starts from 3 as we have used in sieve of
	// Eratosthenes .
	for (int i = 3; i * i <= n; i += 2) {

		// If i is prime, mark all its multiples as
		// composite
		if (!ifnotPrime(prime, i))
			for (int j = i * i, k = i << 1; j < n; j += k)
				makeComposite(prime, j);
	}

	// // writing 2 separately
	// printf("2 ");

	// // Printing other primes
	// for (int i = 3; i <= n; i += 2)
	// 	if (!ifnotPrime(prime, i))
	// 		printf("%d ", i);
}

// Driver code
 
void normalSieve(int n)
{
    // Timer timer;
    // prime[i] is going to store true if
    // if i*2 + 1 is composite.
    bool prime[n/2];
	memset(prime, 0, sizeof(prime));
	// std::vector<int> prime(n/2, false);
 
    // 2 is the only even prime so we can
    // ignore that. Loop starts from 3.
    for (int i=3 ; i*i < n; i+=2)
    {
        // If i is prime, mark all its
        // multiples as composite
        if (prime[i/2] == 0)
            for (int j=i*i; j<n; j+=i*2)
                prime[j/2] = 1;
    }
 
    // writing 2 separately
    // printf("2 ");
 
    // // Printing other primes
    for (int i=3; i<n ; i+=2)
        if (prime[i/2] == false)
			std::cout << i << " ";
    // std::cout << "\nNormal sieve: ";
}
void sieve(int n) {
	// Timer time;
	std::vector<short> prime((n + 1) / 2, true);
	for (int i = 3; i * i <= n; i += 2)
		if (prime[i / 2])
			for (int j = i * i; j <= n; j += i*2)
				prime[j / 2] = false;
	// for (int i = 3; i <= n; i += 2)
	// 	if (prime[i/2])
	// 		std::cout << i << " ";
}
int main()
{
	int n = 1e5;
	// std::cin >> n;
	// bitWiseSieve(LIM);
    normalSieve(n);
	// sieve(n);
	return 0;
}
