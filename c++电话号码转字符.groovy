#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 映射数字到字母
    vector<string> digitToLetters = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        // 递归终止条件：当当前组合长度等于 digits 的长度时，加入结果
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // 获取当前数字对应的字母字符串
        int digit = digits[index] - '0';
        string letters = digitToLetters[digit];

        // 遍历当前数字对应的字母，递归处理下一位
        for (char letter : letters) {
            current.push_back(letter);  // 选择当前字母
            backtrack(digits, index + 1, current, result);  // 递归处理下一位
            current.pop_back();  // 撤销选择，回溯
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;  // 如果输入为空，直接返回空结果
        }
        string current;
        backtrack(digits, 0, current, result);  // 从第一个数字开始回溯
        return result;
    }
};

int main() {
    Solution solution;

    // 示例 1
    string digits = "23";
    vector<string> result = solution.letterCombinations(digits);
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    // 示例 2
    digits = "";
    result = solution.letterCombinations(digits);
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    // 示例 3
    digits = "2";
    result = solution.letterCombinations(digits);
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}