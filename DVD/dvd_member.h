#include "stdafx.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>

#define people 1			//������ �����=�ݵ�ô뿩 ���ɻ������ ���ƾ���
#define dvd_su 1		//dvd�� ��� �Ҽ��ִ� ��
#define rent_su 1			//�������ִ� dvd��
#define dvdH_su 100		//�̷� ��ȸ ���� ��

typedef struct				// �ű� ȸ�� 
{
	char id_name[20];		//���̵�
	char name[10];			//�̸�
	char number[15];		//��ȭ��ȣ
}membership;

typedef struct
{
	char ISBN[13];		//13�ڸ� ���� �̷���� ����ǥ�� ����
	char dvd_tite[30];	//����
	char genre[10];		//�帣
}dvd_menu;
typedef struct
{
	char dvd_ISBN[13];				//�뿩 dvd
	char id[20];				//�뿩�� id���� 
	int date;				//�뿩 ��¥
}Rent;			

