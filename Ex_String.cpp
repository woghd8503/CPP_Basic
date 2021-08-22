#include <iostream> // C++ header
#include "Ex_String.h"

using namespace std;

int MyString::m_nCount = 0; // 정적멤버는 "정의"를 해줘야 됨  .17줄

//기본 생성자
MyString::MyString() 
	: m_nLength(0), m_pszData(NULL)
{
	m_nCount++;
	m_nLength = 0;
	m_pszData = NULL;
	cout << "MyString의 기본생성자" << endl;
}

//변환 생성자
MyString::MyString(const char* pszParam) 
	: m_nLength(0), m_pszData(NULL)
{
	m_nCount++;
	//m_nLength = 0;
	//m_pszData = NULL;
	cout << "MyString의 변환생성자" << endl;
	SetString(pszParam);
}

//복사 생성자
MyString::MyString(const MyString& pszParam)
	: m_nLength(0), m_pszData(NULL)
{
	//m_nLength = 0;
	//m_pszData = NULL;
	m_nCount++;
	cout << "MyString의 복사생성자" << endl;
	SetString(pszParam.GetString());
}

MyString::~MyString()
{
	m_nCount--;
	Release();
}

MyString& MyString::operator=(const MyString& right)
{
	// 자기 자신에 대한 대입이면 아무것도 하지 않는다.
	if (this != &right)
		this->SetString(right.GetString());

	return *this;
}

int MyString::SetString(const char* pszParam)
{
	Release(); //이전데이터 삭제

	if (pszParam == NULL)
		return 0;

	int nLength = strlen(pszParam);
	if (nLength == 0)
		return 0;

	m_pszData = new char[nLength + 1];
	strcpy_s(m_pszData, sizeof(char)*(nLength + 1), pszParam);
	
	m_nLength = nLength;

	return 0;
}

const char* MyString::GetString() const
{
	return m_pszData;
}

void MyString::Release() //동적 메모리 해제함수
{
	if(m_pszData != NULL)
	delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
};