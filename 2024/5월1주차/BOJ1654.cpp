#include <iostream>
#include <set>
using namespace std;

multiset<int> lens;
int N;

bool canBeNlen(int Nlen) {
	int cnt{ 0 };
	//O(K)
	for (int len : lens) {
		if (len < Nlen) continue;
		cnt += len / Nlen;
	}
	return (cnt >= N) ? true : false;
}

int main() { //평균에서 --해가는 방법: 평균이 최대 2^31-1일 수 있으므로 10억번의 연산 필요...
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int K;
	cin >> K >> N;  
	//K==N일 때 들어온 길이가 모두 2^31-1이어야 N의 길이가 2^31-1일 수 있음. 
	//[1(T) ~ 2^31-1(F)] / 2를 검사
	//If(T) => [(1(T) ~ 2^31-1(F)] / 2)(T) ~ 2^31-1(F)] / 2를 검사
	//If(F) => [1(T) ~ (1(T) ~ 2^31-1(F)] / 2)(F)] / 2를 검사
	//O(log2 n)
	for (int i{ 0 }; i < K; i++) {
		int len;
		cin >> len;
		lens.insert(len);
	}
	int upper{ *(--lens.end()) };
	int lower{ 0 };
	int Nlen = (K == N && *lens.begin() == upper) ? upper : upper / 2;
	
	while (!(canBeNlen(Nlen) && !canBeNlen(Nlen + 1))) {
		if (canBeNlen(Nlen)) { lower = Nlen; }
		else { upper = Nlen; }
		Nlen = lower + (upper - lower) / 2;
	}
	cout << Nlen << "\n";
}