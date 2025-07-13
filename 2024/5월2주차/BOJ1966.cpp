#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct object {
	int num;
	int importance;
};

struct compare {
	bool operator()(object a, object b) {
		///return 
	}
};
priority_queue<int> pq;  //priority_queue<자료형, 구조체, 우선순위(언제 swap 할 것인가)> ex)<int, vector<int>, greater<int>> =>작은int부터
                         //기본이 최대힙(완전 이진 트리 구조)

queue<object> q;
int maxies[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		while (!q.empty()) q.pop();
		while (!pq.empty())pq.pop();

		int N, M;
		cin >> N >> M;
		for (int i{ 0 }; i < N; i++) {
			int importance;
			cin >> importance;
			q.push({ i, importance });
			maxies[i] = importance;
			pq.push(importance);
		}
		sort(maxies, maxies + N, greater<>());  //(원소시작메모리, 원소끝메모리+1, 순서) 순서는 기본 오름차순, 알파벳 순서. greater<>()시 내림차순(큰 것부터 정렬)
		
		int orderPrinted{ 0 };
		int front{ 0 };
		while (!q.empty()) {
			object obj = q.front();
			q.pop();
			if (obj.importance < pq.top()) {
				q.push(obj);
				continue;
			}
			orderPrinted++;
			front++;
			pq.pop();
			if (obj.num == M) {
				cout << orderPrinted << "\n";
				break;
			}
		}
	}
} //시간복잡도??