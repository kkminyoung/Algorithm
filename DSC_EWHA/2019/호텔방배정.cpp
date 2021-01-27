#include <string>
#include <vector>
#include <map>
using namespace std;
 
map<long long, long long> room;

// 배정할 방 찾는 함수 - 원하는 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방을 배정
long long find_room(long long N){
    // 비어있으면 할당해줌
    if (room[N] == 0) 
        return N;
    return room[N] = find_room(room[N]); // 안 비어있으면 계속 find
}
 
vector<long long> solution(long long k, vector<long long> room_number){
    vector<long long> answer;
    
    for (int i = 0; i< room_number.size(); i++){
        long long num = room_number[i];
        // 원하는 방에 배정 가능한 경우
        if (room[num] == 0){
            answer.push_back(num);
            room[num] = find_room(num + 1);
        }
        // 원하는 방에 다른 사람 있는 경우
        else{
            long long next_num = find_room(num);
            answer.push_back(next_num);
            room[next_num] = find_room(next_num + 1);
        }
    }
    return answer;
}
