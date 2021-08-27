#include <iostream>

//#define ON_MAIN 
#ifdef ON_MAIN
using namespace std;

/*
함수 바인딩
 : 함수의 호출과 실제 어떤 함수가 연결될 지 결정하는 것
 --------------------------
 1) 정적 바인딩 (기본)
	==> early binding
	==> 변수의 타입을 보고 바인딩을 결정함(컴파일 타입)
---------------------------
	2) 동적 바인딩 (virtual 처리해야 함)
	==> late binding
	==> 변수가 가르키는(포인팅) 실객체를 보고 바인딩을 결정함(실행 타임)

*/
class Animal
{
public:
	//1. 일반 멤버함수(정적 바인딩)
	//void Cry() { cout << "운다" << endl; }

	//2. 가상 멤버함수(동적 바인딩)
	//virtual void Cry() { cout << "운다" << endl; }

	//3. 순수 가상함수(pure virtual)
	virtual void Cry() = 0;//인터페이스 상속
};

class Dog : public Animal
{
public:
	void Cry() { cout << "멍멍멍" << endl; }
};

class Cat : public Animal
{
public:
	void Cry() { cout << "야옹야옹" << endl; }
};

main()
{
	if (1)
	{
		class Animal
		{
		public:
			string name;
			int age;
		};

		class Dog : public Animal
		{
		public:
			int age;
			int color;
			string name;
		};

		Dog dog;
		dog.name = "꿀띠";
		dog.age = 6;
		dog.color = 10;

		Animal ani;
		ani.name = "냐옹이";

		//Dog* p;
		//p = &dog;       //ok
		//p = &ani;		// error

		//Animal* p2;
		//p2 = &dog;	 //ok
		//p2 = &ani;   //당근 ok

		////////////////////////
		//1. upcasting ( 형상향 )
		// : 원래 포인터는 다른 타입의 주소를 담을 수 없다
		// : 하지만, 부모 포인터는 자식의 주소를 담을 수 있다.(=upcasting)
		Animal* pAni = &dog;
		pAni->age = 7;

		//2 downcasting ( 형하향 )
		//Dog* pDog = pAni;//error
		Dog* pDog = (Dog*)pAni;//downcasting은 "강제" 형변환해야 함
		pDog->age = 9;
		pDog->color = 20;
	}

	//함수 오버라이드 + 가상함수(virtual)
	if (0)
	{
		/////////////////////
		// 다형성
		Dog d;
		d.Cry();

		Cat c;
		c.Cry();

		////////////////////
		Animal* p;
		p = &d; //upcasting
		p->Cry();

		p = &c; //upcasting
		p->Cry();

		////////////////////
		//Animal a;// error : 순수 가상클래스는 객체를 만들 수 없다
	}

	//가상 소멸자
	if (1)
	{
		class Base
		{
		public:
			Base() { cout << "Base()" << endl; }
			//~ Base() { cout << "Base()" << endl; }
			virtual ~ Base() { cout << "Base()" << endl; }
		};

		class Derived : public Base
		{
		public:
			Derived() 
			{
				cout << "Derived()" << endl;
				pData1 = new int;
				pData2 = new int[20];
			}
			~Derived() 
			{
				cout << "Derived() - 자원획득" << endl;
				delete pData1;
				delete[] pData2;
			}

			int* pData1;
			int* pData2;
		};

		///////////
		//Derived x;

		Base* p = new Derived;
		//...
		delete p;//소멸자 -> 정적바인딩 ==> 동적바인딩(virtual)
	}

	return 0;
}

#endif