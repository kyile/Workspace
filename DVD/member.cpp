
#include "stdafx.h"
#include "dvd_member.h"
/*
#include "stdlib.h"
#include <string.h>*/

extern int i, j, z;

void new_member(membership *pa);							//1.�ű� ȸ�����Ե�� ����
void member_search(membership *pa);						//2.�� �˻� ����
//1.�ű� ȸ�����Ե������
void new_member(membership *pa	) 
{
	char aid[20] = { NULL };
	int sw = 0;		//switch ����

	for (i = 0; i < people; i++)		//id ��ġ�� �ʱ�����
	{
		sw = 0;
		printf("\n---------- 1. �ű� ȸ�����Ե�� (%d) ----------", i + 1);
		printf("\nID ���: ");
		scanf_s("%s", aid, sizeof(aid));
		getchar();

		for (j = 0; j < people; j++)
		{
			if (strcmp(pa[j].id_name, aid) == 0)		//ID �� ���ǹ�
			{
				printf("�ش� ID�� ��� �߿� �ֽ��ϴ�.�ٸ� ID�� �Է����ּ���.");
				sw = 1;
				break;
			}
		}
		if (sw== 0){
			strcpy_s(pa[i].id_name, aid);			//����ü�� id�� �����Ҽ� �ֵ��� ��
			printf("�̸� ���: ");
			scanf_s("%s", pa[i].name, sizeof(pa[i].name));
			getchar();
			printf("��ȭ��ȣ ���: ");
			scanf_s("%s", pa[i].number, sizeof(pa[i].number));
			getchar();
			printf("\n----------------------------------------------");
		}
	}
}
//2. ���˻� ����
void member_search(membership *pa)
{
	char aid[20] = { NULL };
	printf("\n--------------- 2. �� �˻� ---------------");
	printf("\n���˻� ID:");
	scanf_s("%s", aid, sizeof(aid));
	getchar();
	int sw = 0;   //switch ����

	for (i = 0; i < people; i++)
	{
		if (strcmp(pa[i].id_name, aid) == 0) {
			printf("\n-------------- �˻��� ������ --------------");
			printf("\nID: %s", pa[i].id_name);
			printf("\n�̸�: %s", pa[i].name);
			printf("\n��ȭ��ȣ: %s", pa[i].number);
			sw = 1;
		}
	}
	if(sw==0){
		printf("\n ���� ID�Դϴ�."); 
	}
}