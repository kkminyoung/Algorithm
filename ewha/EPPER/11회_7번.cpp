#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


double solution(int n, vector<int> &num_vector) {
	double answer = 0.0;

	sort(num_vector.begin(), num_vector.end());

	double m = num_vector[0];

	for (int i = 1; i < n; i++) {
		m = (m + num_vector[i])/2.0;
	}

	answer = m;

	return answer;
}
