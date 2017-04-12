// From Weiss, Ch 2.4, p. 44, and
// http://www.programcreek.com/2013/02/leetcode-maximum-subarray-java/

#include <vector>
#include <string>

using namespace std;

/**
 * Returns vector of { max_sum, start, end }
 */
vector<int> max_subarray(vector<int> a) {
	int this_sum = 0, max_sum = 0;
	int start = 0, end = 0;

	for (int i = 0; i < a.size(); i++) {
		this_sum += a[i];

		if (this_sum > max_sum) {
			max_sum = this_sum;
			end = i;
		}
		else if (this_sum < 0) {
			this_sum = 0;
			start = i+1;
		}
	}

	vector<int> result = { max_sum, start, end };
	return result;
}

#include <iostream>
int main(int argc, const char *argv[]) {
	vector<int> vec = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int> result = max_subarray(vec);

	cout << "Maximum sum: " << result[0] << endl;
	cout << "Subarray: [ ";
	for (int i = result[1]; i <= result[2]; i++) {
		cout << vec[i] << " ";
	}
	cout << "]" << endl;

	return 0;
}
