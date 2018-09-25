
#include "stdafx.h"
#include "dvd_member.h"
/*
#include "stdlib.h"
#include <string.h>*/

extern int i, j, z;

void new_member(membership *pa);							//1.신규 회원가입등록 선언
void member_search(membership *pa);						//2.고객 검색 선언
//1.신규 회원가입등록정의
void new_member(membership *pa	) 
{
	char aid[20] = { NULL };
	int sw = 0;		//switch 변수

	for (i = 0; i < people; i++)		//id 겹치지 않기위해
	{
		sw = 0;
		printf("\n---------- 1. 신규 회원가입등록 (%d) ----------", i + 1);
		printf("\nID 등록: ");
		scanf_s("%s", aid, sizeof(aid));
		getchar();

		for (j = 0; j < people; j++)
		{
			if (strcmp(pa[j].id_name, aid) == 0)		//ID 비교 조건문
			{
				printf("해당 ID는 사용 중에 있습니다.다른 ID를 입력해주세요.");
				sw = 1;
				break;
			}
		}
		if (sw== 0){
			strcpy_s(pa[i].id_name, aid);			//구조체에 id를 저장할수 있도록 함
			printf("이름 등록: ");
			scanf_s("%s", pa[i].name, sizeof(pa[i].name));
			getchar();
			printf("전화번호 등록: ");
			scanf_s("%s", pa[i].number, sizeof(pa[i].number));
			getchar();
			printf("\n----------------------------------------------");
		}
	}
}
//2. 고객검색 정의
void member_search(membership *pa)
{
	char aid[20] = { NULL };
	printf("\n--------------- 2. 고객 검색 ---------------");
	printf("\n고객검색 ID:");
	scanf_s("%s", aid, sizeof(aid));
	getchar();
	int sw = 0;   //switch 변수

	for (i = 0; i < people; i++)
	{
		if (strcmp(pa[i].id_name, aid) == 0) {
			printf("\n-------------- 검색된 고객정보 --------------");
			printf("\nID: %s", pa[i].id_name);
			printf("\n이름: %s", pa[i].name);
			printf("\n전화번호: %s", pa[i].number);
			sw = 1;
		}
	}
	if(sw==0){
		printf("\n 없는 ID입니다."); 
	}
}