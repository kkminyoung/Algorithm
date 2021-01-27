#include <string>
#include <vector>
#include <stack>

using namespace std;

// 올바른 괄호 문자열인지 체크
bool check(string u){
    stack<int> s;
    for(int i=0; i<u.size(); i++){
        if(u[i]=='(')
            s.push(i);
        else if(u[i]==')'){
            if(s.empty()==true)
                return false;
            else
                s.pop();
        }
    }
    return true;
}

// 변환
string change(string p){
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if(p.size()==0)
        return "";
    
    //2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
    string u;
    string v;
    int left_count = 0;
    int right_count = 0;
    for(int i=0; i<p.size();i++){
        if(p[i]=='(')
            left_count++;
        else if(p[i]==')')
            right_count++;
        
        
        if(left_count == right_count){
            u=p.substr(0,i+1);
            v=p.substr(i+1,p.size());
            break;
        }
    }
    
    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
    if(check(u)){
        v = change(v);
        return u+v; // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
    }
    else{ // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
        string temp = "("; // 4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        v = change(v);     // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        temp += v; 
        temp += ')';       // 4-3. ')'를 다시 붙입니다. 
        
        // 4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        string new_u="";
        for(int i=1; i<u.size()-1; i++){
            if(u[i]=='(')
                new_u += ')';
            else if(u[i]==')')
                new_u += '(';
        }
        temp+=new_u;
        return temp; //   4-5. 생성된 문자열을 반환합니다.
    }
    
}


string solution(string p) {
    string answer = change(p);

    return answer;
}
