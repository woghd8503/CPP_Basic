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
	cout << "�Ҹ� Ƚ�� : " << count << endl;
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

//Ŭ���� ���ø� ����
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
	a + B // ������ �����ε�
		1) �Ϲ��Լ�
		2) ����Լ� (�켱����)
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
		this->name = "�̸�����";
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
	//�Լ� ���ø�1
	if (1)
	{
		cout << add(10, 20) << endl; // int 
		cout << add(10.5, 20.6) << endl; // double 

		//cout << add("���ѹα�", "����") << endl; //error
		//    error: char*�� operator + ������ �Ǿ� ���� ����
		//string x = "���ѹα�" + "����";

		string a = "���ѹα�";
		string b = "����";
		cout << add(a, b) << endl;//string : operator + ������ �Ǿ� ����

		/////////////////////
		CMyData<double> x(22);
		CMyData<double> y(33);
		cout << add(x, y).GetData() << endl;
		//		add(x, y); CMyData�� operator+ �����ǰ� ���� ����//error 
		//		==> operator + ����������


	}

	//�Լ� ���ø� 2
	if (0)
	{
		///////////////////////////////////////////
		//1. �Ͻ��� �߷�(by �����Ϸ�)
		cout << mymax(10, 20) << endl;
		cout << mymax(30, 40) << endl;
		cout << mymax(50, 60) << endl;
		cout << mymax(10.5, 20.9) << endl;
		cout << mymax('c', 'a') << endl; // char

		//2. ����� ����(by �ΰ�)
		/// /////////////////////////////////////////
		//cout << mymax('c', '10') >> endl; // char error
		cout << mymax<int>(10, 20.9) << endl; //int
		cout << mymax<double>(10, 20.9) << endl; // double
	}

	//�Լ� ���ø� 3
	if (0)
	{
		int i = 50;
		int j = 10;
		cout << "Before " << "i =" << i << ", j =" << j << endl;
		myswap(i, j); // ������ int�� ó���ϴ� myswap�Լ��� �����ȴ�.
		cout << "after" << "j =" << j << ", i =" << i << endl;

		char a = 'a';
		char b = 'b';
		cout << "Before " << "a =" << a << ", b =" << b << endl;
		myswap(a, b); 
		cout << "after" << "b =" << b << ", a =" << a << endl;
	}

	//Ŭ���� ���ø�1
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

	//Ŭ���� ���ø�2 - ����
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

		string a = "ȣ����"; your.Push(a);
		string b = "�缮��"; your.Push(b);
		string c = "��ȫ��"; your.Push(c);

		cout << your.Pop() << endl;
		cout << your.Pop() << endl;
		cout << your.Pop() << endl;
		cout << your.Pop() << endl; //run-time error : ���� ���� ����� ��


		//////////////////////////////
		MyStack<double> his(5);

		his.Push(1.23);
		his.Push(2.23);
		his.Push(3.23);

		cout << his.Pop() << endl;
		cout << his.Pop() << endl;
		cout << his.Pop() << endl;
	}

	//Ŭ���� ���ø�3 - ����+class
	if (0) 
	{
		MyStack<Human> myFriend(5);
		Human a("�浿��", 12);   myFriend.Push(a);
		Human b("Tom", 43);     myFriend.Push(b);
		Human c("�⿵��", 14);   myFriend.Push(c);

		Human p = myFriend.Pop();
		p.PrintData();
		myFriend.Pop().PrintData();
		myFriend.Pop().PrintData();

		//myFriend.Push(Human("�浿��", 12));
		//myFriend.Push(Human("Tom", 43));
		//myFriend.Push(Human("�⿵��", 14));
	
		//myFriend.Pop().PrintData();
		//myFriend.Pop().PrintData();
		//myFriend.Pop().PrintData();
	}
	return 0;
}
#endif