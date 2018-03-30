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
		printf("������� ����� �������: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*1.	��� ��������� ������ ����� �����
++a.	������������ ���������� ������, ������ ������� �������� 
����� ����� ������ ������������� ��������� ���������������� ������� ���������� �������
++b.	������������ ���������� ������, ������ ������� �������� 
����� ���������� �������� ������������� ��������� ��������������� ������ ���������� �������
++c.	������������ ���������� ������, ������ ������� �������� 
++d.	������������ ���������� ������, ������ ������� �������� 
����� ����� ������������� ��������� � ��������������� ������� ���������� �������, ������� 4 ��� 5
*/
			int row,col;
			printf("������� ������ �������: ");
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
				printf("��� �����!");
				exit(0);
			}
			else
			{
				Zapp_One_Mass(mass, row, col);
				Print_Mass(mass, row, col);
				if (massOne == NULL)
				{
					printf("��� �����!");
					exit(0);
				}
				else
				{
					Copy_Chet_Element(mass, massOne, row, col);
					Print_One_Mass(massOne, col);
				}
				if (massTwo == NULL)
				{
					printf("��� �����!");
					exit(0);
				}
				else
				{
					Copy_Nechet_Element_row(mass, massTwo, row, col);
					Print_One_Mass(massTwo, row);
				}
				if (massThree == NULL)
				{
					printf("��� �����!");
					exit(0);
				}
				else
				{
					Copy_Mass_Elsement_Krat(mass, massThree, row, col);
					Print_One_Mass(massThree, row);
				}
				if (massFour == NULL)
				{
					printf("��� �����!");
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
			/*2.	��� ��������� ������ �������� N xM, ����������� ������ �������.
a.	��� ��� ������������� �������� �������� � ���������� ������
b.	��� ��� ������ �������� �������� � ���� ���������� ������, � �������� � � ������
*/
			int row, col;
			printf("������� ������ �������: ");
			scanf("%d-%d", &row, &col);
			int *mass = NULL;
		}
		break;
		case 3:
		{
		//1.	��� ��������� ������ ����� �����
			//a.������������ ���������� ������, 
			//������ ������� �������� ����� ����������� �� ������ �������� ���������������� ������� ���������� �������
				//.������������ ���������� ������, ������ ������� �������� ����� ����������� �� ������ �������� ��������������� ������ ���������� �������
			int row, col;
			printf("������� ������ �������: ");
			scanf("%d-%d", &row, &col);
			int *mas = NULL;
			mas = (int *)malloc(sizeof(int)*row*col);
			if (mas == NULL)
			{
				printf("����� ���");
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
		//2.	��� ��������� ������ ����� �����
			//a.������������ ���������� ������, 
			//������ ������� �������� ����� ������� ������� �������� 
			//���������������� ������� ���������� �������(���� ������ �������� � ������� ���, �� �� ����� ����).
				//b.������������ ���������� ������, ������ ������� �������� ����� ���������� ��������� �������� ��������������� ������ ���������� �������(���� ������ �������� � ������ ���, �� �� ����� ����).
			int row, col;
			printf("������� ������ �������: ");
			scanf("%d-%d", &row, &col);
			int *mas1 = NULL;
			mas1 = (int *)malloc(sizeof(int)*row*col);
			if (mas1 == NULL)
			{
				printf("����� ���");
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
		printf("���������� 1-�� 2-���: ");
		scanf("%d", &quit);
	} while (quit == 1);
}
