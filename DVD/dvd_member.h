#include "stdafx.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>

#define people 1			//저장할 사람수=반드시대여 가능사람수와 같아야함
#define dvd_su 1		//dvd를 등록 할수있는 수
#define rent_su 1			//빌릴수있는 dvd수
#define dvdH_su 100		//이력 조회 가능 수

typedef struct				// 신규 회원 
{
	char id_name[20];		//아이디
	char name[10];			//이름
	char number[15];		//전화번호
}membership;

typedef struct
{
	char ISBN[13];		//13자리 수로 이루어진 국제표준 숫자
	char dvd_tite[30];	//제목
	char genre[10];		//장르
}dvd_menu;
typedef struct
{
	char dvd_ISBN[13];				//대여 dvd
	char id[20];				//대여한 id수와 
	int date;				//대여 날짜
}Rent;			

