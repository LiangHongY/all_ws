#include<iostream>
#include<vector>

using namespace std;

float Mi[] = { 0.25,0.15,0.2,0.4 };

int main() {
	float ans = 0.0,Cx=0.0;
	
	while (true)
	{
		for (int i = 0; i < 4; i++) {
			cout << "请输入第" << i + 1 << "个衡量指标的规范关联度" << endl;
			cin >> ans;
			Cx += ans * Mi[i];
		}
		cout << "优度Cx=" << Cx << endl;

		cout << "是否退出？1表示是，0表示不退出" << endl;
		int t = 0;
		cin >> t;
		if (t)
			break;
		cout << "----------------------------------" << endl;
		Cx = 0.0;
	}
}