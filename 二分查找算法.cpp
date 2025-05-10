class Solution {
    public:
       int search(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
    
                // 找到目标值
                if (nums[mid] == target) {
                    return mid;
                }
    
                // 判断哪一部分是有序的
                if (nums[mid] >= nums[left]) { // 左半部分有序
                    if (target >= nums[left] && target < nums[mid]) { // target 在左半部分
                        right = mid - 1;
                    } else { // target 在右半部分
                        left = mid + 1;
                    }
                } else { // 右半部分有序
                    if (target > nums[mid] && target <= nums[right]) { // target 在右半部分
                        left = mid + 1;
                    } else { // target 在左半部分
                        right = mid - 1;
                    }
                }
            }
            return -1; // 没找到
        }
    };