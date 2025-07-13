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

int main() { //��տ��� --�ذ��� ���: ����� �ִ� 2^31-1�� �� �����Ƿ� 10����� ���� �ʿ�...
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int K;
	cin >> K >> N;  
	//K==N�� �� ���� ���̰� ��� 2^31-1�̾�� N�� ���̰� 2^31-1�� �� ����. 
	//[1(T) ~ 2^31-1(F)] / 2�� �˻�
	//If(T) => [(1(T) ~ 2^31-1(F)] / 2)(T) ~ 2^31-1(F)] / 2�� �˻�
	//If(F) => [1(T) ~ (1(T) ~ 2^31-1(F)] / 2)(F)] / 2�� �˻�
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