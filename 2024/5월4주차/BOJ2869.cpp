#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long A, B, V;
	cin >> A >> B >> V;

	cout << (long long)(ceil((V - A) / (long double)(A - B))) + 1 << "\n";  //ceil시 double이므로 정수계산시 형변환 필요
}