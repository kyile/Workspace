//�ڴ���

//#include "BankingCommonDecl.h"
#include "Account.h"

	Account::Account() {}						 //�����ڰ� ���ǰ� �������� �����Ϸ��� ����Ʈ �����ڸ� �� �������
	Account::Account(int ID, int money, String name)		//�ʱ�ȭ �Ҽ�����/������....�Լ���� ��������//���⵵ const���ϼ� ����
		: accID(ID), AMOUNT(money)						//����̴ϼȶ�����...�ʱ�ȭ
	{
		//NAME = new char[strlen(name) + 1];
		//strcpy(NAME, name);//	���� NAME ������
		NAME = name;
	}
	/*Account::Account(const Account &copy)							//���� ���� ������
		:accID(copy.accID), AMOUNT(copy.AMOUNT)
	{
		NAME = new char[strlen(copy.NAME) + 1];
		strcpy(NAME, copy.NAME);
	}*///string
	/*Account& Account::operator=(const Account& copy)
	{
		accID = copy.accID;
		AMOUNT = copy.AMOUNT;

		delete[]NAME;
		NAME = new char[strlen(copy.NAME) + 1];
		strcpy(NAME, copy.NAME);
		return *this;
	}*///string
	void Account::Deposit(int money)
	{
		AMOUNT += money;
	}
	/*
	Account::~Account()							//�Ҹ���
	{
		delete []NAME;
	}*/
