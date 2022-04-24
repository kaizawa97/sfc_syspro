#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

struct vector {
	int x;
	int y;
	int z;
};
struct vector f,s,result;

void vector_add (int a, int b, int c, int d, int e, int f) {
	result.x = a + d;
	result.y = b + e;
	result.z = c + f;
};

void vector_sub (int a, int b, int c, int d, int e, int f) {
	result.x = a - d;
	result.y = b - e;
	result.z = c - f;
};

int main () {
	int ret;
	char input[MAXLINE];

	fgets(input,MAXLINE,stdin);
	ret = sscanf(input, "%d,%d,%d",&f.x, &f.y, &f.z);
	if (ret != 3) {
		printf("Error: 引数を3個にまたコンマ区切りで指定してください。\n");
		exit(1);
	}

	fgets(input,MAXLINE,stdin);
	ret = sscanf(input, "%d,%d,%d",&s.x, &s.y, &s.z);
	if (ret != 3) {
		printf("Error: 引数を3個にまたコンマ区切りで指定してください。\n");
		exit(1);
	}
	
	vector_add(f.x,f.y,f.z,s.x,s.y,s.z);
	printf("(%d,%d,%d) + (%d,%d,%d) = (%d,%d,%d)\n",f.x,f.y,f.z,s.x,s.y,s.z,result.x,result.y,result.z);
	vector_sub(f.x,f.y,f.z,s.x,s.y,s.z);
	printf("(%d,%d,%d) - (%d,%d,%d) = (%d,%d,%d)\n",f.x,f.y,f.z,s.x,s.y,s.z,result.x,result.y,result.z);
	exit(0);
}
