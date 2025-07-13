#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	int sum = 0;
	for (int i = 1; i <= T; i++) {
		int pow5 = i;
		int cnt = 0;
		while (pow5 % 5 == 0) {//pow5
			pow5 /= 5;
			cnt++;
		}
		if (cnt != 0) { sum += cnt; }
	}
	cout << sum;
}