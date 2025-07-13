#include <iostream>
#include <vector>
using namespace std;

vector<bool> dp;  //쉬운 풀이법 생각하기

int Dp(long long n) {
	if (n <= 0) return dp.size();

	int size = dp.size();
	/*long long lastNumOfGroup{ dp.back() + 6 * size };
	dp.push_back(lastNumOfGroup);*/
	dp.push_back(1);
	return Dp(n - 6 * size);
}

int main() {
	//1(1개)   2-7(6)(2개)   8-19(12)(3개)   20-37(18)(4개)   38-61(24)(5개)
	long long N;
	cin >> N;
	dp.push_back(1);
	//N == 1 + 6*1 + 6*2 + 6*3 + 6*4 + ...+6*n  (n+1개)
	cout << Dp(N - 1) << "\n";
}