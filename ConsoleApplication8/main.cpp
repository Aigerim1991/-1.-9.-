#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include"Header.h"


void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int n, quit;
	do
	{
		printf("введите номер задания: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*1.	Дан двумерный массив целых чисел
++a.	Сформировать одномерный массив, каждый элемент которого 
равен сумме четных положительных элементов соответствующего столбца двумерного массива
++b.	Сформировать одномерный массив, каждый элемент которого 
равен количеству нечетных отрицательных элементов соответствующей строки двумерного массива
++c.	Сформировать одномерный массив, каждый элемент которого 
++d.	Сформировать одномерный массив, каждый элемент которого 
равен сумме положительных элементов в соответствующем столбце двумерного массива, кратных 4 или 5
*/
			int row,col;
			printf("введите размер матрицы: ");
			scanf("%d-%d", &row, &col);
			int *mass = NULL;
			mass = (int*)calloc(row*col, sizeof(int));
			int *massOne = NULL;
			massOne = (int*)calloc(col, sizeof(int));
			int *massTwo = NULL;
			massTwo = (int*)calloc(col, sizeof(int));
			int *massThree = NULL;
			massThree = (int*)calloc(col, sizeof(int));
			int *massFour = NULL;
			massFour = (int*)calloc(col, sizeof(int));
			if (mass == NULL)
			{
				printf("нет места!");
				exit(0);
			}
			else
			{
				Zapp_One_Mass(mass, row, col);
				Print_Mass(mass, row, col);
				if (massOne == NULL)
				{
					printf("нет места!");
					exit(0);
				}
				else
				{
					Copy_Chet_Element(mass, massOne, row, col);
					Print_One_Mass(massOne, col);
				}
				if (massTwo == NULL)
				{
					printf("нет места!");
					exit(0);
				}
				else
				{
					Copy_Nechet_Element_row(mass, massTwo, row, col);
					Print_One_Mass(massTwo, row);
				}
				if (massThree == NULL)
				{
					printf("нет места!");
					exit(0);
				}
				else
				{
					Copy_Mass_Elsement_Krat(mass, massThree, row, col);
					Print_One_Mass(massThree, row);
				}
				if (massFour == NULL)
				{
					printf("нет места!");
					exit(0);
				}
				else
				{
					Copy_Mass_elemnt_krat4(mass, massFour, row, col);
					Print_One_Mass(massFour, col);
				}

			}
			free(mass);
			free(massOne);
			free(massTwo);
			free(massThree);
		}
		break;
		case 2:
		{
			/*2.	Дан двумерный массив размером N xM, заполненный целыми числами.
a.	Все его отрицательные элементы записать в одномерный массив
b.	Все его четные элементы записать в один одномерный массив, а нечетные — в другой
*/
			int row, col;
			printf("введите размер матрицы: ");
			scanf("%d-%d", &row, &col);
			int *mass = NULL;
		}
		break;
		case 3:
		{
		//1.	Дан двумерный массив целых чисел
			//a.Сформировать одномерный массив, 
			//каждый элемент которого равен наибольшему по модулю элементу соответствующего столбца двумерного массива
				//.Сформировать одномерный массив, каждый элемент которого равен наибольшему по модулю элементу соответствующей строки двумерного массива
			int row, col;
			printf("введите размер матрицы: ");
			scanf("%d-%d", &row, &col);
			int *mas = NULL;
			mas = (int *)malloc(sizeof(int)*row*col);
			if (mas == NULL)
			{
				printf("Место нет");
				exit(0);
			}
			else
			{
				for (int i = 0; i <row ; i++)
				{
					for (int j = 0; j < col; j++)
					{
						*(mas + i*col + j) = -1 + rand() % 100;
						printf("%d\t", *(mas + i*col + j));
					}
					printf("\n");
				}

				printf("\n------------------------\n");

				int *m = NULL;
				m = (int*)malloc(sizeof(int)*col);

				int max = 0;
				
				for (int i = 0; i <row; i++)
				{
					max = *(mas + i*col + 0);
					for (int j = 0; j < col; j++)
					{
						if (*(mas + i*col + j) > max)
						{
							max = *(mas + i*col + j);
						}
					}
					*(m + i) = max;
				}


				for (int i = 0; i < col; i++)
				{
					printf("%d\t", *(m + i));
				}
				printf("\n");

			}
		}
		break;
		case 4:
		{
		//2.	Дан двумерный массив целых чисел
			//a.Сформировать одномерный массив, 
			//каждый элемент которого равен первому четному элементу 
			//соответствующего столбца двумерного массива(если такого элемента в столбце нет, то он равен нулю).
				//b.Сформировать одномерный массив, каждый элемент которого равен последнему нечетному элементу соответствующей строки двумерного массива(если такого элемента в строке нет, то он равен нулю).
			int row, col;
			printf("введите размер матрицы: ");
			scanf("%d-%d", &row, &col);
			int *mas1 = NULL;
			mas1 = (int *)malloc(sizeof(int)*row*col);
			if (mas1 == NULL)
			{
				printf("Место нет");
				exit(0);
			}
			else
			{
				for (int i = 0; i <row; i++)
				{
					for (int j = 0; j < col; j++)
					{
						*(mas1 + i*col + j) = -2 + rand() % 10;
						printf("%d\t", *(mas1 + i*col + j));
					}
					printf("\n");
				}
				printf("\n---------\n");
				int *m1 = NULL;
				m1 = (int*)calloc(col,sizeof(int));

				for (int i = 0; i <row; i++)
				{
					for (int j = 0; j < col; j++)
					{
						if (*(mas1 + i*col + j) % 2 == 0)
						{
							*(m1+i) = *(mas1 + i*col + j);
							break;
						}
						
					}
					
				}
				for (int i = 0; i < col; i++)
				{
					printf("%d\t", *(m1 + i));
				}
				printf("\n");

			}
		}break;
		default:
			break;
		}
		printf("продолжить 1-да 2-нет: ");
		scanf("%d", &quit);
	} while (quit == 1);
}
