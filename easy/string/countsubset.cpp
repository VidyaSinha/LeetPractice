#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    // Step 1: Create the combined frequency map for words2
    unordered_map<char, int> maxFreq;
    for (const string& b : words2) {
        unordered_map<char, int> freq;
        for (char ch : b) {
            freq[ch]++;
        }
        for (const auto& [ch, count] : freq) {
            maxFreq[ch] = max(maxFreq[ch], count);
        }
    }

    // Step 2: Find all universal strings in words1
    vector<string> result;
    for (const string& a : words1) {
        unordered_map<char, int> freq;
        for (char ch : a) {
            freq[ch]++;
        }
        bool isUniversal = true;
        for (const auto& [ch, count] : maxFreq) {
            if (freq[ch] < count) {
                isUniversal = false;
                break;
            }
        }
        if (isUniversal) {
            result.push_back(a);
        }
    }

    return result;
}

int main() {
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "oo"};
    vector<string> result = wordSubsets(words1, words2);

    for (const string& word : result) {
        cout << word << " ";
    }

    return 0;
}
