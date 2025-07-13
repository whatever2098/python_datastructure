#include <iostream>
using namespace std;

int bowls[101];
int N, M;

int main() {
	cin >> N >> M;
	
	for (int i{ 1 }; i <= N; i++) {
		bowls[i] = i;
	}

	while (M--) {
		int i, j;
		cin >> i >> j;
		swap(bowls[i], bowls[j]);
	}

	for (int i{ 1 }; i <= N;i++) {
		cout << bowls[i] << " ";
	}
}