#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	//���ڸ� 9->18 ���ڸ� 99->117 ���ڸ� 999->1026 ���ڸ� 9999->10035
	//�ִ� (100000 - 9*5) ~999999 => 1000000 - 99955 �� Ž�� => ����Ž��
	//����:naive�� ������� 6 * 1'000'000 = 6�鸸 �� �ð��ʰ��� ����?
	
	//�ڸ���
	int digits{ (int)(to_string(N).length()) };  //1024  10^2~1024   973~1024
	int begin{ (int)pow(10, digits - 1) - 9 * (digits - 1) };
	for (int i{ begin }; i < N; i++) {
		int sum{ i };
		for (char c : to_string(i)) {
			sum += (int)(c - '0');
		}
		if (sum == N) { cout << i << "\n"; return 0; }
	}
	cout << 0 << "\n";
}