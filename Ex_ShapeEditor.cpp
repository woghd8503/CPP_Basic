#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <vector> // 연속된 메모리
#include <list>   // 비연속된 메모리
/*
*  도형 편집기 예제
* ---------------------
* 1. 각 도형을 타입으로 만들면 편리하다(캡슐화)
*	ex) 사각형을 int 4개로 관리하기 보다는 캡슐로 만들어 줌
* 2. 모든 도형의 공통의 특징을 기반 클래스(Shape)에서 관리한다 (상속 : 재사용)
* 3. 여러 도형을 보관하기 위해 vector 를 사용한다
*	ex) vector<Rect*> v1;  //Rect만 관리한다
*	ex) vector<Circle*> v2;  //Circle만 관리한다
* 4. 모든 도형의 공통의 특징(Draw)는 반드시 기반 클래스(Shape)에도 있어야 한다
* 5. 기반 클래스의 함수 중 파생 클래스가 재정의 하게 되는 모든 함수는 "가상 함수"가 되어야 한다.(다형성)
*/

class Shape
{
public:
	int x, y;
	int color;
	virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Rect : public Shape
{
public:
	int w, h;
	virtual void Draw() override
	{
		cout << "Rect Draw" << endl;
	}
};

class Circle : public Shape
{
public:
	int r;
	virtual void Draw() override
	{
		cout << "Circle Draw" << endl; 
	}
};

class Triagle : public Shape
{
public:
	int r;
	virtual void Draw() override
	{
		cout << "Triagle Draw" << endl;
	}
};


int main()
{
	cout << "-------------------------------------------" << endl;
	cout << "	도형편집기" << endl;
	cout << "-------------------------------------------" << endl;
	//cout << "1.  Rect 그리기\t2. Circle 그리기\t9.All Draw" << endl;
	cout << "1.  Rect 그리기\t2. Circle 그리기\t3. Triangle 그리기\t9.All Draw" << endl;
	cout << "-------------------------------------------" << endl;

	//vector<Rect> v1;		//Rect 만 관리한다.
	//vector<Circle> v2;		//Circle 만 관리한다.

	//Rect v1[30];   //Rect 만 관리한다
	//Circle v2[30]; //Circle 만 관리한다.

	vector<Shape*> v;  //부모의 포인터로는 자식을 가르킬 수 있다(no error)
					   //자식의 포인터로는 부모를 가르킬 수 있다(error)
	//list<Shape*> v1;

	while (1)
	{
		int menu;
		cin >> menu; 

		switch (menu)
		{
		case 1://Rect 그리기
			v.push_back( new Rect );
			break;

		case 2://Circle 그리기
			v.push_back(new Circle);
			break;

		case 3://Triangle 그리기
			v.push_back(new Triagle);
			break;

		case 9://All Draw 

			for (auto& item : v)
			{
				item->Draw(); //정적 바인딩(기본) --> 동적바인딩(virtual)
				// : OCP(Open Close Principle)
				/*
   				 * 다형성 (Polymorphism)
				 * :  동일한 코드 표현(함수 호출)이 상황에 따라 다르게 동작하는 것
				 *
				 * OCP(Open Close Principle)
				 * : 기능 확장에는 열려 있고 (Open)
				 * : 코드 수정에는 닫혀 있어야 (Close)
				 * : 한다는 이론 (Principle)
				 * : ==> 다형성은 OCP를 만조할 수 있는 좋은 코드이다
				*/


			}

			break;

		default:
			cout << "잘못 입력하셨습니다.";
		}
	}
	return 0;
}

#endif