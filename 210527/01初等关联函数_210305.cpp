#include<iostream>

using namespace std;

float c1 = 10000.0, a1 = 14000.0, a01 = 15000.0, b01 = 20000.0, b1 = 22000.0, d1 = 25000.0, x01 = 2.5000;


float p(float a, float b, float x0, float x);//���ؾ���㺯��
float D(float p1, float p2);//λֵ���㺯��
float k(float a, float a0, float b0, float b, float p1, float p2, float p3, float d1, float d2,float x);//�����ȼ��㺯��


int main() {
	float c, a, a0, b0, b, d;
	float x0,x;
	//cout << "���δ�С���������������" << endl;

	//cout << "������c" << endl;
	//cin >> c;
	//cout << "������a" << endl;
	//cin >> a;
	//cout << "������a0" << endl;
	//cin >> a0;
	//cout << "������b0" << endl;
	//cin >> b0;
	//cout << "������b" << endl;
	//cin >> b;
	//cout << "������d" << endl;
	//cin >> d;
	c = c1;
	a = a1;
	a0 = a01;
	b0 = b01;
	b = b1;
	d = d1;
	x0 = x01;
	
	cout << c << " " << a << " " << a0 << " " << b0 << " " << b << " " << d << endl;

	//cout << "��������������X0=<a0,b0>�����ŵ�x0:" << endl;
	//cin >> x0;

	while (true)
	{
		cout << "�����뵱ǰ����x" << endl;
		cin >> x;

		//�������ؾ�	
		float p1, p2, p3;//p1:X(a,b)  p2:X0(a0,b0)  p3:X^(c,d)

		p1 = p(a, b, x0, x);
		p2 = p(a0, b0, x0, x);
		p3 = p(c, d, x0, x);

		cout << "p1=" << p1 << " " << "p2=" << p2 << " " << "p3=" << p3 << endl;
		//����λֵ
		float d1, d2;//d1:p1-p2  d2:p3-p1

		d1 = D(p1, p2);
		d2 = D(p3, p1);
		cout << "d1=" << d1 << " " << "d2=" << d2 << endl;

		//������
		float kx;

		kx = k(a, a0, b0, b, p1, p2, p3, d1, d2, x);

		cout << "������kx=" << kx << endl;

		cout << "�Ƿ��˳���1��ʾ�ǣ�0��ʾ���˳�" << endl;
		int t = 0;
		cin >> t;
		if (t)
			break;
		cout << "----------------------------------" << endl;
	}
}

//������ؾຯ��
float p(float a, float b, float x0, float x) {
	float ans = 0.0000;

	if (a <= x0 < (a + b) / 2) {
		if (x0 == a) {
			if (x < a) {
				ans = a - x;
				cout << "�����ؾ࣬��x0=aʱ��x<a����" << endl;
			}
			//����α�����x=a���ɻ�,����a�϶�����X=<a,b>,����ֻ�Ƿ�Ϊx<a,x>=a�������
			else if (x == a) {
				ans = a - b;
				cout << "�����ؾ࣬��x0=aʱ��x==a����" << endl;
			}
			else if (x > a) 
			{
				ans = x - b;
				cout << "�����ؾ࣬��x0=aʱ��x>a����" << endl;
			}
		}
		else
		{
			if (x <= a) {
				ans = a - x;
				cout << "�����ؾ࣬��a<x0<(a+b)/2ʱ��x<=a����" << endl;
			}
			else if (x >= x0) {
				ans = x - b;
				cout << "�����ؾ࣬��a<x0<(a+b)/2ʱ��x >= x0����" << endl;
			}
			else if (a< x < x0) {
				ans = (x - a) * (b - x0) / (a - x0);
				cout << "�����ؾ࣬��a<x0<(a+b)/2ʱ��a< x < x0����" << endl;
			}
		}
	}

	else if(x0 == (a + b) / 2) {
		if ( x < (a + b)/2) {
			ans = a - x;
			cout << "�е���ؾ࣬��x0=(a+b)/2ʱ��x < (a + b)/2����" << endl;
		}
		else if ( x >= (a + b)/2) {
			ans = x - b;
			cout << "�е���ؾ࣬��x0=(a+b)/2ʱ��x >= (a + b)/2����" << endl;
		}
	}

	else if ((a + b) / 2 < x0 <= b) {
		if (x0 == b) {
			if (x < b) {
				ans = a - x;
				cout << "�Ҳ���ؾ࣬��x0=bʱ��x<b����" << endl;
			}
			else if (x == b) {
				ans = a - b;
				cout << "�Ҳ���ؾ࣬��x0=bʱ��x=b����" << endl;
			}
			else if (x > b) {
				ans = x - b;
				cout << "�Ҳ���ؾ࣬��x0=bʱ��x>b����" << endl;
			}
		}
		
		else if ((a + b) / 2 < x0 <b) {
			if (x <= x0) {
				ans = a - x;
				cout << "�Ҳ���ؾ࣬��(a + b)/2 < x0 <bʱ��x <= x0����" << endl;
			}
			else if (x >= b) {
				ans = x - b;
				cout << "�Ҳ���ؾ࣬��(a + b)/2 < x0 <bʱ��x >= b����" << endl;
			}
			else if (x0 < x < b) {
				ans = (b - x) * (a - x0) / (b - x0);
				cout << "�Ҳ���ؾ࣬��(a + b)/2 < x0 <bʱ��x0 < x < b����" << endl;
			}

		}
	}
	
	return ans;
}

//����λֵ����
float D(float p1, float p2) {
	return (p1 - p2);
}

//��������Ⱥ���
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