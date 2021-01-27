// 원형큐 방식으로 풀어보려 했으나 실패
// 안되는 풀이.. permutation 방식으로 풀 것임

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    
    sort(dist.begin(), dist.end(), greater<>());

    vector<int> remain = weak;
    vector<int> temp_remain;
    vector<int> r ;


    // 많이 움직일 수 있는 애부터 하나씩 점검함
    for(int i=0; i<dist.size(); i++){
        cout<< "i:" << i << endl;
        int max = 0 ;
        int start = 0 ;
        r = remain;
        
        // 출발지점 한칸씩 돌려가며 완전탐색
        for(int j=0; j<n; j++){
            temp_remain = r;
            
            int count = 0;
            for(int k=0; k<=dist[i];k++){
                int c = (j+k)%n; // 원형태로 변경
                for(int w=0; w<temp_remain.size();w++){
                    if(temp_remain[w]==c){
                        count++;
                        temp_remain[w]= -1;
                        //cout << "count: " << count << endl;
                        //cout << "index: " << c << w <<endl;
                    }
                }   
            }
            // 가장 많이 품어가는 놈
            if(count>max){
                max = count;
                remain = temp_remain;
            }
        }
        
        
        int flag = 0;
        for(int j=0; j<remain.size(); j++){
            if(remain[j]!=-1){
                cout << remain[j];
                flag=1;
            }
        }
        
        if(flag==0){
            answer = i+1;
            break;
        }
        

    }
    

    return answer;
}
