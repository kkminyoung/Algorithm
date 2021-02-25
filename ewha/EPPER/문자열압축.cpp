#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string s) {
	string answer="";
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	int count = 0;
	int i=0;
	while(i<s.size()){
		if(s[i]==s[i+1])
			count++;
		else{
			if(s[i]==1)
				answer+="1";
			answer+=alpha[count];
			count =0;
		}

		i++;
	}
	return answer;
}

int main() {
	string s;
	string answer;

	cin >> s;
	answer = solution(s);
	cout << answer;

	return 0;
}
