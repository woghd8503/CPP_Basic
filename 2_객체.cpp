#define ON_MAIN 
#ifdef ON_MAIN

#include <stdio.h>  // C header
#include <iostream> // C++ header

using namespace std;

typedef struct USERDATA
{
	int nAge;
	char szName[32];

	void PrintData(USERDATA* p)
	{
		printf("%d,%s\n", nAge, szName);
	}


} USERDATA; // int, char '이형'의 데이터를 USERDATA로 묶은것

void PrintData(USERDATA* p)
{
	printf("%d, %s\n", p->nAge, p->szName);
}
int main()
{
	// 구조체(=사용자정의 데이터)
	if (1)
	{

		USERDATA kim = { 20, "김철수" };
		PrintData(&kim);
		//printf("%d, %s\n", kim.nAge, kim.szName);
	}

	//객체
	if (1)
	{
		class Human
		{
		public:
			//Human() { ; } // 디폴트 생성자 (by Compiler)
			//~Human() { ; } // 디폴트 소멸자 (by Compiler)

			int nAge;
			char szName[33];

			void PrintData()
			{
				printf("%d, %s\n", nAge, szName);
			}
		};

		Human lee = { 33, "이길동" };
		lee.PrintData();
		
	}
	return 0;
}

#endif