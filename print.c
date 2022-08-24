//ㄴㅏ중에 꼭  삭삭제제!!!!!!!!!!!!!!!!!!!1
#include <stdio.h> //print.c
#include "fdf.h"

void printmap(t_map *map)
{
	printf("* map :\n");
	for (int i=0 ; i < map->row; i++)
	{
		for (int j=0; j < map->col; j++)
			printf("%d ", map->coordn[i][j]);
		printf("\n");
	}
	printf("* color :\n");
	for (int i=0 ; i < map->row; i++)
	{
		for (int j=0; j < map->col; j++)
			printf("%d ", map->color[i][j]);
		printf("\n");
	}
}