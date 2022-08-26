#include <stdio.h>

int main(){
	int a= 0x123456;

	//a = (a >> 8) % ((a >> 16) << 8);
	//a = a % 0x10000;
	a = a % 0x100;
	//a = a >> 16;
	//a = a>>4;
	printf("%x", a);
}