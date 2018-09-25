/*
제작자: 박다정
프로젝트명: 전화번호 부

*/

//#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define bookmas 3 //저장 가능한 전화 번호 개수
#define munjasu 20
#define phone 12

typedef struct	//전화번호 구조체
{
	char name[munjasu];	//이름 멤버
	char tel[phone]; //번호 멤버
}abook;

//함수선언
abook InputPhoneData(abook *pnum);	//1입력함수
abook ShowAllData(abook *pa);			//2출력함수
abook SearchPhoneData(abook *pb);		//3검색기능
abook DeletePhoneData(abook *pc);		//4삭제기능
void CrystalPhone(abook *pb);				//5.수정기능

											//main
int main()
{
	abook num[50]; //abook 구조체
	int number;
	while (1)
	{

		printf("\n\n------------------------------------------------\n");
		printf("	   전화번호 입력 프로그램			\n");
		printf("-------------------- 메뉴 ----------------------\n\n");
		printf(" 1. 전화번호 입력	     \n");
		printf(" 2. 전화번호 전체 출력\n");
		printf(" 3. 전화번호 검색       \n");
		printf(" 4. 전화번호 삭제       \n");
		printf(" 5. 전화번호 변경       \n");
		printf(" 6. 종료                   \n");
		printf("----------------------------------------------- \n");

		printf("  선택 >>  ");
		scanf_s("%d", &number);

		if (number <= 0)	//0보다 작은수 입력시
		{
			printf("다시 입력 하세요 \n");
		}
		if (number > 0)
		{

			switch (number)
			{
			case 1:
			{
				InputPhoneData(num); break; //1입력함수
			}
			case 2:
			{
				ShowAllData(num); break; //2출력 함수
			}
			case 3:
			{
				SearchPhoneData(num); break;//3검색함수
			}
			case 4:
			{
				DeletePhoneData(num); break;//4삭제함수
			}
			case 5:
			{
				CrystalPhone(num); break; //5.수정함수
			}
			default:  //종료
			{
				printf("종료 입니다. \n");
				exit(1);
			}
			}
		}
	}

	return 0;
}

abook InputPhoneData(abook *pnum)				//1.입력함수 정의
{
	int i;  //for돌릴 변수

	printf("\n---------------------------------------------- \n");
	printf("\n              전화번호 입력 ①                      \n\n\n\n\n");

	for (i = 0; i < bookmas; i++)
	{
		printf("이름[%d]: ", i + 1);
		scanf_s("%s", pnum[i].name, sizeof(pnum[i].name)); // char에는 &안함-배열은 주소를 가지고있음
		getchar();

		printf("전화 번호[%d]: ", i + 1);
		scanf_s("%s", pnum[i].tel, sizeof(pnum[i].tel));	//주소를 알려줘야 한다.
		getchar();

		printf("\n");
	}
	return *pnum;
}

abook ShowAllData(abook *pnum)				//출력함수 정의
{
	int i;

	printf("---------------------------------------------- \n");
	printf("                 전화번호 전체 출력 ②                      \n\n\n\n\n");

	for (i = 0; i < bookmas; i++)
	{
		if (pnum[i].tel == NULL) // 삭제된 전화번호  처리
		{
			printf("");
		}
		else { printf("이름과 전화번호 출력: %s , %s \n", pnum[i].name, pnum[i].tel); }
	}
	printf("반복 횟수: %d", bookmas);

	return	*pnum;
}
abook SearchPhoneData(abook *pnum)						//검색기능
{
	char name[munjasu]; //비교대상 이름 입력변수
	int i;

	printf("----------------------------------------------\n");
	printf("                  전화번호검색 ③                      \n\n\n\n\n");

	printf("검색할 이름: ");
	scanf_s("%s", name, sizeof(name));
	getchar();

	for (i = 0; i < bookmas; i++)
	{
		if (strncmp(pnum[i].name, name, 20) == 0)			//abook의두개를 비교한다. 
		{
			printf("이름[%d]: %s \n", i + 1, pnum[i].name);
			printf("전화번호[%d]: %s \n", i + 1, pnum[i].tel);
		}
	}
	return *pnum;
}
abook DeletePhoneData(abook *pnum)
{
	char name[munjasu];
	int i;
	printf("----------------------------------------------\n");
	printf("                  전화번호 삭제 ④                     \n");
	printf("이름 검색후 삭제: ");
	scanf_s("%s", name, sizeof(name));
	getchar();

	for (i = 0; i < bookmas; i++)
	{
		if (strncmp(pnum[i].name, name, 20) == 0)			//구조체의name과 비교
		{
			printf("이름[%d]: %s \n", i + 1, pnum[i].name);
			printf("전화번호[%d]: %s \n", i + 1, pnum[i].tel);

			*pnum[i].name = NULL;
			*pnum[i].tel = NULL; //int 형 0으로 바뀜

			printf("삭제되었습니다. ");
		}
	}
	return *pnum;
}

void CrystalPhone(abook *pnum)//5.수정함수
{
	char name[munjasu];		//이름 저장
	int i;

	printf("----------------------------------------------\n");
	printf("                  전화번호 수정 ④                     \n");
	printf(" 전화번호 수정할 이름 입력 : ");
	scanf_s("%s", name, sizeof(name));
	//있는 이름인지검색 
	getchar();

	for (i = 0; i < bookmas; i++)
	{
		if (strncmp(pnum[i].name, name, 20) == 0)			//abook의두개를 비교한다. 
		{
			printf("이름[%d]: %s \n", i + 1, pnum[i].name);
			printf("전화번호[%d]: %s \n", i + 1, pnum[i].tel);

			*pnum[i].tel = NULL; //번호 삭제

			printf("수정할 전화번호:");
			scanf_s("%s", pnum[i].tel, sizeof(pnum[i].tel));
			printf("\n 수정이 완료 되었습니다. ");
			getchar();
			continue;
		}
	}
}
