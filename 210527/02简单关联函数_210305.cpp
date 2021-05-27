#include<iostream>
#include<algorithm>

using namespace std;

float a1=6.0, b1=10.0,M1=10.0;

int main() {
	float a, b,M,x;
	a = a1;//表示正域区间左侧a
	b = b1;//表示正域区间右侧b
	M = M1;//表示表示最佳点

	int X,t;

	while (true)
	{
		cout << "请输入当前x" << endl;
		cin >> x;

		cout << "请选择正域的范围X" << endl;
		cout << "X:<a,b>....输入0" << endl;
		cout << "X:>a...输入1" << endl;
		cout << "X:<b...输入-1" << endl;
		cout << "X:-,+...输入2" << endl;
		cin >> X;

		cout << "M在当前区域是否有最大值，1表示有，0表示无，请输入选择" << endl;
		cin >> t;

		float kx = 0.0000;

		//正域为有限区间，并且最大值M存在
		if (X == 0 && a <= M <= b) {
			if (M == a) {
				if (x < a) {
					kx = (x - a) / (b - a);
				}
				else if (x >= a) {
					kx = (b - x) / (b - a);
				}
			}
			else if (M == b) {
				if (x <= b) {
					kx = (x - a) / (b - a);
				}
				else if (x > b) {
					kx = (b - x) / (b - a);
				}
			}
			else
			{
				if (x <= M) {
					kx = (x - a) / (M - a);
				}
				else if (x >= M) {
					kx = (b - x) / (b - M);
				}
			}
		}

		//正域为右无穷区间
		else if (X == 1 && M >= a) {
			//最大值M存在
			if (t == 1) {
				if (M == a) {
					if (x < a) {
						kx = x - a;
					}
					else if (x >= a) {
						if (a > 0) {
							kx = (1 + a) / (x + 1);
						}
						else {
							kx = (1 - a) / (x + 1 - 2 * a);
						}
					}
				}
				else if (M > a) {
					if (x <= M) {
						kx = (x - a) / (M - a);
					}
					else if (x >= M) {
						if (M > 0) {
							kx = (1 + M) / (x + 1);
						}
						else
						{
							kx = (1 - M) / (x + 1 - 2 * M);
						}
					}
				}
			}
			//最大值M不存在
			else if (t == 0) {
				kx = x - a;//当kx在[a,+...)没有最大值M时，取kx=x-a;
			}

		}

		//正域为左无穷区间
		else if (X == -1 && M <= b) {
			//最大值M存在
			if (t == 1) {
				if (M == b) {
					if (x > b) {
						kx = b - x;
					}
					else if (x <= b) {
						if (b > 0) {
							kx = (1 + b) / (1 - x + 2 * b);
						}
						else
						{
							kx = (1 - b) / (1 - x);
						}
					}
				}
				else
				{
					if (x < M) {
						if (M > 0) {
							kx = (1 + M) / (1 - x + 2 * M);
						}
						else
						{
							kx = (1 - M) / (1 - x);
						}
					}
					else if (x >= M)
					{
						kx = (x - b) / (M - b);
					}
				}
			}
			//最大值M不存在
			else if (t == 0) {
				kx = b - x;
			}

		}

		//正域为左右无穷区间
		else if (X == 2) {
			//最大值M存在
			if (t == 1) {
				if (x < M) {
					kx = 1 / (1 + M - x);
				}
				else if (x >= M)
				{
					kx = 1 / (x + 1 - M);
				}
			}
			//最大值M不存在
			else if (t == 0) {
				kx = max(exp(x), exp(-x));
			}
		}

		cout << "关联度kx=" << kx << endl;

		cout << "是否退出？1表示是，0表示不退出" << endl;
		int tt = 0;
		cin >> tt;
		if (tt)
			break;
		cout << "----------------------------------" << endl;
	}

	
}