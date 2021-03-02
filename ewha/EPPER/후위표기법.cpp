#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(int m, string input) {
	int answer = 0;

	stack<int> s; 
	
	int size = input.size();
	char token;
	int x, y, z;
	int i = 0;
	
	while(i < size){
		token = input[i];
		
		// 피연산자 : 스택에 담음
		if(token>='0' && token <='9')
			s.push(token-'0');
		// 연산자 : 스택에서 두 개의 연산자를 꺼내서 연산한 뒤에 그 결과를 스택에 담음
		else{
			x = s.top();
			s.pop();
			
			y = s.top();
			s.pop();

			if(token == '+')
				z = y + x;
			else if(token =='-')
				z = y - x;
			else if(token =='*')
				z = y * x;
			else if(token =='/')
				z = y / x;
			
			s.push(z);
		}
		i++;
	}
	// 연산을 마치고 스택에 남아있는게 최종 결과
	answer = s.top();
	
	return answer;
}


int main() {
	int m;
	char str;
  string input="";
	int result; 
	
  cin >> m;
  for(int i=0; i<m; i++){
		cin >> str;
		input += str;
	}
	result = solution(m, input);
	cout << result;

  return 0;
}
