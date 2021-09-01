#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <vector>
int foo()
{
	if (1)// 실패가 났다고 가정하면
	   //return -1;
	//1. C언어에서의 에러 처리
	   //return -1;//실패한 경우, 약속된 값(-1)을 반환함
	   //1) 이 값이 에러인지, 연산의 결과인지 혼란스러울 수 있음
	   //2) 함수가 에러를 반환할 때, 호출자가 반드시 에러를 처리하도록 강제할 수 없음
	   // 
	//2. C++의 예외처리 (반환값과 에러를 분리함)
		throw "홍길동";   //실패한 경우, 반환이 아닌 예외를 throw함
				 // : 리턴값과 실패의 전달이 분리됨

		//계산...
	int count = -1;
	return count;

}

//예외전용 클래스
class MyMemoryException : public std::exception
{
public:
	virtual char const* what() const //noexcept
	{
		return "메모리 예외가 발생했습니다. ";
	}
};
int foo2()
{
	if (1)//실패
		throw MyMemoryException();
	//...
	return 0;
}

int main()
{
	//예외처리
	if (0)
	{
		try
		{
			foo();
		}
		catch (int a) //int형의 예외를 처리하겠다.
		{
			cout << "예외발생(int) " << a << endl;
		}
		catch (...) //anytype 예외를 처리하겠다.
		{
			cout << " 예외발생(anytype) " << endl;
		}
		cout << "bye" << endl;
	}

	//예외전용 클래스사용(exception)
	if (1)
	{
		try
		{

			foo2();
		}
		catch (const MyMemoryException& m)
		{
			cout << m.what() << endl;
		}
	}
	cout << "bye" << endl;

	//c++ 표준예외클래스
	if (0)
	{
		//1.(std::bad_alloc)
		int* p = NULL;
		try
		{

			p = new int[1000]; //항상 성공한다는 보장이 없음
		}
		catch (std::bad_alloc& e)
		{
			cout << "std:: bad_alloc 발생 : ";
			cout << e.what() << endl;
		}

		////////////////////////////////////////////
		//2.(std::out_of_range)
		vector<int> v = { 1,2,3 };
		try
		{
			v.at(5) = 5; // 잘못된 인덱스
		}
		catch (std::out_of_range& e)
		{
			cout << "std:: bad_alloc 발생 : ";
			cout << e.what() << endl;
		}
		cout << "bye bye" << endl;
	}

	//noexcept
	if (1)
	{
		void xxx();               // 이 함수는 예외가 있을수도 , 없을수도 
		void yyy() throw(int);      // 이 함수는 int형의 예외가능성이 있다.
		void zzz() throw();         // 이 함수는 예외가 없다

		//c++98
		void aaa() noexcept(false);      //이 함수는 예외가 있다
		void bbb() noexcept(true);      //이 함수는 예외가 없다
		////////////////////////
		void ccc() noexcept;         //이 함수는 예외가 없다
		void ddd();         //이 함수는 예외가 있다

		//////////////////////////
		bool b = noexcept(ddd());
		cout << b << endl;
	}

	return 0;
	//
}

#endif