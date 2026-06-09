#include <stdio.h>

int main ( int argc, char *argv[]){
    
    int areas[] = {10,10,12,13,14,20};
    char name [] = "Zed";
    char full_name[] = { 'Z', 'e', 'd', ' ', 'A', '.',' ', 'S','h','a','w','\0'};
    printf("The size of an int(in bytes): %ld\n", sizeof(int));
    //So here we see how large an int is in terms of bytes
    //in c an integer type is 4 bytes, which gives it the range of 0 - 2^32, which is like 4 billion. 
    printf("The size of areas( int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas (int[]) : %ld\n", sizeof(areas)/sizeof(int));
    //prior to this we determined that the size of areas is 24 which gives us the amount of
    //btres the entire areas array holds in memory. This is not correct as we need
    //to be able to have indexes to the array. We can solve this issue by simply taking 
    //the size in bytes and dividing by the size of an indvidual element
    //using areas as an example, we know that areas is an array of ints and we know the size
    //of an int so we can simply divide the size of areas by the size of a single int, 
    //which results in the amount of int types within the areas array. 
    printf("The first element of areas is %d and the second is %d", areas[0],areas[1]);
    printf("The size of a char: %ld\n", sizeof(name));
    printf("The size of name (char[]): %ld", sizeof(name));
    printf("The number of chars: %ld", sizeof(name)/sizeof(char));
    printf("The size of full name (char[])", sizeof(full_name));
    printf("The number of chars: %ld\n", sizeof(full_name)/sizeof(char));
    printf("name =\"%s\" and full_name \"%s\"\n", name, full_name);
    return 0;
    
}
