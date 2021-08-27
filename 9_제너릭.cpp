#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

int myCompare(int a, int b)
{
	return a > b; // <
}

int main()
{
	// 컨테이너
	if (0)
	{
		//1.배열 : 연속된 메모리 - 크기를 변경할 수 없다.
		int x[10] = { 1, 2, 3, 4, };
		
		//2. STL 배열 - 연속된 메모리
		std::array<int, 10> a = {1, 2, 3, 4, }; // 크기를 변경할 수 없다
		std::vector<int>    v = {1, 2, 3};      // 크기를 변경할 수 있다
		v.resize(5);

		//3. STL 리스트 - 연속되지 않은 메모리
		std::list<int> s = { 1, 2, 3 };

		////////////////////////////////////////////
		// *********** 컨테이너 *********** 
		////////////////////////////////////////////
		//1. 템플릿으로 만들어져 있다
		//
		//2. 멤버함수의 이름이 모두 동일하다
		//	1) 삽입 : push_front(), push_back(), insert() 
		//			(stack::push()만 지원)
		//			(vector는 앞에 삽입불가 --> push_front()없음-성능이슈)
		//	2) 제거 : pop_front(), pop_back(), erase() 
		//			(stack::pop()만 지원)
		//	3) 접근 : front(), back(), at()
		//			(stack::top()만 지원)
		//  ** 제거와 접근은 동시에 이뤄지지 않음

		//list<double> score;
		vector<int> score;
		for (int i = 0; i < 10; i++)
		{
			score.push_back(i * 10 + 0.1);
		}
		for (auto& n : score) // 범위기반 for(C++11)
		{
			cout << n << endl;
		}

		////////////////////////////////
		stack<int> my;
		my.push(10);
		my.push(20);
		
		printf("hi");//일반함수, 전역함수

		//int temp = s.pop_back(); //error : pop은 제거함, 리턴은 하지 않음
		int temp;
		temp = my.top();// 20 꺼내짐, 제거는 안함
		cout << temp << endl;
		temp = my.top();// 10 꺼내짐???? -> 여전히 20
		cout << temp << endl;

		my.pop();//제거
		temp = my.top();//접근
		cout << temp << endl;

		////////////////////////////////
		std::list<int> your = {1, 2, 3};
		your.pop_front();      //제거
		auto& n = your.front();//맨앞 요소로 접근
		cout << n << endl;     //2

		your.pop_front();      //제거

		n = your.back();	   //맨뒤 요소로 접근
		cout << n << endl;	   //2

	}

	// 반복자(iterator)
	if (0)
	{
		int x[10] = { 1, 2, 3, 4, 5, 6, 7, 9, 10 };//배열
		int* p1 = x;
		p1++;//2
		cout << p1 << endl;// 주소
		cout << *p1 << endl;//값 : 2

		auto p4 = begin(x); // 일반함수 (c++11)

		/////////////////////////////////////////
		//반복자
		//: 컨테이너의 요소를 가리키는 포인터와 유사한 객체
		//: ++, * 연산자를 재정의 해서 포인터와 유사하게 동작하도록 만든것
		//: 일반함수 begin()도 지원된다(c++11부터)
		//: 멤버함수 begin()을 통해서 꺼낼 수 있다
		//: std::vector<int>::iterator가 정확한 타입 (auto로 편리하게 사용)

		//std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 동적배열
		std::list<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 동적배열

		//std::vector<int>::iterator p2 = v.begin(); // 정식방법
		auto p2 = v.begin(); // 편법방법
		p2++;
		//cout << p2 << endl; // 주소
		cout << *p2 << endl; // 값 : 2
	
		///////////////////////////////
		auto p3 = begin(v); // 일반함수 (c++11)
		p3++;
		p3++;
		cout << *p3 << endl; // 값 : 3
	}

	// 반복자에서 꺼내기(begin()/end())
	if (0)
	{
		//std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::list<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		//int v[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		//std::vector<int>::iterator p1 = v.begin();//첫요소를 가르킴
		//std::vector<int>::iterator p2 = v.end();//마지막의 다음요소를 가르킴

		//멤버함수보다는 "일반함수"를 사용하면,
		//STL과 배열을 변경하면서 사용하기 용이함
		//auto p1 = v.begin();//첫요소를 가르킴
		//auto p2 = v.end();//마지막의 다음요소를 가르킴
		auto p1 = begin(v);//첫요소를 가르킴
		auto p2 = end(v);//마지막의 다음요소를 가르킴

		*p1 = 100;
		//*p2 = 100; // runtime error

		while(p1 != p2)
		{
			cout << *p1 << endl;
			p1++;
		}
	}

	// 컨테이너의 요소를 열거하는 3가지 방법
	if (0)
	{
		//std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//STL vector
		list<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//STL vector

		//1. 배열연산자 [] 사용 (단, list는 사용불가)
		for (int i = 0; i < v.size(); i++)
			;//cout << v[i] << endl;
		cout << "--------------------" << endl;

		//2. range-for문 사용
		
		for (auto& item : v)
			cout << item << endl;
		cout << "--------------------" << endl;

		//3. 반복자 사용
		auto start = begin(v);

		while (start != end(v))
		{
			cout << *start << endl;
			start++;
		}
	}

	// 알고리즘(Algorithm)
	if (0)
	{
		//	: #include <algorithm> 필요
		//	: 알고리즘은 멤버함수가 아니다
		//	: 일반함수로 제공해서 하나의 함수로 다양한 컨테이너를 지원함
		//	: 자료구조에 독립적이다
		// www.cppreference.com에서 다양한 알고리즘 참고 (예제포함)

		//vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		//list<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		//1. reverse()
		//reverse(data.begin(), data.end()); //멤버함수 - 컨테이너
		reverse(begin(data), end(data));     // 일반함수- 컨테이너, C의 배열
		for (auto& n : data)
			cout << n << ", ";
		cout << endl << endl;

		//2. sort()
		//sort(begin(data), end(data));
		auto p = begin(data);
		sort(p, p+5);
		//sort(begin(data), end(data));
		for (auto& n : data)
			cout << n << ", ";
		cout << endl << endl;

		//3. find()
		// : [first, last) 사이의 선형검색을 수행한다.
		// : last는 검색이 대상이 아니다
		// : 검색 실패시, 0이 아닌 last를 반환한다

		 auto hit = find(begin(data), end(data), 7);
		 if (hit == end(data))   //안되는 경우를 먼저 짜야됨
			 cout << "검색 실패" << endl;
		 else
			 cout << "검색 성공 : " << *hit << endl;
	}

	// 정책변경(Policy) - 알고리즘의 정책변경
	if (1)
	{
		std::vector<int> v = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		//for (auto& n : v) cout << n << endl;
		//std::sort(begin(v), end(v)); // 오름차순 정렬
		//for (auto& n : v) cout << n << ", ";

		//1. 일반함수 사용
		//std::sort(begin(v), end(v), myCompare); // 내림차순 정렬
		//for (auto& n : v) std::cout << n << endl;

		//2. 함수객체 사용(<functional>)
		std::greater<int> ggg; // >
		//std::sort(begin(v), end(v), ggg);
		//for (auto& n : v) std::cout << n << endl;

		//3. 람다 표현식 사용(C++11) - 이름이 없는 함수
		std::sort(begin(v), end(v),
			[](int a, int b) {return a > b;});
		for (auto& n : v) std::cout << n << endl;
	}

	return 0;
}
#endif