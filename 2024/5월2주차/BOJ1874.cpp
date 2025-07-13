#include <iostream>
#include <vector>
using namespace std;

vector<int> stack;
vector<string> cals;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int a;
	int i{ 1 };
	while(n--) {
		cin >> a;
		while (stack.empty() || stack.back() < a) {
			stack.push_back(i);
			cals.push_back("+");
			++i;
		}
		stack.pop_back();
		cals.push_back("-");
	}
	if (stack.empty()) {
		for (string cal : cals) { cout << cal << '\n'; }
		return 0;
	}
	cout << "NO" << '\n';
}