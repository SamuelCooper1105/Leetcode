/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct hashp {
	int key;
	int value;
    int flag;	
};

int hashme(int key, int numSize){
	long long h = (long long)key % numSize;
	if ( h < 0) h+= numSize;
	
	return (int)h;
}

int* twoSum(int *nums, int numsSize, int target, int* returnSize){
    printf("%d", numsSize);
	struct hashp *table = calloc( numsSize, sizeof(struct hashp));
	for(int i = 0; i < numsSize; ++i) {
		int comp = target - nums[i];
		int hsh_dex = hashme(comp, numsSize);
        while(table[hsh_dex].flag != 0){
            if(table[hsh_dex].key == comp){
			    int* res = malloc(sizeof(int)*2);
			    res[0] = table[hsh_dex].value;
			    res[1] = i;
			    free(table);
			    //free(hashp);
			    *returnSize = 2;
			    return res;
		    }
            hsh_dex++;
            if(hsh_dex >= numsSize){
                hsh_dex =0;
                continue;
            }
        }
		if(table[hsh_dex].flag != 0 && table[hsh_dex].key == comp){
			int* res = malloc(sizeof(int)*2);
			res[0] = table[hsh_dex].value;
			res[1] = i;
			free(table);
			//free(hashp);
			*returnSize = 2;
			return res;
		}
		
		int hsh_dex2 = hashme(nums[i], numsSize);
        while(table[hsh_dex2].flag==1){
            hsh_dex2++;
            if(hsh_dex2 >= numsSize){
                hsh_dex2 = 0;
                continue;
            }
        }
            table[hsh_dex2].value = i;
		    table[hsh_dex2].key = nums[i];
            table[hsh_dex2].flag =  1;
	}	
	*returnSize = 0;
    free(table);
	return NULL;
}
