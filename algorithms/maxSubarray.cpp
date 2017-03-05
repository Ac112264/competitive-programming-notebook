// From Weiss, Ch 2.4, p. 44, and
// http://www.programcreek.com/2013/02/leetcode-maximum-subarray-java/

#include <vector>
#include <string>

/**
 * Returns vector of { maxSum, start, end }
 */
std::vector<int> maxSubArray(std::vector<int> a) {
	int thisSum = 0, maxSum = 0;
	int start = 0, end = 0;

	for (int i = 0; i < a.size(); i++) {
		thisSum += a[i];

		if (thisSum > maxSum) {
			maxSum = thisSum;
			end = i;
		}
		else if (thisSum < 0) {
			thisSum = 0;
			start = i+1;
		}
	}

	std::vector<int> result { maxSum, start, end };
	return result;
}

#include <iostream>
int main(int argc, const char *argv[]) {
	std::vector<int> vec = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	std::vector<int> result = maxSubArray(vec);

	std::cout << "Maximum sum: " << result[0] << std::endl;
	std::cout << "Subarray: [ ";
	for (int i = result[1]; i <= result[2]; i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "]" << std::endl;

	return 0;
}
