#include<bits/stdc++.h>
using namespace std;
// The function to find x^n in O(log n) time.......
int mod_exp(int x, int n, int m) {
	// If x is greater than m then take its modulo
	x = x % m;
	int res = 1; //It is going to be our final result
	while (n > 0) {
		if (n & 1) { // If n is odd then multiply res by x;
			res = (res * x) % m;
		}
		n = n >> 1; // n=n/2;
		x = (x * x) % m;
		// The order of flow is like if we want to find  a^6 then a^6=(a^2)^3 so we make a=a*a then (a^2)^3=(a^2)^2 * a^2 and so one ....
	}
	return res;
}

// The function to determine gcd of two numbers using eucledian method
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

// This function is to perform extended euclidean algorithm
/*The idea is to solve A*x +B*y = GCD(A,B) and find x,y
	This works as A=B(quotient) +remiander(r); -(1)
				  B=r(quotient) +remiander; and then we works upwards
*/
int gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return d;
}

// The function below give the solution of the general equation :
// a.x+b.y=c (for general integral solution)linear diophantine equation
bool find_any_solution(int a, int b, int c, int &x, int &y, int &g) {
	g = gcd(abs(a), abs(b), x, y);
	if (c % g) {
		return false;
	}
	x *= c / g;
	y *= c / g;
	if (a < 0) x *= -1;
	if (y < 0) y *= -1;
	return true;
}

// This function is the implementation of the sieve of Eratosthenes... O(n (loglog n))
int N = 10 + 7;
bool isPrime[N + 1];
void sieve() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i * i < N + 1; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j < N + 1; j += i) {
				isPrime[j] = 0;
			}
		}
	}
}

// This function helps to find the factorisation of all the numbers between 2:n(n<1e7)
// Although the time complexity of this function is better than the naive sieve
// (O(n (ln(ln(n))))) but in practice the runtime of both of the algorithm is simillar
const int N;
int lp[N + 1]; // lp[i] stores the smallest prime divisor of the number i;
vector<int> p;// it stores all the primes smaller than i;
void extSieve() {
	memset(lp, 0, sizeof(lp));
	for (int i = 2; i < N + 1; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			p.push_back(i);
		}
		for (int j = 0; j < p.size() && p[j] <= lp[i] && i * p[j] <= N; i++) {
			lp[i * p[j]] = p[j];
		}
	}
}

// The function is the eulers totient function which return the number of coprimes
// smaller than the given number : Time Complexity( O(√n))
int phi(int n) {
	int result = n;
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0) {
			while (n % i == 0) { n /= i;}
			result -= result / i;
		}
	}
	if (n > 1) {
		result -= result / n;
	}
	return result;
}

// If you want the totient of every number between 2-n then the above algo is not
// optimised as the time complexity would be O(n√n) where the time complexity
// of the below algo is O(n*loglogn)
vector<int> optphi(int n) {
	vector<int> tot(n + 1);
	for (int i = 0; i < n + 1; i++) {
		tot[i] = i;
	}
	for (int i = 2; i < n + 1; i++) {
		if (tot[i] == i) {
			for (int j = i; j < n + 1; j += i) {
				tot[j] -= tot[j] / i;
			}
		}
	}
}

// The function below return the modulo inverse of the number
int modInv(int n, int m) {
	int x, y;
	int g = gcd(n, m, x, y);
	if (g != 1) {
		return -1;
	}
	return (x % m + m) % m;
}

// The function below return the modulo inverse of the number using totient function phi
int modInv(int n, int m, vector<int> phi) {
	return mod_exp(n, phi[m] - 1, m);
}

