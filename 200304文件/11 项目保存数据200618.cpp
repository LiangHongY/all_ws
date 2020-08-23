#include<iostream>
using namespace std;


double calculate()
{
	
	double t=0.0;
	while(1)
	{
		int i = 0;
		cout << "Input your choose:" << endl;
		cout << "1 : add 0.01" << endl;
		cout << "2 : reduce 0.01" << endl;
		cout << " others : end" << endl;
		cin >> i;

		if (i == 1)
		{
			t += 0.01;
		}
		else if (i == 2)
		{
			t -= 0.01;
		}
		else 
			break;
	}
	return t;

}


void chooseparams()
{
	int i=-1;
	cout << "Please enter the parameters for adjustment" << endl;
	cout << "0 --- xyz_x" << endl;
	cout << "1 --- xyz_y" << endl;
	cout << "2 --- xyz_z" << endl;
	cout << "3 --- rpy_r" << endl;
	cout << "4 --- rpy_p" << endl;
	cout << "5 --- rpy_y" << endl;

	cin >> i;
	switch (i)
	{
	case 0: {
		double ret_xyz_x =calculate();
	}
	case 1: {
		double ret_xyz_y = calculate();
	}
	case 2: {
		double ret_xyz_y = calculate();
	}
	case 3: {
		double ret_rpy_r = calculate();
	}
	case 4: {
		double ret_rpy_p = calculate();
	}
	case 5: {
		double ret_rpy_y = calculate();

	}
	default:
		break;
	}
}


void choosetype()
{
	int i=-1;
	cout << "Input adjustment sensor :" << endl;
	cout << "0 ---- front_scanner" << endl;
	cout << "1 ---- rear_scanner" << endl;
	cout << "2 ---- depthcamera" << endl;

	cin >> i;
	switch (i)
	{
	case 0: {
		cout << "front_scanner_adjustment :" << endl;
		chooseparams();
	}
	case 1: {
		cout << "rear_scanner_adjustment :" << endl;
		chooseparams();
	}
	case 2: {
		cout << "depthcamera_adjustment :" << endl;
		chooseparams();
	}
	default:
		break;
	}
} 
void test01()
{
	choosetype();
}

int main()
{
	test01();
	system("pause");
	return 0;
}