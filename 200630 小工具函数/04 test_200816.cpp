#include<iostream>
using namespace std;

class a
{

public:
	a()
	{
		cout << "���캯������" << endl;
	}

	void fun(int i)
	{
		cout << "����fun����" << endl;
	}
	~a() {
		cout << "������������"<<endl;
	}


protected:
	void gun(int i)
	{
		cout << "gun" << endl;
	}
private:
	int m_i;


};

int main()
{
	a t;
	t.fun(1);

	system("pause");
	return 0;
}