#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > farthest) return false; // 当前点不可达
            farthest = max(farthest, i + nums[i]);
            if (farthest >= nums.size() - 1) return true; // 能到最后一个下标
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    // 示例输入 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "输入：{2, 3, 1, 1, 4}" << endl;
    cout << "输出：" << (solution.canJump(nums1) ? "true" : "false") << endl;

    // 示例输入 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "输入：{3, 2, 1, 0, 4}" << endl;
    cout << "输出：" << (solution.canJump(nums2) ? "true" : "false") << endl;

    return 0;
}
