#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <vector>
#include <list>
//#include "9_제너릭1.h"

typedef struct USERDATA
{
	int age;
	string name;
} USERDATA;

class Human
{
public:
	int age = 0;
	string name = "";

	Human() : age(-1), name("이름없음") {};  // 초기화 목록

	Human(int age, string name)
	{
		this->name = name;
		this->age = age;
	}
	void Print(void)
	{
		cout << name << ", " << age << endl;
	}
};

int main()
{
	//vector + 구조체
	if (1)
	{
		int a;
		a = 10;

		int b = 20;

		std::vector<USERDATA> vec(3);
	
		vec[0] = USERDATA{ 10, "영희" };
		vec[1] = USERDATA{ 20, "철수" };
		vec[2] = USERDATA{ 33, "기영이" };

		//1. []연산자
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i].age;
			cout << vec[i].name;
		}

		//2. 범위기반 for문 
		for (auto& n : vec)
		{
			cout << n.age << ", " << n.name << endl;
		}

		//3. 반복자 사용
		auto p1 = begin(vec); /// p1 = vec.begin();
		while (p1 != end(vec))
		{
			cout << p1->age << ", " << p1->name << endl;
			p1++;
		}

		//////////////////////
		//2명추가
		USERDATA a = {};
		vec.push_back(USERDATA{ 40,"김연아" });
		vec.push_back(USERDATA{ 200,"김수안무" });

		for (auto& n : vec)
		{
			cout << n.age << "," << n.name << endl;
		}
		cout << endl;
			
	}

	//vector + 클래스
	if (0)
	{
		vector<Human> vec; // (3);

		//vec[0] = Human(10, "기영이");
		//vec[1] = Human(20, "연아");
		//vec[2] = Human(30, "철수");

		for (auto& n : vec) n.Print();
		cout << endl;
		////////////////////////
		vec.push_back(Human(40, "엄마"));
		vec.push_back(Human(50, "연아"));
		vec.push_back(Human(30, "WOGHD"));

		for (auto& n : vec) n.Print();
		cout << endl;
	}

	return 0;
}
#endif