#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <vector>
#include <list>
//#include "9_���ʸ�1.h"

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

	Human() : age(-1), name("�̸�����") {};  // �ʱ�ȭ ���

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
	//vector + ����ü
	if (1)
	{
		int a;
		a = 10;

		int b = 20;

		std::vector<USERDATA> vec(3);
	
		vec[0] = USERDATA{ 10, "����" };
		vec[1] = USERDATA{ 20, "ö��" };
		vec[2] = USERDATA{ 33, "�⿵��" };

		//1. []������
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i].age;
			cout << vec[i].name;
		}

		//2. ������� for�� 
		for (auto& n : vec)
		{
			cout << n.age << ", " << n.name << endl;
		}

		//3. �ݺ��� ���
		auto p1 = begin(vec); /// p1 = vec.begin();
		while (p1 != end(vec))
		{
			cout << p1->age << ", " << p1->name << endl;
			p1++;
		}

		//////////////////////
		//2���߰�
		USERDATA a = {};
		vec.push_back(USERDATA{ 40,"�迬��" });
		vec.push_back(USERDATA{ 200,"����ȹ�" });

		for (auto& n : vec)
		{
			cout << n.age << "," << n.name << endl;
		}
		cout << endl;
			
	}

	//vector + Ŭ����
	if (0)
	{
		vector<Human> vec; // (3);

		//vec[0] = Human(10, "�⿵��");
		//vec[1] = Human(20, "����");
		//vec[2] = Human(30, "ö��");

		for (auto& n : vec) n.Print();
		cout << endl;
		////////////////////////
		vec.push_back(Human(40, "����"));
		vec.push_back(Human(50, "����"));
		vec.push_back(Human(30, "WOGHD"));

		for (auto& n : vec) n.Print();
		cout << endl;
	}

	return 0;
}
#endif