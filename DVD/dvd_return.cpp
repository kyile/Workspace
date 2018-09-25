#include "stdafx.h"
#include "dvd_member.h"

extern int i, j, z;

void dvd_binquiry(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph);  //7. dvd �뿩 �̷� ��ȸ
void dvd_rent(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph);		//8.���� �뿩 dvd ��ü ��ȸ
//7.dvd �뿩 �̷� ��ȸ
void dvd_binquiry(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph)
{	
	char isbn[13];
	printf("\nISBN�Է�: ");//ISBN�Է�
	scanf_s("%s", isbn, sizeof(isbn));
	getchar();

	for (i = 0; i < dvdH_su; i++)
	{
		if (strcmp(ph[i].dvd_ISBN, isbn) == 0)	//�ݳ� ���ϰ��
		{
			printf("\n �뿩��: %d", ph[i].date);//�뿩��
			printf("\n �� ID: %s", ph[i].id);//��ID

			for (j = 0; j < people; j++)
			{
				if (strcmp(pa[j].id_name, ph[i].id) == 0)
				{
					printf("\n �̸�:%s", pa[j].name);//�̸�
					printf("\n ��ȭ��ȣ:%s\n", pa[j].number);//��ȭ��ȣ
				}
			}
		}
		
	}
}
//8.���� dvd ��ü ��ȸ
void dvd_rent(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph)
{
	char id[20] = {NULL};
	int date1;
	int date2;
	int n1 = 0;

	printf("\nã�� �� id:");							//ã�� ��id,�뿩�Ⱓ�Է�
	scanf_s("%s", id, sizeof(id));
	getchar();

	for (i = 0; i < people; i++)
	{
		n1 = 1;
		if (strcmp(pa[i].id_name, id) == 0)	//����ȸ���� ���̸� ���
		{
			n1 = 0;
			break;
		}
	}
	if (n1 == 0)
	{
		printf("\n�뿩�Ⱓ (���۳�¥):");
		scanf_s("%d", &date1);
		printf("\n�뿩�Ⱓ (��������¥):");
		scanf_s("%d", &date2);

		for (j = 0; j < dvdH_su; j++)
		{
			if (strcmp(ph[j].id, id) == 0)				//id�� ��ġ�ϴ� �뿩����
			{
				if ((ph[j].date>=date1)&& (ph[j].date<=date2))
				{
					printf("\nISBN : %s \n �뿩�� : %d\n", ph[j].dvd_ISBN, ph[j].date);	//ISBN, �뿩���� ���
			
				}
			}
		}
	}

	else
		printf("ȸ�� ���� �ƴմϴ�. \n");
	//���⼭, �뿩 �Ⱓ�� �뿩���� �������� ��ȸ�� ���۳�¥�� ��ȸ�� ������ ��¥�� �Է¹޾Ƽ� ó��.
}