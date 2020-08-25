#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int current = 0;
	//���ο� �ö����ִ���, ������ ���� �Ÿ�
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

		// ��� truck�� �ְ� ���ΰ� ���Ը� �ߵ� �� �ִٸ�
		if (truck_weights.size() > 0 && current + truck_weights.at(0) <= weight) {
			// �ٸ��� �߰�
			truck.push(truck_weights.at(0));
			current += truck_weights.at(0);
			remain.push(bridge_length);
			
			//��� truck���� ����
			truck_weights.erase(truck_weights.begin());
		}
		// �ð� ����
		answer++;

		if (truck_weights.size() == 0 && truck.size() == 0)
			break;
	}
	return answer;
}