#include <iostream>
using namespace std;

int main() {
	int nums[100001] = { -1,1,-1,2,1,3,2,4,3 };
	int n;
	cin >> n;
	for (int i = 4;i < 99995;i++) nums[i + 5] = nums[i] + 1;
	cout << nums[n - 1];
	return 0;
}