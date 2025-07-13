#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		string e;
		getline(cin, e, '.');  //<string>�� getline.  <istream>�� cin.getline(e, 101, '.')
		cin.ignore();

		if (e == "") break;

		for (auto it{ e.begin() }; it != e.end();it++) {
			if (*it == '(' || *it == '[') {
				s.push(*it); 
				/*for (++it; *it == ' '; it++) {
					s.push(' ');
				}
				it--;*/
				continue;
			}
			if (*it == ')' || *it == ']') {
				/*for (auto itBlank{ it - 1 }; *itBlank == ' ' && !s.empty(); itBlank--) {
					s.pop();
				}*/
				if (s.empty()) { s.push(*it); break; }
				
				if (*it == ')' && s.top() == '(') { s.pop(); continue; }
				if (*it == ']' && s.top() == '[') { s.pop(); continue; }

				s.push(*it); break;
			}
		}
		
		cout << ((s.empty())? "yes": "no") << "\n";//���� ��ȣ�� ������ ��쵵 ���
		while (!s.empty()) { s.pop(); }
	}
}