#include "stdafx.h"
#include "dvd_member.h"

extern int i, j, z;

void dvd_binquiry(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph);  //7. dvd 대여 이력 조회
void dvd_rent(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph);		//8.고객별 대여 dvd 전체 조회
//7.dvd 대여 이력 조회
void dvd_binquiry(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph)
{	
	char isbn[13];
	printf("\nISBN입력: ");//ISBN입력
	scanf_s("%s", isbn, sizeof(isbn));
	getchar();

	for (i = 0; i < dvdH_su; i++)
	{
		if (strcmp(ph[i].dvd_ISBN, isbn) == 0)	//반납 고객일경우
		{
			printf("\n 대여일: %d", ph[i].date);//대여일
			printf("\n 고객 ID: %s", ph[i].id);//고객ID

			for (j = 0; j < people; j++)
			{
				if (strcmp(pa[j].id_name, ph[i].id) == 0)
				{
					printf("\n 이름:%s", pa[j].name);//이름
					printf("\n 전화번호:%s\n", pa[j].number);//전화번호
				}
			}
		}
		
	}
}
//8.고객별 dvd 전체 조회
void dvd_rent(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph)
{
	char id[20] = {NULL};
	int date1;
	int date2;
	int n1 = 0;

	printf("\n찾는 고객 id:");							//찾는 고객id,대여기간입력
	scanf_s("%s", id, sizeof(id));
	getchar();

	for (i = 0; i < people; i++)
	{
		n1 = 1;
		if (strcmp(pa[i].id_name, id) == 0)	//기존회원인 고객이면 출력
		{
			n1 = 0;
			break;
		}
	}
	if (n1 == 0)
	{
		printf("\n대여기간 (시작날짜):");
		scanf_s("%d", &date1);
		printf("\n대여기간 (마지막날짜):");
		scanf_s("%d", &date2);

		for (j = 0; j < dvdH_su; j++)
		{
			if (strcmp(ph[j].id, id) == 0)				//id와 일치하는 대여대조
			{
				if ((ph[j].date>=date1)&& (ph[j].date<=date2))
				{
					printf("\nISBN : %s \n 대여일 : %d\n", ph[j].dvd_ISBN, ph[j].date);	//ISBN, 대여일을 출력
			
				}
			}
		}
	}

	else
		printf("회원 고객이 아닙니다. \n");
	//여기서, 대여 기간은 대여일을 기준으로 조회할 시작날짜와 조회할 마지막 날짜를 입력받아서 처리.
}