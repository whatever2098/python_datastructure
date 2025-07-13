#include <iostream>
using namespace std;

int main() {
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	if (arr[0] > arr[1]) {
		int temp = arr[0];  arr[0] = arr[1]; arr[1] = temp;
	}
	if (arr[0] > arr[2]) {
		int temp = arr[0]; arr[0] = arr[2]; arr[2] = temp;
	}
	
	cout << arr[0] << " ";
	(arr[1] < arr[2]) ? cout << arr[1] << " " << arr[2] : cout << arr[2] << " " << arr[1];
	
}