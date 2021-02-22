// cpp 내장함수중 sort 말고 stable_sort를 사용해야함!!!! 기본 sort는 unstable sort 임!!!

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 숫자 위치 찾기
int findNumIdx(const string &str){
    int i;
    for (i = 0; i < str.length(); i++){
        if (str[i] >= '0' && str[i] <= '9')
            break;
    }
    return i;
}

// Number 부분 가져오기
int getNumber(string str){
    return stoi(str.substr( findNumIdx(str) ));
}

// Header 부분 가져오기
string getHeader(string str){
    string rtn = str.substr(0, findNumIdx(str));
    transform(rtn.begin(), rtn.end(), rtn.begin(), ::toupper);

    return rtn;
}

// 헤드 이름 순 정렬
bool headComp(string str1, string str2) { 
    return getHeader(str1).compare(getHeader(str2)) < 0; 
}

// 숫자 순 정렬
bool numComp(string str1, string str2) { 
    return getNumber(str1) < getNumber(str2); 
}


vector<string> solution(vector<string> files){   
    stable_sort(files.begin(), files.end(), numComp);
    stable_sort(files.begin(), files.end(), headComp);

    return files;
}
