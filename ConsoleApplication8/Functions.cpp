#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
int i, j;
void Zapp_One_Mass(int *mass, int row,int col)
{
	for (i = 0;i < row*col;i++)
		*(mass + i) = -20 + rand() % 100;	
}
void Print_Mass(int *mass, int row, int col)
{
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf("%d\t", *(mass + i*col+j));
		}
		printf("\n");
	}
	printf("\n-----------------------\n");
}
void Copy_Chet_Element(int *mass, int *massOne, int row, int col)
{
	int summ = 0;
	for (i = 0;i < col;i++)
	{
		summ = 0;
		for (j = 0;j < row;j++)
		{
			if (*(mass + j*row + i) % 2 == 0)
			{
				summ += *(mass + j*row + i);
			}
		}
		*(massOne + i) = summ;
	}
}
void Print_One_Mass(int *mass, int row)
{
	{
		for (i = 0;i < row;i++)
			printf("%d\t", *(mass + i));
	}
	printf("\n------------------------\n");
}
void Copy_Nechet_Element_row(int *mass, int *massOne, int row, int col)
{
	int summ = 0;
	for (i = 0;i < row;i++)
	{
		summ = 0;
		for (j = 0;j < col;j++)
		{
			if (*(mass + i*col + j) < 0)
			{
				if (*(mass + i*col + j) % 2 != 0)
				{
					summ += *(mass + i*col + j);
				}
			}
		}

		*(massOne + i) = summ;
	}
}
void Copy_Mass_Elsement_Krat(int *mass, int *massOne, int row, int col)
{
	int summ = 0;
	for (i = 0;i < row;i++)
	{
		summ = 0;
		for (j = 0;j < col;j++)
		{
			if (*(mass + i*col + j) < 0)
			{
				if ((*(mass + i*col + j) % 3 == 0)||(*(mass+i*col+j)%7==0))
				{
					summ += *(mass + i*col + j);
				}
			}
		}

		*(massOne + i) = summ;
	}
}
void Copy_Mass_elemnt_krat4(int *mass, int *massOne, int row, int col)
{
	int summ = 0;
	for (i = 0;i < col;i++)
	{
		summ = 0;
		for (j = 0;j < row;j++)
		{
			if (*(mass + j*row + i) > 0)
			{
				if (*(mass + j*row + i) % 4 == 0 || (*(mass + j*row + i) % 5 == 0))
				{
					summ += *(mass + j*row + i);
				}
			}
		}
		*(massOne + i) = summ;
	}
}
int *Get_Memmory(int col)
{
	return (int*)calloc(col, sizeof(int));

	/*mass = (int*)calloc(col, sizeof(int));
	if (mass == NULL)
	{
		printf("нет места!\n");
		exit(0);
	}
	return mass;*/
}
