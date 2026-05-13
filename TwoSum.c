**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int len = numsSize;

    for(int i =0; i < len; ++i){
            for(int j = i+1; j < len; j++){
                if(nums[j] == target - nums[i]){
                    int *result = malloc(sizeof(int)*2);
                    result[0] = i;
                    result[1] = j;
                    *returnSize =2;
                    return result;
                }
            }
       
    }
    *returnSize = 0;
    return malloc(sizeof(int)*0);
}
