#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    // 2의 제곱수 만들어놓음
    vector<int> two;
    for(int i=0; i<n; i++){
        two.push_back(pow(2,i));
    }
    
    // #, " " 저장
    string temp;
    for(int i=0; i<n; i++){
        temp="";
        for(int j=n-1; j>=0; j--){
            if(arr1[i]/two[j] ==1 || arr2[i]/two[j]==1)
                temp+="#";
            else
                temp+=" ";
            
            
            if(arr1[i]/two[j] ==1)
                arr1[i] = arr1[i]-two[j];
            
            if(arr2[i]/two[j] ==1)
                arr2[i] = arr2[i]-two[j];
            
        }
        answer.push_back(temp);
    }
    
    
    return answer;
}
