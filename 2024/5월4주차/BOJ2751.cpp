#include <iostream>
#include <set>
using namespace std;

set<int> st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		int n;
		cin >> n;
		st.insert(n);
	}
	
	for (auto i{ st.begin() }; i != st.end();i++) {
		cout << *i << "\n";
	}
}