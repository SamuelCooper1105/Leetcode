#include <iostream.h>
#include <stdlib.h>

double findMedianSortedArrays(int * nums1, int nums1Size, int * nums2, int nums2Size){

	double limit = nums1Size + nums2Size;
	int i =0;
	int median;
	int median2;
	if(limit%2 == 0){
		//Remember that in C, division truncates towards 0. there fore 5/2
		//would be 2 as 5 / 2 would typically be 2.5, but this needs to be
		//truncated towards 0, one could call this the floor of the division
		//which would be correct for positive numbers(positive signed or
		//unsigned). Now this is not true for negative numbers. if we are
		// given -5 /  2 this would typically be -2.5. Based off of the above
		// you may assume that the answer will be -2 or you may assume it
		// will be -3. If you actually read what was written the correct
		// answer would be -3, but this is not how C works, the correct answer
		// would be -2, as instead of taking the floot of a result, C
		// truncates the answer towards 0, instead of just taking the floor.
		limit / 2 = median;
		median2 = median + 1;
	}	
	else {
		//If limit is 11 what is the median? Well we have 11 elements
		//obviously so we have 1 median, which leaves 10 other elements
		//or 5 on either side of the median. so the median element of an
		//array with 11 elements would be 6. so whats 11 / 2 in C? its 5
		//so we need to increment the result of our division op.
		
		median = (limit / 2) + 1;
	}
	//Alright so the idea here is to find the median of the two arrays.
	//we are supposed to do this in Log(m + n) time. So lets get the brute force
	//out of the way. We could simply merge the two lists then find the median
	//that way. but this is expensive in terms of computing power and storage.
	//Remember we are iterating through each and every element, then creating a
	//new array. It is trivial to calculate what the median element should be
	//(demonstrated above) we should be able to iterate through the values until
	//we reach the median element.
	

}

