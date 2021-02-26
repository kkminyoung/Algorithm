#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int numbers[]) {
	vector<int> answer;
	vector<int> ind;
	
	int k = 7;
	for(int i=0; i<k; i++)
		ind.push_back(1);

	for(int i=0; i<9-k; i++)
		ind.push_back(0);
	
	sort(ind.begin(), ind.end());

	do{
		int sum = 0;
		for(int i=0; i<ind.size(); i++){
			if(ind[i] == 1){
				sum += numbers[i];
			}
		}
		
		if(sum==100){
			for(int i=0; i<ind.size(); i++){
				if(ind[i] == 1)
					answer.push_back(numbers[i]);
			}
			break;
		}
	}while(next_permutation(ind.begin(), ind.end()));
	
	return answer;
}

int main(void) {
	int numbers[9];
	int i;
	vector<int> r;
	
	for (i = 0; i < 9; i++) 
		cin >> numbers[i];
	
	r = solution(numbers);
	
	for (i = 0; i < 7; i++) 
		cout << r[i] << " " ;
	
}
