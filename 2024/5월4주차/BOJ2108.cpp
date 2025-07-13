#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

map<int, int> numbers;

/*
* <사용자 지정 sort 하는 법>
* 1. bool 반환 함수 정의
* 2. [](,)->bool{} 람다 사용
* 3. class 내에서 operator< 오버라이딩
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

		if (numbers.find(integer) == numbers.end()) { numbers[integer] = 1; continue; }   //히스토그램 정리 위해 map 사용 (key 오름차순  정렬, find 가능) 
		numbers[integer]++;
	}

	/*
	* <소수 n번째 자리에서 반올림 하는 법>
	* n번째 자리 == 소수점 첫째자리 될 때까지 *10    pow(10, )
	* 0.5더하여 floor하기
	* 다시 그 자리까지 /10
	*/
	cout << floor(sum / (double)N + 0.5) << "\n";    

	int cnt{ 0 };
	int mid;
	for (auto num : numbers) {
		cnt += num.second;
		if (cnt >= N / 2 + 1) { mid = num.first; break; }
	}
	cout << mid << "\n";

	vector<pair<int, int>> numbers_(numbers.begin(), numbers.end());  //map -> vector (indexing과 resorting을 위해)
	int min = numbers_[0].first;
	int max = numbers_[numbers_.size() - 1].first;     //vector가 indexing이 편함.

   	sort(numbers_.begin(), numbers_.end(), compare);  //vector로 사용자가 정의하는 기준으로 resort
	//sort(numbers_.begin(), numbers_.end(), [](pair<int, int>& a, pair<int, int>& b)->bool{ if(a.second == b.second){return a.first > b.first;} return a.second > b.second;})
	cout << ((numbers_.size() == 1)? numbers_[0].first : (numbers_[0].second == numbers_[1].second) ? numbers_[1].first : numbers_[0].first);
	cout << "\n";
	
	cout << max - min << "\n";
}