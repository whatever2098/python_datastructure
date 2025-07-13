#include<iostream>
#include<algorithm>
using namespace std;

long long A[100'000];

bool binarySearch(int lower, int upper, long long search) {
	if (lower >= upper || search < A[lower] || search > A[upper] ) return false;
	int mid = (lower + upper) / 2;
	if (search == A[mid]) return true;
	else if (search > A[mid]) { lower = mid + 1; }
	else { upper = mid; }
	return binarySearch(lower, upper, search);  //return해야됨 주의
}

/*bool binarySearch(int lower, int upper, long long search) {
	while (upper >= lower) {
		int mid = (lower + upper) / 2;
		if (search == A[mid]) return true;
		else if (search < A[mid]) { upper = mid - 1; }   
		else { lower = mid + 1; }
	}
	return false;
}*/

int main() {
	ios_base::sync_with_stdio(0);      //입력 많을 시 시간복잡도 위해 반드시 필요
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);  //O(NlogN)
	cin >> M;
	while (M--) {  //O(MlogN)
		long long b;
		cin >> b;
		cout << ((b == A[N-1])? 1 : (binarySearch(0, N-1, b)) ? 1 : 0) << '\n';
	}
}