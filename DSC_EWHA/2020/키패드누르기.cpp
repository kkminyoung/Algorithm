#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 인덱스 찾아내는 함수
vector<int> get_index(int num){
    vector<int> idx;
    if(num==0)
        idx={3,1};
    else
        idx={(num-1)/3,(num+2)%3};
    return idx;
}

// 작은거리 찾아내는 함수
string get_Sdist(vector<int> left, vector<int> mid, vector<int> right, string hand){
    int left_dist = abs(left[0]-mid[0]) + abs(left[1]-mid[1]);
    int right_dist = abs(right[0]-mid[0]) + abs(right[1]-mid[1]);
    
    if(left_dist<right_dist)
        return "left";
    else if(left_dist>right_dist)
        return "right";
    else
        return hand;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    vector<int> left_curr={3,0};
    vector<int> right_curr={3,2};

    for(int i=0; i<numbers.size(); i++){
        vector<int> idx = get_index(numbers[i]);
        
        //왼쪽패드
        if (idx[1]==0){
            left_curr = idx;
            answer+="L";
        }
        //오른쪽패드
        else if(idx[1]==2){
            right_curr = idx;
            answer+="R";
        }
        // 중간에 있는 경우
        else{
            //최소거리 찾음
            string where = get_Sdist(left_curr,idx,right_curr,hand);
            
            if(where=="left"){
                answer+="L";
                left_curr=idx;
            }
            else if(where=="right"){
                answer+="R";
                right_curr=idx;
            }
                
            
        }
            
        
        
    }
    
    
    return answer;
}
