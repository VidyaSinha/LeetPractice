//Given a sorted array of distinct integers and a target value, 
//return the index if the target is found. If not, return the index where it 
//would be if it were inserted in order.

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) {
            return i; // Return index if target is found or needs to be inserted here
        }
    }
    return nums.size(); // If target is larger than all elements, return size
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target;

    cout << "Enter the target value: ";
    cin >> target;

    int result = searchInsert(nums, target);
    cout << "Target index or insertion point: " << result << endl;

    return 0;
}
