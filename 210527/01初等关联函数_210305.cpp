#include<iostream>

using namespace std;

float c1 = 10000.0, a1 = 14000.0, a01 = 15000.0, b01 = 20000.0, b1 = 22000.0, d1 = 25000.0, x01 = 2.5000;


float p(float a, float b, float x0, float x);//可拓距计算函数
float D(float p1, float p2);//位值计算函数
float k(float a, float a0, float b0, float b, float p1, float p2, float p3, float d1, float d2,float x);//关联度计算函数


int main() {
	float c, a, a0, b0, b, d;
	float x0,x;
	//cout << "依次从小到大且无相等输入" << endl;

	//cout << "请输入c" << endl;
	//cin >> c;
	//cout << "请输入a" << endl;
	//cin >> a;
	//cout << "请输入a0" << endl;
	//cin >> a0;
	//cout << "请输入b0" << endl;
	//cin >> b0;
	//cout << "请输入b" << endl;
	//cin >> b;
	//cout << "请输入d" << endl;
	//cin >> d;
	c = c1;
	a = a1;
	a0 = a01;
	b0 = b01;
	b = b1;
	d = d1;
	x0 = x01;
	
	cout << c << " " << a << " " << a0 << " " << b0 << " " << b << " " << d << endl;

	//cout << "请输入满意区间X0=<a0,b0>的最优点x0:" << endl;
	//cin >> x0;

	while (true)
	{
		cout << "请输入当前变量x" << endl;
		cin >> x;

		//三个可拓距	
		float p1, p2, p3;//p1:X(a,b)  p2:X0(a0,b0)  p3:X^(c,d)

		p1 = p(a, b, x0, x);
		p2 = p(a0, b0, x0, x);
		p3 = p(c, d, x0, x);

		cout << "p1=" << p1 << " " << "p2=" << p2 << " " << "p3=" << p3 << endl;
		//两个位值
		float d1, d2;//d1:p1-p2  d2:p3-p1

		d1 = D(p1, p2);
		d2 = D(p3, p1);
		cout << "d1=" << d1 << " " << "d2=" << d2 << endl;

		//关联度
		float kx;

		kx = k(a, a0, b0, b, p1, p2, p3, d1, d2, x);

		cout << "关联度kx=" << kx << endl;

		cout << "是否退出？1表示是，0表示不退出" << endl;
		int t = 0;
		cin >> t;
		if (t)
			break;
		cout << "----------------------------------" << endl;
	}
}

//计算可拓距函数
float p(float a, float b, float x0, float x) {
	float ans = 0.0000;

	if (a <= x0 < (a + b) / 2) {
		if (x0 == a) {
			if (x < a) {
				ans = a - x;
				cout << "左侧可拓距，当x0=a时，x<a类型" << endl;
			}
			//这里课本关于x=a有疑惑,由于a肯定属于X=<a,b>,程序只是分为x<a,x>=a两种情况
			else if (x == a) {
				ans = a - b;
				cout << "左侧可拓距，当x0=a时，x==a类型" << endl;
			}
			else if (x > a) 
			{
				ans = x - b;
				cout << "左侧可拓距，当x0=a时，x>a类型" << endl;
			}
		}
		else
		{
			if (x <= a) {
				ans = a - x;
				cout << "左侧可拓距，当a<x0<(a+b)/2时，x<=a类型" << endl;
			}
			else if (x >= x0) {
				ans = x - b;
				cout << "左侧可拓距，当a<x0<(a+b)/2时，x >= x0类型" << endl;
			}
			else if (a< x < x0) {
				ans = (x - a) * (b - x0) / (a - x0);
				cout << "左侧可拓距，当a<x0<(a+b)/2时，a< x < x0类型" << endl;
			}
		}
	}

	else if(x0 == (a + b) / 2) {
		if ( x < (a + b)/2) {
			ans = a - x;
			cout << "中点可拓距，当x0=(a+b)/2时，x < (a + b)/2类型" << endl;
		}
		else if ( x >= (a + b)/2) {
			ans = x - b;
			cout << "中点可拓距，当x0=(a+b)/2时，x >= (a + b)/2类型" << endl;
		}
	}

	else if ((a + b) / 2 < x0 <= b) {
		if (x0 == b) {
			if (x < b) {
				ans = a - x;
				cout << "右侧可拓距，当x0=b时，x<b类型" << endl;
			}
			else if (x == b) {
				ans = a - b;
				cout << "右侧可拓距，当x0=b时，x=b类型" << endl;
			}
			else if (x > b) {
				ans = x - b;
				cout << "右侧可拓距，当x0=b时，x>b类型" << endl;
			}
		}
		
		else if ((a + b) / 2 < x0 <b) {
			if (x <= x0) {
				ans = a - x;
				cout << "右侧可拓距，当(a + b)/2 < x0 <b时，x <= x0类型" << endl;
			}
			else if (x >= b) {
				ans = x - b;
				cout << "右侧可拓距，当(a + b)/2 < x0 <b时，x >= b类型" << endl;
			}
			else if (x0 < x < b) {
				ans = (b - x) * (a - x0) / (b - x0);
				cout << "右侧可拓距，当(a + b)/2 < x0 <b时，x0 < x < b类型" << endl;
			}

		}
	}
	
	return ans;
}

//计算位值函数
float D(float p1, float p2) {
	return (p1 - p2);
}

//计算关联度函数
float k(float a, float a0, float b0, float b, float p1, float p2, float p3, float d1, float d2,float x) {
	float ans=0.0000;

	if (d1 != 0 && (a <= x <= b)) {
		ans = p1 / d1;
	}
	if (d1 == 0 && (a0 <= x <= b0)) {
		ans = 1 - p2;
	}
	if (d1 == 0 && (a < x < a0 || b0 < x < b)) {
		ans = 0.0;
	}
	if (d2 != 0 && (x<a || x>b)) {
		ans = p1 / d2;
	}
	if (d2 == 0 && (x<a || x>b)) {
		ans = -p3 - 1;
	}
	return ans;
}