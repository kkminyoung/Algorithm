#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int>genres_count;
	vector <pair<string, int>> v;

	// 장르별 재생 횟수
	for (int i = 0; i < genres.size(); i++)
		genres_count[genres[i]] += plays[i];

	// 재생 횟수 기준으로 정렬
	map<string, int>::iterator iter = genres_count.begin();
	for (iter = genres_count.begin(); iter != genres_count.end(); ++iter) 
		v.push_back(make_pair(iter->first, iter->second));
	sort(v.begin(), v.end(), compare); 

	//장르 별, 많이 재생된 두 곡 찾기
	for (int i = 0; i < v.size(); i++) {
		int f = 0; int s = 0; int fn = 0; int sn = 0;
		for (int j = 0; j < genres.size(); j++) {
			if (genres[j] == v[i].first) {
				if (plays[j] > f) {
					s = f;
					sn = fn;
					f = plays[j];
					fn = j;
				}
				else if (plays[j] > s) {
					s = plays[j];
					sn = j;
				}
			}
		}
		//장르에 2개 이상의 곡이 있을 경우에만 앨범에 넣기
		answer.push_back(fn);
		if (s > 0) 
			answer.push_back(sn);
	}
	return answer;
}