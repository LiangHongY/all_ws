#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<float> a,b,c;
	

	float ans = 0.0;
	int n = 12;//���ݸ���
	
	for (int i = 0; i < n; i++) {
		cout << "�������" << i + 1<< "������" << endl;
		cin >> ans;
		b.push_back(ans);

		if (ans > 0) {
			a.push_back(ans);
		}
		else
		{
			a.push_back(-ans);
		}
		
	}

	float max_a = *max_element(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		ans = b.at(i) / max_a;
		cout << "������ں���ָ��ĵ�" << i << "�������Ĺ淶������Kx=" << ans << endl;
	}
}
