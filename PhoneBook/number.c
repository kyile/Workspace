/*
������: �ڴ���
������Ʈ��: ��ȭ��ȣ ��

*/

//#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define bookmas 3 //���� ������ ��ȭ ��ȣ ����
#define munjasu 20
#define phone 12

typedef struct	//��ȭ��ȣ ����ü
{
	char name[munjasu];	//�̸� ���
	char tel[phone]; //��ȣ ���
}abook;

//�Լ�����
abook InputPhoneData(abook *pnum);	//1�Է��Լ�
abook ShowAllData(abook *pa);			//2����Լ�
abook SearchPhoneData(abook *pb);		//3�˻����
abook DeletePhoneData(abook *pc);		//4�������
void CrystalPhone(abook *pb);				//5.�������

											//main
int main()
{
	abook num[50]; //abook ����ü
	int number;
	while (1)
	{

		printf("\n\n------------------------------------------------\n");
		printf("	   ��ȭ��ȣ �Է� ���α׷�			\n");
		printf("-------------------- �޴� ----------------------\n\n");
		printf(" 1. ��ȭ��ȣ �Է�	     \n");
		printf(" 2. ��ȭ��ȣ ��ü ���\n");
		printf(" 3. ��ȭ��ȣ �˻�       \n");
		printf(" 4. ��ȭ��ȣ ����       \n");
		printf(" 5. ��ȭ��ȣ ����       \n");
		printf(" 6. ����                   \n");
		printf("----------------------------------------------- \n");

		printf("  ���� >>  ");
		scanf_s("%d", &number);

		if (number <= 0)	//0���� ������ �Է½�
		{
			printf("�ٽ� �Է� �ϼ��� \n");
		}
		if (number > 0)
		{

			switch (number)
			{
			case 1:
			{
				InputPhoneData(num); break; //1�Է��Լ�
			}
			case 2:
			{
				ShowAllData(num); break; //2��� �Լ�
			}
			case 3:
			{
				SearchPhoneData(num); break;//3�˻��Լ�
			}
			case 4:
			{
				DeletePhoneData(num); break;//4�����Լ�
			}
			case 5:
			{
				CrystalPhone(num); break; //5.�����Լ�
			}
			default:  //����
			{
				printf("���� �Դϴ�. \n");
				exit(1);
			}
			}
		}
	}

	return 0;
}

abook InputPhoneData(abook *pnum)				//1.�Է��Լ� ����
{
	int i;  //for���� ����

	printf("\n---------------------------------------------- \n");
	printf("\n              ��ȭ��ȣ �Է� ��                      \n\n\n\n\n");

	for (i = 0; i < bookmas; i++)
	{
		printf("�̸�[%d]: ", i + 1);
		scanf_s("%s", pnum[i].name, sizeof(pnum[i].name)); // char���� &����-�迭�� �ּҸ� ����������
		getchar();

		printf("��ȭ ��ȣ[%d]: ", i + 1);
		scanf_s("%s", pnum[i].tel, sizeof(pnum[i].tel));	//�ּҸ� �˷���� �Ѵ�.
		getchar();

		printf("\n");
	}
	return *pnum;
}

abook ShowAllData(abook *pnum)				//����Լ� ����
{
	int i;

	printf("---------------------------------------------- \n");
	printf("                 ��ȭ��ȣ ��ü ��� ��                      \n\n\n\n\n");

	for (i = 0; i < bookmas; i++)
	{
		if (pnum[i].tel == NULL) // ������ ��ȭ��ȣ  ó��
		{
			printf("");
		}
		else { printf("�̸��� ��ȭ��ȣ ���: %s , %s \n", pnum[i].name, pnum[i].tel); }
	}
	printf("�ݺ� Ƚ��: %d", bookmas);

	return	*pnum;
}
abook SearchPhoneData(abook *pnum)						//�˻����
{
	char name[munjasu]; //�񱳴�� �̸� �Էº���
	int i;

	printf("----------------------------------------------\n");
	printf("                  ��ȭ��ȣ�˻� ��                      \n\n\n\n\n");

	printf("�˻��� �̸�: ");
	scanf_s("%s", name, sizeof(name));
	getchar();

	for (i = 0; i < bookmas; i++)
	{
		if (strncmp(pnum[i].name, name, 20) == 0)			//abook�ǵΰ��� ���Ѵ�. 
		{
			printf("�̸�[%d]: %s \n", i + 1, pnum[i].name);
			printf("��ȭ��ȣ[%d]: %s \n", i + 1, pnum[i].tel);
		}
	}
	return *pnum;
}
abook DeletePhoneData(abook *pnum)
{
	char name[munjasu];
	int i;
	printf("----------------------------------------------\n");
	printf("                  ��ȭ��ȣ ���� ��                     \n");
	printf("�̸� �˻��� ����: ");
	scanf_s("%s", name, sizeof(name));
	getchar();

	for (i = 0; i < bookmas; i++)
	{
		if (strncmp(pnum[i].name, name, 20) == 0)			//����ü��name�� ��
		{
			printf("�̸�[%d]: %s \n", i + 1, pnum[i].name);
			printf("��ȭ��ȣ[%d]: %s \n", i + 1, pnum[i].tel);

			*pnum[i].name = NULL;
			*pnum[i].tel = NULL; //int �� 0���� �ٲ�

			printf("�����Ǿ����ϴ�. ");
		}
	}
	return *pnum;
}

void CrystalPhone(abook *pnum)//5.�����Լ�
{
	char name[munjasu];		//�̸� ����
	int i;

	printf("----------------------------------------------\n");
	printf("                  ��ȭ��ȣ ���� ��                     \n");
	printf(" ��ȭ��ȣ ������ �̸� �Է� : ");
	scanf_s("%s", name, sizeof(name));
	//�ִ� �̸������˻� 
	getchar();

	for (i = 0; i < bookmas; i++)
	{
		if (strncmp(pnum[i].name, name, 20) == 0)			//abook�ǵΰ��� ���Ѵ�. 
		{
			printf("�̸�[%d]: %s \n", i + 1, pnum[i].name);
			printf("��ȭ��ȣ[%d]: %s \n", i + 1, pnum[i].tel);

			*pnum[i].tel = NULL; //��ȣ ����

			printf("������ ��ȭ��ȣ:");
			scanf_s("%s", pnum[i].tel, sizeof(pnum[i].tel));
			printf("\n ������ �Ϸ� �Ǿ����ϴ�. ");
			getchar();
			continue;
		}
	}
}
