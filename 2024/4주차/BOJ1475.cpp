#include <iostream>
#include <cmath>
using namespace std;

int numbers[10];

int main() {
	string N;
	cin >> N;
	
	for (int i{ 0 }; i < N.length(); i++) {
		numbers[N[i] - '0']++;
	}

	int sets = round((double)(numbers[6] + numbers[9]) / 2);

	for (int i{ 0 }; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		if (sets < numbers[i]) {
			sets = numbers[i];
		}
	}

	cout << sets << "\n";
}