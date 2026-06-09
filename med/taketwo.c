#include <stdlib.h>
#include <strings.h>

int substringfdr( char *s ){
	if(*s == '\0'){
		return 0;
	}

	char * l = s;
	char * r = l +1;
	int n = 1;
	int max =1;

	char seen[256] = {0};

	seen[(unsigned char)*l] = 0;
	int i = 1;
	while ( *r != '\0'){
		int rdex = (unsigned char) *r;
		int ldex = (unsigned char) *l;

		if(seen[rdex] != 0 ) {
			l = &s[seen[rdex]];
		}

		seen[rdex] = i;
		i++;
	}

	n = r- l;
	return n;

}


int main ( int argc, char *argv[]){
	char * nput = argv[1];

	int res = substringfdr(nput);

	printf("Hello:\nThe result was %d and the prompt was %s.", res, nput);
	return 0;
}
