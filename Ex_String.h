#pragma once

class MyString
{
public:
	MyString(); // �⺻ ������
	MyString(const char* pszParam); // ��ȯ ������
	MyString(const MyString& pszParam); // ���� ������

	~MyString();
	//������ �����ε�
	// left = right
	// left operator=(right);
	MyString& operator=(const MyString& rhs);

	// ������� ����(=Ŭ������ �������)
	static int m_nCount;  // ������� ������ �ν��Ͻ��� ���� ����

private:
	char* m_pszData;//�����޸�(4B)-->malloc/free
	int m_nLength;//���ڿ��� ����
	//char szData[100];//�����޸�

public:
	int SetString(const char* pszParam);
	const char* GetString() const;
private:
	void Release();//���� �޸� �����Լ�
};