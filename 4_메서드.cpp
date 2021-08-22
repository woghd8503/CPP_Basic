#define ON_MAIN 
#ifdef ON_MAIN

#include <stdio.h>  // C header
#include <iostream> // C++ header

using namespace std;



class CTest
{
public:

	CTest(int a)
	{
		m_nData = a;
		m_nCount++;//생성자가 불린 횟수
	}

	int m_nData; // 객체마다 따로 생성됨

	//정적 멤버 변수 선언(정의는 아니다)
	static int m_nCount;//지금까지 CTest객체가 생성된 횟수
	
	int GetCount()
	{
		return m_nCount;
	}
};

//정적 멤버 변수 정의
int CTest::m_nCount = 0;

class CTest
{
public:
	int m_nData;
	int m_nData2;

	CTest() : m_nData(10), m_nData2(20)  // 초기화 목록
	{
		cout << "CTest()의 생성자" << endl;
		//m_nData = 10; // 초기화 방법 1
		//m_nData2 = 20; // 초기화 방법 1
	}

	~CTest()
	{
		cout << "~CTest()의 소멸자" << endl;
	}

	void PrintData(void)
	{
		cout << m_nData << endl;
		cout << m_nData2 << endl;
	}
};

int main()
{
	//멤버변수의 초기화
	if (0)
	{
		cout << "메인시작" << endl;
		int a;		// 4B 메모리 할당
		CTest b;	// 20B 메모리 할당 --> b의 생성자 호출됨

		b.PrintData();
		//...
		cout << "메인끝" << endl;
	}//--> 1) a의 메모리 해지
     //	   2) b의 소멸자 호출됨
	 //    3) b의 메모리 해지

	//Static 멤버
	if (1)
	{
		CTest a(5);
		CTest b(10);
		CTest c(100);

		cout << a.m_nData << endl;
		cout << b.m_nData << endl;
		cout << c.m_nData << endl;
		cout << a.m_nCount << endl;

	}
	return 0;
}


#endif