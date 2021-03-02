#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 예약을 정렬하는 기준
bool compare(const pair<int,int> &m1, const pair<int,int> &m2) { 
	// 정렬 기준은 끝나는 시간을 기준으로 오름차순, 끝나는 시간이 같다면 시작 시간을 기준으로 오름차순
	if(m1.second == m2.second) 
		return m1.first < m2.first;
	else 
		return m1.second < m2.second;
}

int solution(vector<int> s, vector<int> e, int N){
	int answer = 0;
	int e1 = -1, e2 = -1;
	
	// v = 시작 시간, 끝나는 시간을 담은 벡터
	vector<pair<int,int>> v;
	for(int i=0; i<N; i++)
		v.push_back(make_pair(s[i], e[i]));
	
	// 앞서 정의한 기준으로 정렬
	sort(v.begin(), v.end(), compare);
	
	for(int i = 0 ; i < N; i++){
		// 1번자리 비어있으면
		if(e1 <= v[i].first) {
			e1 = v[i].second;
			answer++;
		}
		// 2번자리 비어있으면
		else if(e2 <= v[i].first) {
			e2 = e1;
			e1 = v[i].second;
			answer++;
		}
	}

	return answer;
}

int main() {
	vector<int> s;
	vector<int> e;
	int N;

	cin >> N;
	int temp;
	for(int i=0; i<N; i++){
		cin >> temp;
		s.push_back(temp);
	}
	
	for(int i=0; i<N; i++){
		cin >> temp;
		e.push_back(temp);
	}
	
	cout << solution(s, e, N);
	
	return 0;
}
