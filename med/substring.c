int lengthOfLongestSubstring( char * s ) {
    if(*s == '\0'){
        return 0;
    }
        char * l = s;
        char * r = l + 1;
        int n = 1;
        int max = 1;
        char seen[256]={0};
        seen[(unsigned char)*l] = 1;
        
        printf("Starting Point: \nl:%c | r:%c\n", *l, *r);
        while(*r != '\0'){
            int rdex = (unsigned char)(*r);
            int ldex = (unsigned char)(*l);

            while( seen[rdex] == 1 ){
                seen[ldex] = 0;
                l++;
                n--;
                ldex = (unsigned char)*l;
            }
            n++;
            if ( n > max ){
                max = n;
            }
            printf("l:%c | r:%c | n:%d\n", *l, *r, n);
            seen[rdex] = 1;
            
            r++;
        }
        printf("l: %s | r : %s\n", l, r);       
        return max;

}
