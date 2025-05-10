
void quicksort(int* nums,int left,int right){
    if(left>=right)return;
    int pivot=nums[left];
    int l=left;
    int r=right;
    while(l<r){
while(l<r&&nums[r]>=pivot)r--;//先写l<r
if(l<r)nums[l]=nums[r];
while(l<r&&nums[l]<=pivot)l++;
if(l<r)nums[r]=nums[l];
    }
    nums[l]=pivot;
    if(left<=l-1)quicksort(nums,left,l-1);
    if(right>=l+1)quicksort(nums,l+1,right);//注意分治算法一定要使return的条件成立
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    quicksort(nums,0,numsSize-1);
    int** result=(int**)malloc(sizeof(int*)*numsSize*numsSize);
    *returnColumnSizes=(int*)malloc(sizeof(int)*numsSize*numsSize);//注意这个b要给他分配内存
    int k=0;
    *returnSize=0;
    for(int i=0;i<numsSize-3;i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;//注意是前置跳过
for(int j=i+1;j<numsSize-2;j++){
    if (j > i + 1 && nums[j] == nums[j - 1]) continue;
    int left=j+1,right=numsSize-1;
    while(left<right){
        long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
    if(sum==target){
(*returnSize)++;
(*returnColumnSizes)[k]=4;
result[k]=(int*)malloc(sizeof(int)*4);
result[k][0]=nums[i];
result[k][1]=nums[j];
result[k][2]=nums[left];
result[k++][3]=nums[right];
while(left+1<right&&nums[left]==nums[left+1])left++;//注意指针内部跳过
while(right-1>left&&nums[right]==nums[right-1])right--;
left++;
right--;
continue;
    }
if(sum<target){
    while(left+1<right&&nums[left]==nums[left+1])left++;
    left++;
}
if(sum>target){
    while(right-1>left&&nums[right]==nums[right-1])right--;
    right--;
}
    }
}

    }
    return result;
}


//接下来给出一个优化剪枝的方法，比上面快很多！
void quicksort(int* nums, int left, int right) {
    if (left >= right) return;
    int pivot = nums[left], l = left, r = right;
    while (l < r) {
        while (l < r && nums[r] >= pivot) r--;
        nums[l] = nums[r];
        while (l < r && nums[l] <= pivot) l++;
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    quicksort(nums, left, l - 1);
    quicksort(nums, l + 1, right);
}

// 四数之和
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 4) return NULL;

    // 1️⃣ 先排序，便于双指针
    quicksort(nums, 0, numsSize - 1);

    // 2️⃣ 申请内存
    int maxSize = numsSize * numsSize / 2;
    int** result = (int**)malloc(sizeof(int*) * maxSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSize);

    int k = 0;

    // 3️⃣ 四重循环 + 双指针
    for (int i = 0; i < numsSize - 3; i++) {
        // 剪枝：最小值大于 target
        if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
        // 剪枝：最大值小于 target
        if ((long long)nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] < target) continue;
        // 跳过重复元素
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            // 剪枝
            if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
            if ((long long)nums[i] + nums[j] + nums[numsSize - 1] + nums[numsSize - 2] < target) continue;
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 双指针寻找四数之和
            int left = j + 1, right = numsSize - 1;
            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    // 申请内存
                    result[k] = (int*)malloc(sizeof(int) * 4);
                    result[k][0] = nums[i];
                    result[k][1] = nums[j];
                    result[k][2] = nums[left];
                    result[k][3] = nums[right];
                    (*returnColumnSizes)[k] = 4;
                    k++;

                    // 跳过重复
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    *returnSize = k;
    return result;
}