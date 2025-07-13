#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		q.push(i);
	}

	int currentCard;
	while (true) {
		currentCard = q.front();
		q.pop();
		if (q.empty()) break;
		
		currentCard = q.front();
		q.pop();
		q.push(currentCard);
	}

	cout << currentCard << "\n";
}