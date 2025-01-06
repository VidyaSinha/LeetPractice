#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int>& nums, int target)
{
    unordered_map<int, int> numMap; // Stores the number and its index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // The number needed to reach the target
        if (numMap.count(complement)) {    // Check if the complement exists
            return {numMap[complement], i}; // Return indices
        }
        numMap[nums[i]] = i; // Store the current number and its index
    }

    return {}; // Return an empty vector if no solution is found
}

int main() {
    vector<int> nums = {2, 7, 11, 15}; // Example input
    int target = 9;

    vector<int> result = solution(nums, target); // Call the function

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
