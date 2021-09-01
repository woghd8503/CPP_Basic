#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/////////////////////////////////////////////////////////////////////////
// 주소록이 저장될 데이터 파일
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

	string strName = "";		// 이름
	int nAge = 0;				// 나이
	int nGender = 0;			// 성별

	//for 링크드 리스트
	//UserData* pNext = NULL;	//다음 요소를 가르키는 링크
	//UserData* pPrev = NULL;	//이전 요소를 가르키는 링크

	void PrintData()
	{
		cout << strName << ", ";
		cout << nAge << "세, ";
		cout << (nGender ? "여성" : "남성");
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

//배열로 처리
//#define		MAX_BOOKCOUNT	50
int			g_nCount = 0;
//UserData	g_AddrBook[MAX_BOOKCOUNT];//정적메모리

//링크드 리스트로 처리
//UserData* g_HeapAddrBook;//동적메모리

vector<UserData> udata; // 동적 배열


///////////////////////////////////////////////////////////////////////
// 이름을 입력받아 배열에 추가하는 함수
void Add()
{
	string strName = "";
	int nAge = -1;
	int nGender = -1;
	//if (g_nCount + 1 > MAX_BOOKCOUNT)
	//{
	//	cout << "입력불가 : 용량초과" << endl;
	//	return;
	//}

	cout << "이름을 입력하세요 : ";
	cin >> strName;

	cout << "나이를 입력하세요 : ";
	cin >> nAge;

	cout << "성별을 입력하세요(남성:0, 여성:1) : ";
	cin >> nGender;

	udata.push_back(UserData(strName, nAge, nGender));
	
	//g_nCount++;//다음입력용
}

/////////////////////////////////////////////////////////////////////////
// 특정 노드를 검색하는 함수
void Search()
{
	string strName;

	cout << "검색할 이름을 입력하세요 : ";
	cin >> strName;

	// 1. 알고리즘 
	/////////////////////////
	 auto p = std::find(begin(udata), end(udata), UserData(strName, 0, 0));
	 if (p == end(udata))
		 cout << "데이터를 찾을 수 없습니다." << endl;
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
// 배열에 들어있는 모든 데이터를 화면에 출력하는 함수
void PrintAll()
{
	if (udata.size() == 0)
	{
		cout << "출력할 데이터가 없습니다" << endl;
		return;
	}

	// 1. 배열
	//for (int i = 0; i < udata.size(); i++)
	//{
	//	udata[i].PrintData();
	//}

	// 2. 범위 기반 for문을 이용
	//for (auto& n : udata)
	//{
	//	n.PrintData();
	//}

	// 3. 반복자 사용
	auto p = begin(udata);
	while(p != end(udata))
	{
		p->PrintData();
		p++;
	}
}

/////////////////////////////////////////////////////////////////////////
// 이름을 입력받아 자료를 검색하고 삭제하는 함수
void Remove()
{
	bool isDeleted = false;
	string strName;
	cout << "삭제할 이름을 입력하세요 : ";
	cin >> strName;

	// 1. 반복자
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

	// 2. 알고리즘 
    /////////////////////////
	auto p = std::find(begin(udata), end(udata), UserData(strName, 0, 0));
	if (p == end(udata))
	{
		cout << "데이터를 찾을 수 없습니다." << endl;
		isDeleted = true;
	}
	else
		udata.erase(p);

	if (isDeleted != true)
	{
		cout << "삭제할 데이터를 찾을 수 없습니다" << endl;
		isDeleted = false;
	}
}

/////////////////////////////////////////////////////////////////////////
// 메뉴를 출력하는 UI 함수
int PrintUI()
{
	int nInput = 0;

	cout << "===================================================\n";
	cout << "전화번호부(Array)\n";
	cout << "---------------------------------------------------\n";
	cout << "[1] 추가\t [2] 검색\t [3] 전체보기\t [4] 삭제\t [0] 종료\n";
	cout << "===================================================\n";

	// 사용자가 선택한 메뉴의 값을 반환한다.
	cin >> nInput;
	return nInput;
}

/////////////////////////////////////////////////////////////////////////
// 데이터 파일에서 노드들을 읽어와 배열을 완성하는 함수
int LoadList(string strFileName)
{
	ifstream f;
	f.open(strFileName, std::ios::binary);

	if (f.is_open())
	{
		//헤더 정보
		int count = 0;
		f >> count;
		//데이터 정보
		for (int i = 0; i < count; i++)
		{
			//f.read((char*))(g_AddrBook + i), sizeof(UserData);


			// 동적메모리를 잡아서 여기에 읽어온다
			// 1. 파일에서 읽어올 공간(buff)을 만든다.
			UserData* buff = new UserData;
			
			// 2. 그 공간으로 파일에서 1명의 정보를 읽는다.

			// 파일에서 읽는다
			f.read((char*)buff, sizeof(UserData));
			
			// 3. 컨테이너에 1명의 정보를 넣는다.
			//컨테이너에 push 함
			udata.push_back( *buff );
		}
		f.close();
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////
// 배열 형태로 존재하는 정보를 파일에 저장하는 함수
int SaveList(string strFileName)
{
	ofstream f;
	f.open(strFileName, std::ios::binary);

	if (f.is_open())
	{
		//헤더 정보
		f << udata.size();
		//데이터 정보
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

	// 메인 이벤트 반복문
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
			cout << "지원하지 않는 메뉴입니다\n\n";
		}
	}

	// 종료 전에 파일로 저장하고 메모리를 해제한다.
	SaveList(DATA_FILE_NAME);
	return 0;
}
#endif