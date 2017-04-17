// Sieve of Eratosthenes
// Κόσκινον Ἐρατοσθένους

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool* sieve_eratosthenes(int n) {
	// true is prime, false is composite
	// sieve[0] and sieve[1] are wasted, but whatever
	bool* sieve = new bool[n];
	fill_n(sieve, n, true);

	// Enumerate i from 2 to floor(sqrt(n))
	for (int i = 2; i*i <= n; i++) {
		// If i is prime, mark its multiples as composite
		if (sieve[i]) {
			// Optimization: start from i^2 instead of i*2
			for (int j = i*i; j <= n; j += i) {
				sieve[j] = false;
			}
		}
	}

	return sieve;
}

int main(int argc, const char *argv[]) {
	int n = argc > 1 ? atoi(argv[1]) : 100;
	
	bool* sieve = sieve_eratosthenes(n);

	// Output primes
	cout << "Primes from 2 to " << n << ": " << endl;
	for (int i = 2; i <= n; i++) {
		if (sieve[i]) {
			cout << i << " ";
		}
	}
	
	return 0;
}
