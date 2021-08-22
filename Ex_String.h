#pragma once

class MyString
{
public:
	MyString(); // 기본 생성자
	MyString(const char* pszParam); // 변환 생성자
	MyString(const MyString& pszParam); // 복사 생성자

	~MyString();
	//연산자 오버로딩
	// left = right
	// left operator=(right);
	MyString& operator=(const MyString& rhs);

	// 정적멤버 변수(=클래스의 멤버변수)
	static int m_nCount;  // 현재까지 생성된 인스턴스의 갯수 관리

private:
	char* m_pszData;//동적메모리(4B)-->malloc/free
	int m_nLength;//문자열의 길이
	//char szData[100];//정적메모리

public:
	int SetString(const char* pszParam);
	const char* GetString() const;
private:
	void Release();//동적 메모리 해제함수
};