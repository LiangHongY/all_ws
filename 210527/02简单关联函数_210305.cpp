#include<iostream>
#include<algorithm>

using namespace std;

float a1=6.0, b1=10.0,M1=10.0;

int main() {
	float a, b,M,x;
	a = a1;//��ʾ�����������a
	b = b1;//��ʾ���������Ҳ�b
	M = M1;//��ʾ��ʾ��ѵ�

	int X,t;

	while (true)
	{
		cout << "�����뵱ǰx" << endl;
		cin >> x;

		cout << "��ѡ������ķ�ΧX" << endl;
		cout << "X:<a,b>....����0" << endl;
		cout << "X:>a...����1" << endl;
		cout << "X:<b...����-1" << endl;
		cout << "X:-,+...����2" << endl;
		cin >> X;

		cout << "M�ڵ�ǰ�����Ƿ������ֵ��1��ʾ�У�0��ʾ�ޣ�������ѡ��" << endl;
		cin >> t;

		float kx = 0.0000;

		//����Ϊ�������䣬�������ֵM����
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

		//����Ϊ����������
		else if (X == 1 && M >= a) {
			//���ֵM����
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
			//���ֵM������
			else if (t == 0) {
				kx = x - a;//��kx��[a,+...)û�����ֵMʱ��ȡkx=x-a;
			}

		}

		//����Ϊ����������
		else if (X == -1 && M <= b) {
			//���ֵM����
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
			//���ֵM������
			else if (t == 0) {
				kx = b - x;
			}

		}

		//����Ϊ������������
		else if (X == 2) {
			//���ֵM����
			if (t == 1) {
				if (x < M) {
					kx = 1 / (1 + M - x);
				}
				else if (x >= M)
				{
					kx = 1 / (x + 1 - M);
				}
			}
			//���ֵM������
			else if (t == 0) {
				kx = max(exp(x), exp(-x));
			}
		}

		cout << "������kx=" << kx << endl;

		cout << "�Ƿ��˳���1��ʾ�ǣ�0��ʾ���˳�" << endl;
		int tt = 0;
		cin >> tt;
		if (tt)
			break;
		cout << "----------------------------------" << endl;
	}

	
}