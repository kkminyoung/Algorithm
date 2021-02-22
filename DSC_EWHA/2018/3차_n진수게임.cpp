#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string dict = "0123456789ABCDEF";
    
    // 진법에 맞춰 순서대로 저장
    string save = "";
    for(int i=0; i<m*t+1; i++){
        string temp = "";
        int num = i;
        
        if(num == 0)
            temp = "0";
        while(num > 0){
            temp += dict[num % n];
            num /= n;
        }
        reverse(temp.begin(), temp.end());
        
        save += temp;
        
    }
    
    // 저장해논 곳에서 본인 차례만 answer에 저장
    for(int i=0; i<t; i++)
        answer += save[m*i+p-1];

    

    
    return answer;
}


 
