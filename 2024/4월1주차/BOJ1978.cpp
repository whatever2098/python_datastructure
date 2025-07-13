#include <iostream>
using namespace std;

int main() {
	int n;
	int cnt{ 0 };
	cin >> n;
	while (n--) {
		int num;
		bool isPrime{ true }; //에라토스테네스의 체
		cin >> num;
		if (num == 1) { continue; }
		for (int i{ 2 }; i < num; i++) {
			if (num % i == 0) { isPrime = false; }
		}
		if (isPrime) { cnt++; }
	}
	cout << cnt << "\n";
}