#include <iostream>
using namespace std;

int tri[3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		cin >> tri[0] >> tri[1] >> tri[2];
		if (tri[0] == 0) { break; }   //== ��� ���޾� �� �� ����!

		//tri[0]�� ���� �׻� max
		if (tri[1] > tri[0]) { swap(tri[0], tri[1]); }
		if (tri[2] > tri[0]) { swap(tri[0], tri[2]); }

		cout << ((tri[1] * tri[1] + tri[2] * tri[2] == tri[0] * tri[0]) ? "right" : "wrong") << "\n";
	}
}