#include <iostream>
using namespace std;

int dp[15][15]{ 0 };

int DP(int k, int n) {
	if (dp[k][n] != 0) { return dp[k][n]; }
	if (k == 0) { return dp[0][n] = n; }
	int sum{ 0 };
	for (int i{ 1 }; i <= n; i++) {
		sum += DP(k - 1, i);
	}
	return dp[k][n] = sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	int T;
	cin >> T;

	while (T--) {
		int k, n;
		cin >> k >> n;
		cout << DP(k, n) << "\n";
	}
}