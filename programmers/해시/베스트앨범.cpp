#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<pair <string, int>> hash;
	vector<pair <int, string>> temp;
	vector<pair <int, int>> max;

	// �帣, ���Ƚ���� pair�� ����, vec�� ����
	for (int i = 0; i < genres.size(); i++)
		hash.push_back(make_pair(genres[i], plays[i]));

	// �� �帣 �ȿ��� plays �� ����
	for (int i = 0; i < genres.size(); i++) {
		temp.push_back(make_pair(plays[i], genres[i]));
		for (int j = i + 1; j < genres.size(); j++) {
			if (genres[i] == genres[j]) {
				temp[i].first += plays[j];
				genres.erase(genres.begin() + j);
				plays.erase(plays.begin() + j);
				j--;
			}
		}
	}

	// plays ������� ����
	sort(temp.begin(), temp.end(), greater<pair<int, string>>());

	// answer�� �ű��
	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < hash.size(); j++) {
			if (temp[i].second == hash[j].first)
				max.push_back(make_pair(hash[j].second, j));
		}
		sort(max.begin(), max.end(), greater<pair<int, int>>());
		if (max.size() >= 2) {
			if (max[0].first == max[1].first) {
				answer.push_back(max[1].second);
				answer.push_back(max[0].second);
			}
			else {
				answer.push_back(max[0].second);
				answer.push_back(max[1].second);
			}
		}
		else {
			answer.push_back(max[0].second);
		}
		max.clear();
	}


	return answer;
}