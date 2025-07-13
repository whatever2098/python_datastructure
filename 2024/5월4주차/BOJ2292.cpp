#include <iostream>
#include <vector>
using namespace std;

vector<bool> dp;  //���� Ǯ�̹� �����ϱ�

int Dp(long long n) {
	if (n <= 0) return dp.size();

	int size = dp.size();
	/*long long lastNumOfGroup{ dp.back() + 6 * size };
	dp.push_back(lastNumOfGroup);*/
	dp.push_back(1);
	return Dp(n - 6 * size);
}

int main() {
	//1(1��)   2-7(6)(2��)   8-19(12)(3��)   20-37(18)(4��)   38-61(24)(5��)
	long long N;
	cin >> N;
	dp.push_back(1);
	//N == 1 + 6*1 + 6*2 + 6*3 + 6*4 + ...+6*n  (n+1��)
	cout << Dp(N - 1) << "\n";
}