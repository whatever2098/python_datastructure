#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b, int gcd) {
	return a * b / gcd;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;

	int g = gcd(a, b);
	cout << g << "\n";

	cout << lcm(a, b, g) << "\n";
}