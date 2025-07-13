#include <iostream>
using namespace std;

int cntfib{ 1 };
int cntfibonacci{ 0 };
int cntfibDpRec{ 0 };

int fib(int n) {
	if (n == 1 || n == 2) return 1;
	cntfib++;  //n번째 규칙찾아보기
	return fib(n - 1) + fib(n - 2);
}

int f[41]{ 0 };
int fibonacci(int n) {
	f[1] = f[2] = 1;
	for (int i{ 3 }; i <= n; i++) {
		cntfibonacci++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int fibDpRec(int n) {
	if (f[n]) return f[n];
	if (n == 1 || n == 2) { return f[n] = 1; }
	cntfibDpRec++;
	return f[n] = fibDpRec(n - 1) + fibDpRec(n - 2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	fib(n);
	//fibonacci(n);
	fibDpRec(n);
	cout << cntfib << " " << cntfibDpRec << "\n";
}