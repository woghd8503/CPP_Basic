#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream> // cin, cout�� ����Ϸ���
#include <fstream>  // ifstream, ofstream
#include <string>

int main()
{
	//cin�� ����Լ�
	if (0)
	{
		int age = 0;
		cout << "���̸� �Է��ϼ��� : ";

		if (0)
		{
			// 1ȸ�� üũ
			cin >> age; // 'a'�� �Է��ϸ�?

			if (cin.fail())
				cout << "�Է½���" << endl;
			else
				cout << "�Է¼��� : " << age << endl;
		}

		while (1)
		{
			cin >> age;
			if (cin.fail())
			{
				cin.clear(); // cin�� ���¸� clear�Ѵ�.
				cin.ignore(100, '\n'); // �Է¹��۸� ����.
				continue;
			}
			break;
		}
		cout << "�Է¼��� : " << age << endl;


	}

	// �ܾ��Է� vs �����Է�
	if (0)
	{
		string name;
		cout << "�̸��� �Է��ϼ��� : ";
		//cin >> name; //"�� ȣ��" �� �Է��ϸ� ��� �ɱ�?
		//cout << name << endl;

		std::getline(cin, name);
		cout << name << endl;

	}

	//���� ��� - ofstream(output) + text���
	if (0)
	{
		cout << "hello" << endl;

		ofstream f("c:\\Temp\\a.txt");
		f << "hello" << endl;
		f << "hi" << endl;
		f << "hello" << endl;
	}

	//���� �Է� - ifstream(input) + text���
	if (0)
	{
		ifstream f("c:\\Temp\\a.txt");

		string content;
		
		while (getline(f, content))
		{
			cout << content << endl;
		}
	}

	// ���� ��� - ofstream + binary���
	if (1)
	{
		class Human
		{
		public:
			string name;
			int age;
		};
		Human a;
		a.name = "ȫ�浿";
		a.age = 22;
		////////////////////
		//��������
		ofstream f1("c:\\Temp\\bin.dat", std::ios::binary);
		f1.write((const char*)&a, sizeof(Human));
		f1.close();

		////////////////////
		//���Ϸε�
		cout << "before" << endl;
		Human b;
		ifstream f2("c:\\Temp\\bin.dat", std::ios::binary);
		if (f2.is_open())
		{
			f2.read((char*)&b, sizeof(Human));
			f2.close();
		}
		cout << "after" << endl;
		cout << b.name << endl;
		cout << b.age << endl;
	}
	return 0;
}

#endif