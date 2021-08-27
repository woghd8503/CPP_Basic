#include <iostream>

//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#define DEFAULT_FARE 50000

class CPerson
{
public:
	CPerson() { }
	virtual ~CPerson() {
		cout << "virtual ~CPerson()" << endl;
	}

	// 요금 계산 인터페이스(순수 가상 함수)
	void CalcFare() { m_nFare = DEFAULT_FARE; };
	unsigned int GetFare() { return m_nFare; }

protected:
	unsigned int m_nFare = 0;
};

class CBaby : public CPerson 
{
public:// 0~7세
	void CalcFare() { m_nFare = 0; };// 100% 할인
};

class CChild : public CPerson
{
public:// 8~13세
	void CalcFare() { m_nFare = DEFAULT_FARE * 0.5; }; // 50% 할인
};

class CTeen : public CPerson
{
public:// 14~19세
	void CalcFare() { m_nFare = DEFAULT_FARE * 0.7; }; // 25% 할인
};

class CAdult : public CPerson
{
public:// 20세 이상
	void CalcFare() { m_nFare = DEFAULT_FARE; };
};

int main()
{
	cout << "=======================================" << endl;
	cout << "\t 에버랜드 요금 계산기" << endl;
	cout << "=======================================" << endl;

	int nCount = 0;
	cout << "총 몇 분이 입장하시나요? ";
	cin >> nCount;
	cout << "------------------------------" << endl;

	CPerson** arList = new CPerson * [nCount];
	int nAge = 0;

	// 1. 자료 입력: 사용자 입력에 따라서 생성할 객체 선택
	for (int i = 0; i < nCount; i++)
	{
		cout << i + 1 << "번의 나이를 입력하세요: ";;
		cin >> nAge;

		if (nAge < 8)
			arList[i] = new CBaby;
		else if (nAge < 14)
			arList[i] = new CChild;
		else if (nAge < 20)
			arList[i] = new CTeen;
		else
			arList[i] = new CAdult;

		arList[i]->CalcFare();
	}

	// 2. 자료 출력: 계산한 요금을 활용하는 부분
	int nFare = 0;
	int nTotal = 0;
	cout << "------------------------------" << endl;
	for (int i = 0; i < nCount; i++)
	{
		nFare = arList[i]->GetFare();
		nTotal += nFare;

		cout << i + 1 << "분의 요금은 " << nFare << "원" << endl;
	}
	cout << "------------------------------" << endl;
	cout << "총 요금 : " << nTotal << endl;
	cout << "------------------------------" << endl;

	// 3. 자료 삭제 및 종료
	for (int i = 0; i < nCount; i++)
	{
		delete arList[i];
	}
	delete[] arList;

	return 0;
}

#endif