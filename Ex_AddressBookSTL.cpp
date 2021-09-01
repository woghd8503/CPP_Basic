#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/////////////////////////////////////////////////////////////////////////
// �ּҷ��� ����� ������ ����
#define DATA_FILE_NAME "c:\\Temp\\AddrBookSTL.dat"

/////////////////////////////////////////////////////////////////////////
class UserData
{
public:
	UserData() { }
	UserData(string strName, int nAge, int nGender)
	{
		this->strName = strName;
		this->nAge = nAge;
		this->nGender = nGender;
	}

	~UserData()
	{

	}

	string strName = "";		// �̸�
	int nAge = 0;				// ����
	int nGender = 0;			// ����

	//for ��ũ�� ����Ʈ
	//UserData* pNext = NULL;	//���� ��Ҹ� ����Ű�� ��ũ
	//UserData* pPrev = NULL;	//���� ��Ҹ� ����Ű�� ��ũ

	void PrintData()
	{
		cout << strName << ", ";
		cout << nAge << "��, ";
		cout << (nGender ? "����" : "����");
		cout << endl;
	}

	// a == b
	// a.operator==(b)
	int operator==(const UserData& param)
	{
		if (this->strName == param.strName)
			return 1;
		else
			return 0;
	}
};

//�迭�� ó��
//#define		MAX_BOOKCOUNT	50
int			g_nCount = 0;
//UserData	g_AddrBook[MAX_BOOKCOUNT];//�����޸�

//��ũ�� ����Ʈ�� ó��
//UserData* g_HeapAddrBook;//�����޸�

vector<UserData> udata; // ���� �迭


///////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �迭�� �߰��ϴ� �Լ�
void Add()
{
	string strName = "";
	int nAge = -1;
	int nGender = -1;
	//if (g_nCount + 1 > MAX_BOOKCOUNT)
	//{
	//	cout << "�ԷºҰ� : �뷮�ʰ�" << endl;
	//	return;
	//}

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> strName;

	cout << "���̸� �Է��ϼ��� : ";
	cin >> nAge;

	cout << "������ �Է��ϼ���(����:0, ����:1) : ";
	cin >> nGender;

	udata.push_back(UserData(strName, nAge, nGender));
	
	//g_nCount++;//�����Է¿�
}

/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϴ� �Լ�
void Search()
{
	string strName;

	cout << "�˻��� �̸��� �Է��ϼ��� : ";
	cin >> strName;

	// 1. �˰��� 
	/////////////////////////
	 auto p = std::find(begin(udata), end(udata), UserData(strName, 0, 0));
	 if (p == end(udata))
		 cout << "�����͸� ã�� �� �����ϴ�." << endl;
	 else
		 p->PrintData();
	

	 //2.Container 
	////////////////////
	bool isHit = false;
	//for (auto& n : udata)
	//{
	//	if (strName == n.strName)
	//	{
	//		n.PrintData();
	//		isHit = true;
	//	}
	//}

	//auto p = begin(udata);
	//auto p2 = end(udata);

	//while (p != p2)
	//{
	//	if (p->strName == strName)
	//	{
	//		p->PrintData();
	//		isHit = true;
	//		break;
	//	}
	//	p++;
	//}	
}

/////////////////////////////////////////////////////////////////////////
// �迭�� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
void PrintAll()
{
	if (udata.size() == 0)
	{
		cout << "����� �����Ͱ� �����ϴ�" << endl;
		return;
	}

	// 1. �迭
	//for (int i = 0; i < udata.size(); i++)
	//{
	//	udata[i].PrintData();
	//}

	// 2. ���� ��� for���� �̿�
	//for (auto& n : udata)
	//{
	//	n.PrintData();
	//}

	// 3. �ݺ��� ���
	auto p = begin(udata);
	while(p != end(udata))
	{
		p->PrintData();
		p++;
	}
}

/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �ڷḦ �˻��ϰ� �����ϴ� �Լ�
void Remove()
{
	bool isDeleted = false;
	string strName;
	cout << "������ �̸��� �Է��ϼ��� : ";
	cin >> strName;

	// 1. �ݺ���
	/////////////////////////////
	//auto p1 = begin(udata);
	//while (p1 != end(udata))
	//{
	//	if (strName == p1->strName)
	//	{
	//		udata.erase(p1);
	//		isDeleted = true;
	//		break;
	//	}
	//	p1++;		
	//}

	// 2. �˰��� 
    /////////////////////////
	auto p = std::find(begin(udata), end(udata), UserData(strName, 0, 0));
	if (p == end(udata))
	{
		cout << "�����͸� ã�� �� �����ϴ�." << endl;
		isDeleted = true;
	}
	else
		udata.erase(p);

	if (isDeleted != true)
	{
		cout << "������ �����͸� ã�� �� �����ϴ�" << endl;
		isDeleted = false;
	}
}

/////////////////////////////////////////////////////////////////////////
// �޴��� ����ϴ� UI �Լ�
int PrintUI()
{
	int nInput = 0;

	cout << "===================================================\n";
	cout << "��ȭ��ȣ��(Array)\n";
	cout << "---------------------------------------------------\n";
	cout << "[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ����\t [0] ����\n";
	cout << "===================================================\n";

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	cin >> nInput;
	return nInput;
}

/////////////////////////////////////////////////////////////////////////
// ������ ���Ͽ��� ������ �о�� �迭�� �ϼ��ϴ� �Լ�
int LoadList(string strFileName)
{
	ifstream f;
	f.open(strFileName, std::ios::binary);

	if (f.is_open())
	{
		//��� ����
		int count = 0;
		f >> count;
		//������ ����
		for (int i = 0; i < count; i++)
		{
			//f.read((char*))(g_AddrBook + i), sizeof(UserData);


			// �����޸𸮸� ��Ƽ� ���⿡ �о�´�
			// 1. ���Ͽ��� �о�� ����(buff)�� �����.
			UserData* buff = new UserData;
			
			// 2. �� �������� ���Ͽ��� 1���� ������ �д´�.

			// ���Ͽ��� �д´�
			f.read((char*)buff, sizeof(UserData));
			
			// 3. �����̳ʿ� 1���� ������ �ִ´�.
			//�����̳ʿ� push ��
			udata.push_back( *buff );
		}
		f.close();
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////
// �迭 ���·� �����ϴ� ������ ���Ͽ� �����ϴ� �Լ�
int SaveList(string strFileName)
{
	ofstream f;
	f.open(strFileName, std::ios::binary);

	if (f.is_open())
	{
		//��� ����
		f << udata.size();
		//������ ����
		for (auto& item : udata)
		{
			f.write((const char*)&item, sizeof(UserData));
		}
		f.close();
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////
int main()
{
	int nMenu = 0;
	LoadList(DATA_FILE_NAME);

	// ���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add
			Add();
			break;

		case 2:		  // Search
			Search();
			break;

		case 3:		 // Print all
			PrintAll();
			break;

		case 4:		  // Remove
			Remove();
			break;

		default:
			cout << "�������� �ʴ� �޴��Դϴ�\n\n";
		}
	}

	// ���� ���� ���Ϸ� �����ϰ� �޸𸮸� �����Ѵ�.
	SaveList(DATA_FILE_NAME);
	return 0;
}
#endif