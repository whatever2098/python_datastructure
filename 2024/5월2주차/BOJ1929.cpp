#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;
	for (int i{ 2 }; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
		/*int approxOfDivNByI = (n + (i - (n % i))) / i;
		if (approxOfDivNByI < maxDivisor) { maxDivisor = approxOfDivNByI; }*/
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int M, N;
	cin >> M >> N;
	for (int i{ M }; i <= N; i++) {
		if (isPrime(i)) {
			cout << i << "\n";
		}
	}
}