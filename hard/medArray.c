#include <stdlib.h>
#include <math.h>

double mod ( double a, double b ) {
	double q = a/b;
	q = floor( q );
	return  a - (b*q);
}

double bin_search ( int *a, int *b, int m, int n );


double findMedianSortedArrays( int *nums1, int nums1Size, int *nums2, int nums2Size ) {
	int limit = nums1Size + nums2Size;
	int median;
	int median2 = median = 0;
	int eflag = 0;
	if ( limit % 2 == 0 ) {
		median = limit / 2;
		median2 = median + 1;
		eflag = 1;
	}
	else {
		median = limit / 2;
	}
}
