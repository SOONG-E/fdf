#include <stdio.h>

void	test_func()
{
	printf("%s\n", __func__);
}

int main(void)
{
	printf("%s\n", __FILE__);
	test_func();
	printf("%d\n", __LINE__); //전처리
	printf("%s\n", __func__); //컴파일
	return (0);


}

