#include<iostream>
#include<vector>

using namespace std;

float Mi[] = { 0.25,0.15,0.2,0.4 };

int main() {
	float ans = 0.0,Cx=0.0;
	
	while (true)
	{
		for (int i = 0; i < 4; i++) {
			cout << "�������" << i + 1 << "������ָ��Ĺ淶������" << endl;
			cin >> ans;
			Cx += ans * Mi[i];
		}
		cout << "�Ŷ�Cx=" << Cx << endl;

		cout << "�Ƿ��˳���1��ʾ�ǣ�0��ʾ���˳�" << endl;
		int t = 0;
		cin >> t;
		if (t)
			break;
		cout << "----------------------------------" << endl;
		Cx = 0.0;
	}
}