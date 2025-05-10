#include <stdio.h>

int maxSubArraySum(int arr[], int n) {
    int max_sum = arr[0];  // 最大和
    int current_sum = arr[0]; // 当前窗口的和

    for (int i = 1; i < n; i++) {
        // 如果当前和 + 当前元素小于当前元素，就从当前元素重新开始
        current_sum = (current_sum + arr[i] > arr[i]) ? current_sum + arr[i] : arr[i];
        max_sum = (max_sum > current_sum) ? max_sum : current_sum;
    }

    return max_sum;
}

int main() {
    int arr[] = {1, -2, 3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = maxSubArraySum(arr, n);
    printf("Maximum subarray sum is %d\n", result);  // 输出：10
    return 0;
}
