#include <iostream>
#include <deque> // 덱 사용하는 문제
#include <string>

using namespace std;

int main() {
	int N;
	deque<int> dq;

	// 입력
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i) {
		string text;
		getline(cin, text);

		// front
		if (text == "front") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.front() << "\n";
		}

		// back
		else if (text == "back") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.back() << "\n";
		}

		// push
		else if (text[1] == 'u') {
			string backup = text;
			//push_front
			if (text[5] == 'f') { 
				int x = stoi(backup.erase(0, 10));
				dq.push_front(x);
			}
			// push_back
			else { 
				int x = stoi(backup.erase(0, 9));
				dq.push_back(x);
			}
		}


		else if (text[1] == 'o') {
			if (text[4] == 'f') {
				if (dq.empty()) cout << -1 << "\n";
				else {
					cout << dq.front() << "\n";
					dq.pop_front();
				}
			}
			else {
				if (dq.empty()) cout << -1 << "\n";
				else {
					cout << dq.back() << "\n";
					dq.pop_back();
				}
			}
		}

		// size 반환
		else if (text == "size")
			cout << dq.size() << "\n";

		// empty
		else if (text == "empty") {
			if (dq.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}

	return 0;
}