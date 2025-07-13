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
priority_queue<int> pq;  //priority_queue<�ڷ���, ����ü, �켱����(���� swap �� ���ΰ�)> ex)<int, vector<int>, greater<int>> =>����int����
                         //�⺻�� �ִ���(���� ���� Ʈ�� ����)

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
		sort(maxies, maxies + N, greater<>());  //(���ҽ��۸޸�, ���ҳ��޸�+1, ����) ������ �⺻ ��������, ���ĺ� ����. greater<>()�� ��������(ū �ͺ��� ����)
		
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
} //�ð����⵵??