#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

map<int, int> numbers;

/*
* <����� ���� sort �ϴ� ��>
* 1. bool ��ȯ �Լ� ����
* 2. [](,)->bool{} ���� ���
* 3. class ������ operator< �������̵�
*/
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) { return a.first < b.first; }
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	long long sum{ 0 };

	for (int i{ 0 }; i < N; i++) {
		int integer;
		cin >> integer;

		sum += integer;

		if (numbers.find(integer) == numbers.end()) { numbers[integer] = 1; continue; }   //������׷� ���� ���� map ��� (key ��������  ����, find ����) 
		numbers[integer]++;
	}

	/*
	* <�Ҽ� n��° �ڸ����� �ݿø� �ϴ� ��>
	* n��° �ڸ� == �Ҽ��� ù°�ڸ� �� ������ *10    pow(10, )
	* 0.5���Ͽ� floor�ϱ�
	* �ٽ� �� �ڸ����� /10
	*/
	cout << floor(sum / (double)N + 0.5) << "\n";    

	int cnt{ 0 };
	int mid;
	for (auto num : numbers) {
		cnt += num.second;
		if (cnt >= N / 2 + 1) { mid = num.first; break; }
	}
	cout << mid << "\n";

	vector<pair<int, int>> numbers_(numbers.begin(), numbers.end());  //map -> vector (indexing�� resorting�� ����)
	int min = numbers_[0].first;
	int max = numbers_[numbers_.size() - 1].first;     //vector�� indexing�� ����.

   	sort(numbers_.begin(), numbers_.end(), compare);  //vector�� ����ڰ� �����ϴ� �������� resort
	//sort(numbers_.begin(), numbers_.end(), [](pair<int, int>& a, pair<int, int>& b)->bool{ if(a.second == b.second){return a.first > b.first;} return a.second > b.second;})
	cout << ((numbers_.size() == 1)? numbers_[0].first : (numbers_[0].second == numbers_[1].second) ? numbers_[1].first : numbers_[0].first);
	cout << "\n";
	
	cout << max - min << "\n";
}