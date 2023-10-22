#include <cstdio>

int func(int a){
	static int b = 3;
	static int c;
	int e[3] = {3, 2, 1};
	int *p = e;
	c = 3;
	--b;
	return a ? ++(*p)+b+(++c): *(++p)+b+(--c);
}

int main(void)
{
	int i;
	for(i = 0;i < 3; i+=2){
		printf("%d,",func(i));
	}
	return 0;
}