#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int max{ 0 };
	int sum{ 0 };
	for (int i{ 0 }; i < N; i++) {
		int score;
		cin >> score;
		sum += score;
		if (score > max) { max = score; }
	}
	cout << float(sum * 100) / float(max * N);


}