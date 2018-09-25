
#include "stdafx.h"
#include "dvd_member.h"

void new_member(membership *pa);								    //1.신규 회원가입등록	
void member_search(membership *pa);							    //2.고객 검색
void dvd_registraion(dvd_menu *pb);								    //3.dvd 등록
void dvd_search(dvd_menu *pb);										//4.dvd 검색
int dvd_inquiry(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph, int rentHis);	//5.dvd 대여 
void dvd_return(dvd_menu *pb, Rent *pc );							//6.dvd 반납
void dvd_binquiry(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph); //7.dvd  대여 이력 조회
void dvd_rent(membership *pa, dvd_menu *pb, Rent *pc, Rent *ph);		//8.고객별 대여 dvd 전체 조회
extern int i, j, z;		//for문 용


int main()
{
	membership list[people] = { NULL };		//신규회원 배열 변수
	dvd_menu dvd_list[dvd_su] = { NULL };   //dvd 배열 배열 변수
	Rent dvd_Rent[rent_su] = { NULL };		//dvd 대여 배열 변수
	Rent dvd_His[dvdH_su] = { NULL };			//dvd 대여 이력 변수
	int num = 0;			//메뉴번호 판단하는 변수
	int rentHis = 0;

	while (1)
	{

		printf("             DVD 신규고객 회원가입          \n");
		printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
		printf("1. 신규회원 가입창						\n");
		printf("2. 고객 검색						\n");
		printf("3. DVD 등록						\n");
		printf("4. DVD 검색						\n");
		printf("5. DVD 대여						\n");
		printf("6. DVD 반납						\n");
		printf("7. DVD 대여 이력 조회          \n");
		printf("8. 고객별 대여 DVD 전체 조회 \n");
		printf("0. 종료           					\n");
		printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");


		printf("\n번호 입력>> ");
		scanf_s("%d", &num);
		printf("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
		if (num < 0)
		{
			printf("허용 범위가 아닙니다. 다시 입력하세요\n");
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
				new_member(list); break;			 //1.신규 회원가입등록	
			}
			case 2:
			{
				member_search(list); break;		//2.고객 검색
			}
			case 3:
			{
				dvd_registraion(dvd_list); break; //3.dvd 등록
			}
			case 4:
			{
				dvd_search(dvd_list); break;		//4.dvd 검색
			}
			case 5:
			{
				rentHis += dvd_inquiry(list, dvd_list, dvd_Rent, dvd_His, rentHis); 
				break;	//5.dvd 대여 
			}
			case 6:
			{
				dvd_return(dvd_list, dvd_Rent); break;			//6.dvd 반납
			}
			case 7:
			{
				dvd_binquiry(list, dvd_list, dvd_Rent, dvd_His); break; //7. dvd 대여 이력 조회
			}
			case 8:
			{
				dvd_rent(list, dvd_list, dvd_Rent, dvd_His); break;		//8.고객별 대여 dvd 전체 조회
			}
			}
			printf("\n〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
		}
	}
	return 0;
}