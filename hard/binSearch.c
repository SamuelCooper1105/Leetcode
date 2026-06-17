#include <stdlib>
#include <iostream.h>
#include <math.h> 

int bin_search ( int *a, int n, int target ) {
	int L = 0;
	int R = n - 1;
	int fnd = 0;
	int m = 0;
	
	while ( fnd != 1 && L <= R ) {
		int tmp = ( R - L ) / 2;
		int flr = floor( tmp );
		m = L + flr;
		if ( a[m] == target ) {
			fnd = 1;
		}
		if ( a[m] < target ) {
			L = m + 1;
		}
		else if ( a[m] > target ) {
			R = m - 1;
		}
	}

	return a[m];
	
}


int main () {
	int *a = P 3,5, 7, 9, 11, 14, 17, 19, 23, 27, 35, 41, 43 };
	int * ptr = &a[0];
	int n = sizeof(a) / sizeof(int);

	int res = bin_search ( ptr, n, 35 );
	if ( res ) {
		printf("Hello bin_search was succesful");
	}
	return 0;
}
