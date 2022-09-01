#include <stdio.h>
#include "fdf.h"
/*
int main(){
	int a= 0x123456;

	//a = (a >> 8) % ((a >> 16) << 8);
	//a = a % 0x10000;
	a = a % 0x100;
	//a = a >> 16;
	//a = a>>4;
	printf("%x", a);
}
*/
#include <math.h>

int	cal_rgb(t_coor coor, t_coor one, t_coor two, char c)
{
	double gap;
	gap = sqrt((pow(coor.x - one.x, 2)) + (pow(coor.y - one.y, 2))) / sqrt((pow(two.x - one.x, 2)) + (pow(two.y - one.y, 2)));

	printf("gap %f\n", gap);
	if (c == 'r')
	{
		return ((((two.color >> 16) - (one.color >> 16)) * gap) + (one.color >> 16));
	}
	else if (c == 'g')
		return (((((two.color % 0x10000) >> 8) - ((one.color % 0x10000) >> 8)) * gap) + ((one.color % 0x10000) >> 8));
	else
		return ((((two.color % 0x100) - (one.color % 0x100)) * gap) + (one.color % 0x100));
}

int	make_color(t_coor coor, t_coor one, t_coor two)
{
	int temp;

	if (one.color == two.color)
		return (one.color);
	temp = cal_rgb(coor, one, two, 'r') << 16;
	temp += cal_rgb(coor, one, two, 'g') << 8;
	temp += cal_rgb(coor, one, two, 'b');
	return (temp);
}

int main(){
	t_coor a;
	t_coor b;
	t_coor	c;

	a.x = 0;
	a.y = 0;
	a.color = 0x000000;

	b.x = 3;
	b.y = 3;
	b.color = 0xffffff;

	c.x = 1;
	c.y = 1;
	c.color = make_color(c, a, b);
	printf("%x \n %x\n %x\n", c.color >> 16 , (c.color % 0x10000) >> 8, c.color % 0x100);
}