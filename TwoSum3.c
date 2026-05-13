/* yes I am aware that this is disgusting, and the hash function is bad but it runs quick on leet code so I do not care */


struct HN {
    int key;
    int val;
    int flag;
    struct HN *next;
};

int hashme(int key, int len){
    int hashed = key % len;
    if(hashed < 0){
        hashed += len;
    }
    
    return hashed;
}



int *twoSum(int *nums, int len, int target, int* returnsize ){
    
    struct HN *table = calloc(len, sizeof(struct HN));
    for(int i =0; i < len; ++i){
        int comp = target - nums[i];
        int hsh_ndx = hashme(comp, len);
	    if(table[hsh_ndx].flag == 1 && table[hsh_ndx].key == comp){
		    int *res = malloc(sizeof(int) * 2);
		    res[0]=table[hsh_ndx].val;
		    res[1]=i;
		    free(table);
		    *returnsize = 2;
		    return res;
	    }
	    else{
		    struct HN *cur = table[hsh_ndx].next;
		    while(cur != NULL && cur->flag ==1){
		    	if(cur->key == comp){
			    	int *res = malloc(sizeof(int) * 2);
			    	res[0]=table[hsh_ndx].val;
                    res[1]=i;
			    	free(table);
		    		*returnsize = 2;
		    		return res;
		    	}
			    cur = cur->next;
		    }
    	}
        
        int hsh_ndx2 = hashme(nums[i], len);
        if(table[hsh_ndx2].flag == 0 ){
            table[hsh_ndx2].val = i;
            table[hsh_ndx2].key = nums[i];
            table[hsh_ndx2].flag = 1;
            continue;
        }
        else{
            struct HN *cur = table[hsh_ndx2].next;
            while( cur != NULL && cur->flag == 0 ){
                cur->val = i;
                cur->key = nums[i];
                cur->flag=1;
                table[hsh_ndx2].next = cur;
                free(cur);
            }
        }
    }
        *returnsize = 0;
        free(table);
        return NULL;
}
