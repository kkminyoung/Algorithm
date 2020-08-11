#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_func(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> s;

	for (auto num : numbers)
		s.push_back(to_string(num));
	
	// compare function을 이용하여 정렬!!!
	sort(s.begin(), s.end(), compare_func);

	if (s.at(0) == "0")
		return "0";
	for (auto num : s)
		answer += num;

	return answer;

}