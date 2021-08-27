#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>

//int mymax(int a, int b)
//{
//	cout << "max a: " << a << endl;
//	cout << "max b: " << b << endl;
//	if (a >= b)
//		return a;
//	else
//		return b;
//	
//	//return (a > b) ? a : b;
//}

template <typename T> T mymax(T a, T b)
{
	static int count = 0;
	count++;
	cout << "불린 횟수 : " << count << endl;
	cout << "max a: " << a << endl;
	cout << "max b: " << b << endl;
	if (a >= b)
		return a;
	else
		return b;
}

template <typename S> void myswap(S& a, S& b)
{
	S temp;
	temp = a;
	a = b;
	b = temp;
}

//클래스 템플릿 정의
template <typename T> class CMyData
{
	T data;
public:
	CMyData(T param) { data = param; }
	T GetData() { return data; }
	void SetData(T p) { data = p; }

	/*
	CMyData a;
	CMyData B;
	a + B // 연산자 오버로딩
		1) 일반함수
		2) 멤버함수 (우선순위)
	a.operator+(b)
	*/
	CMyData operator+(CMyData& param)
	{
		data = data + param.data
	}
};

template <typename T> T add(T a, T b)
{
	return a + b;
}

int add(int a, int b)
{
	return a + b;
}

//void myswap(int& a, int& b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}

//
//double add(double a, double b)
//{
//	return a + b;
//}
//
//string add(string a, string b)
//{
//	return a + b;
//}

template <typename T> 
class MyStack 
{
private:
	int m_top = -1;
	int m_size = 0;
	T* m_buff = NULL;
public:
	MyStack(int max)
	{
		m_size = max;
		m_buff = new T[m_size];
	}

	~MyStack()
	{
		delete[] m_buff;
	}

	int Push(T value)
	{
		//check max
		if (m_top == (m_size - 1)) //return 0;
		{
			cout << "Overflow : Program Terminated\n";
			exit(EXIT_FAILURE);
		}
		m_top++;
		m_buff[m_top] = value;
		return 1;
	}

	T Pop(void)
	{
		//check empty
		if (m_top == -1) //return T(0);
		{
			cout << "Underflow : Program Terminated\n";
			exit(EXIT_FAILURE);
		}

		T temp = m_buff[m_top];
		m_top--;
		return temp;
	}
};

class Human
{
public:
	string name;
	int age;

	Human()
	{
		this->name = "이름없음";
		this->age = 0;
	}
	Human(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void PrintData()
	{
		cout << name << ", " << age << endl;
	}
};

int main()
{
	//함수 템플릿1
	if (1)
	{
		cout << add(10, 20) << endl; // int 
		cout << add(10.5, 20.6) << endl; // double 

		//cout << add("대한민국", "만세") << endl; //error
		//    error: char*가 operator + 재정의 되어 있지 않음
		//string x = "대한민국" + "만세";

		string a = "대한민국";
		string b = "만세";
		cout << add(a, b) << endl;//string : operator + 재정의 되어 있음

		/////////////////////
		CMyData<double> x(22);
		CMyData<double> y(33);
		cout << add(x, y).GetData() << endl;
		//		add(x, y); CMyData가 operator+ 재정의가 되지 않음//error 
		//		==> operator + 재정의했음


	}

	//함수 템플릿 2
	if (0)
	{
		///////////////////////////////////////////
		//1. 암시적 추론(by 컴파일러)
		cout << mymax(10, 20) << endl;
		cout << mymax(30, 40) << endl;
		cout << mymax(50, 60) << endl;
		cout << mymax(10.5, 20.9) << endl;
		cout << mymax('c', 'a') << endl; // char

		//2. 명시적 지정(by 인간)
		/// /////////////////////////////////////////
		//cout << mymax('c', '10') >> endl; // char error
		cout << mymax<int>(10, 20.9) << endl; //int
		cout << mymax<double>(10, 20.9) << endl; // double
	}

	//함수 템플릿 3
	if (0)
	{
		int i = 50;
		int j = 10;
		cout << "Before " << "i =" << i << ", j =" << j << endl;
		myswap(i, j); // 저절로 int를 처리하는 myswap함수가 생성된다.
		cout << "after" << "j =" << j << ", i =" << i << endl;

		char a = 'a';
		char b = 'b';
		cout << "Before " << "a =" << a << ", b =" << b << endl;
		myswap(a, b); 
		cout << "after" << "b =" << b << ", a =" << a << endl;
	}

	//클래스 템플릿1
	if (0)
	{
		CMyData<int> a(100);
		cout << a.GetData() << endl;
		a.SetData(90);
		cout << a.GetData() << endl;
	
		CMyData<double> b(100.5);
		cout << b.GetData() << endl;
		b.SetData(90.3);
		cout << b.GetData() << endl;
	}

	//클래스 템플릿2 - 스택
	if (0)
	{
		MyStack<int> my(5);

		my.Push(1);
		my.Push(2);
		my.Push(3);
		my.Push(4);

		cout << my.Pop() << endl;
		cout << my.Pop() << endl;
		cout << my.Pop() << endl;
		cout << my.Pop() << endl;

		//////////////////////////////
		MyStack<string> your(5);

		string a = "호동이"; your.Push(a);
		string b = "재석이"; your.Push(b);
		string c = "재홍이"; your.Push(c);

		cout << your.Pop() << endl;
		cout << your.Pop() << endl;
		cout << your.Pop() << endl;
		cout << your.Pop() << endl; //run-time error : 이후 문장 실행안 됨


		//////////////////////////////
		MyStack<double> his(5);

		his.Push(1.23);
		his.Push(2.23);
		his.Push(3.23);

		cout << his.Pop() << endl;
		cout << his.Pop() << endl;
		cout << his.Pop() << endl;
	}

	//클래스 템플릿3 - 스택+class
	if (0) 
	{
		MyStack<Human> myFriend(5);
		Human a("길동이", 12);   myFriend.Push(a);
		Human b("Tom", 43);     myFriend.Push(b);
		Human c("기영이", 14);   myFriend.Push(c);

		Human p = myFriend.Pop();
		p.PrintData();
		myFriend.Pop().PrintData();
		myFriend.Pop().PrintData();

		//myFriend.Push(Human("길동이", 12));
		//myFriend.Push(Human("Tom", 43));
		//myFriend.Push(Human("기영이", 14));
	
		//myFriend.Pop().PrintData();
		//myFriend.Pop().PrintData();
		//myFriend.Pop().PrintData();
	}
	return 0;
}
#endif