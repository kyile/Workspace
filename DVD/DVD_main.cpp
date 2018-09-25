
#include "stdafx.h"
#include "dvd_member.h"

void new_member(membership *pa);								    //1.�ű� ȸ�����Ե��	
void member_search(membership *pa);							    //2.�� �˻�
void dvd_registraion(dvd_menu *pb);								    //3.dvd ���
void dvd_search(dvd_menu *pb);										//4.dvd �˻�
int dvd_inquiry(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph, int rentHis);	//5.dvd �뿩 
void dvd_return(dvd_menu *pb, Rent *pc );							//6.dvd �ݳ�
void dvd_binquiry(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph); //7.dvd  �뿩 �̷� ��ȸ
void dvd_rent(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph);		//8.���� �뿩 dvd ��ü ��ȸ
extern int i, j, z;		//for�� ��


int main()
{
	membership list[people] = { NULL };		//�ű�ȸ�� �迭 ����
	dvd_menu dvd_list[dvd_su] = { NULL };   //dvd �迭 �迭 ����
	Rent dvd_Rent[rent_su] = { NULL };		//dvd �뿩 �迭 ����
	Rent dvd_His[dvdH_su] = { NULL };			//dvd �뿩 �̷� ����
	int num = 0;			//�޴���ȣ �Ǵ��ϴ� ����
	int rentHis = 0;

	while (1)
	{

		printf("             DVD �ű԰� ȸ������          \n");
		printf("������������������������\n");
		printf("1. �ű�ȸ�� ����â						\n");
		printf("2. �� �˻�						\n");
		printf("3. DVD ���						\n");
		printf("4. DVD �˻�						\n");
		printf("5. DVD �뿩						\n");
		printf("6. DVD �ݳ�						\n");
		printf("7. DVD �뿩 �̷� ��ȸ          \n");
		printf("8. ���� �뿩 DVD ��ü ��ȸ \n");
		printf("0. ����           					\n");
		printf("������������������������");


		printf("\n��ȣ �Է�>> ");
		scanf_s("%d", &num);
		printf("\n������������������������");
		if (num < 0)
		{
			printf("��� ������ �ƴմϴ�. �ٽ� �Է��ϼ���\n");
			break;
		}
		if (num >= 0)
		{
			switch (num)
			{
			case 0:
			{exit(1); }
			case 1:
			{
				new_member(list); break;			 //1.�ű� ȸ�����Ե��	
			}
			case 2:
			{
				member_search(list); break;		//2.�� �˻�
			}
			case 3:
			{
				dvd_registraion(dvd_list); break; //3.dvd ���
			}
			case 4:
			{
				dvd_search(dvd_list); break;		//4.dvd �˻�
			}
			case 5:
			{
				rentHis += dvd_inquiry(list, dvd_list, dvd_Rent, dvd_His, rentHis); 
				break;	//5.dvd �뿩 
			}
			case 6:
			{
				dvd_return(dvd_list, dvd_Rent); break;			//6.dvd �ݳ�
			}
			case 7:
			{
				dvd_binquiry(list, dvd_list, dvd_Rent, dvd_His); break; //7. dvd �뿩 �̷� ��ȸ
			}
			case 8:
			{
				dvd_rent(list, dvd_list, dvd_Rent, dvd_His); break;		//8.���� �뿩 dvd ��ü ��ȸ
			}
			}
			printf("\n������������������������\n");
		}
	}
	return 0;
}