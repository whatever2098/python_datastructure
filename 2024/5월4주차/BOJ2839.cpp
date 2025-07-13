#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int result{ 5000 };
	for (int i{ N / 5 }; i >= 0; i--) {
		for (int j{ (N - i * 5) / 3 }; j >= 0; j--) {
			if (5 * i + 3 * j == N && i + j < result) { result = i + j; }
			if (5 * i + 3 * j < N) break;
		}
	}

	cout << ((result == 5000) ? -1 : result) << "\n";  //삼항연산자 사용시 괄호 꼭!
}