#include <iostream>
using namespace std;

int cards[101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i{ 1 }; i <= N;i++) {
		cin >> cards[i];
	}
	
	int result{ 0 };
	int sum{ 0 };
	for (int i{ 1 }; i <= N; i++) {
		sum += cards[i];
		for (int j{ 1 }; j <= N; j++) {
			if (i == j) continue;
			sum += cards[j];
			if (sum > M) { sum -= cards[j]; continue; }
			for (int k{ 1 }; k <= N; k++) {
				if (i == k || j == k) continue;
				sum += cards[k];
				if (M - sum >= 0 && sum > result) result = sum;
				sum -= cards[k];        //브루트포스 -> 모든 경우 다 조사하는지 인덱싱 확실히 재검토
			}
			sum -= cards[j];
		}
		sum -= cards[i];
	}
	cout << result << "\n";
}