#include<iostream>
using namespace std;

class a
{

public:
	a()
	{
		cout << "构造函数调用" << endl;
	}

	void fun(int i)
	{
		cout << "调用fun函数" << endl;
	}
	~a() {
		cout << "析构函数调用"<<endl;
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