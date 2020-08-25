#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int current = 0;
	//도로에 올라가져있는차, 차마다 남은 거리
	queue<int> truck;
	queue<int> remain;
	while (true) {
		int size = remain.size();
		for (int i = 0; i < size; i++) {
			int length = remain.front();
			remain.pop();

			//remain X
			if (length <= 1) {
				current -= truck.front();
				truck.pop();
				continue;
			}

			//remain
			remain.push(length - 1);
		}

		// 대기 truck이 있고 도로가 무게를 견딜 수 있다면
		if (truck_weights.size() > 0 && current + truck_weights.at(0) <= weight) {
			// 다리에 추가
			truck.push(truck_weights.at(0));
			current += truck_weights.at(0);
			remain.push(bridge_length);
			
			//대기 truck에서 삭제
			truck_weights.erase(truck_weights.begin());
		}
		// 시간 증가
		answer++;

		if (truck_weights.size() == 0 && truck.size() == 0)
			break;
	}
	return answer;
}