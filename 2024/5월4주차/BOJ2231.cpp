#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	//한자리 9->18 두자리 99->117 세자리 999->1026 네자리 9999->10035
	//최대 (100000 - 9*5) ~999999 => 1000000 - 99955 개 탐색 => 완전탐색
	//질문:naive한 방식으로 6 * 1'000'000 = 6백만 왜 시간초과가 날까?
	
	//자릿수
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