#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<float> a,b,c;
	

	float ans = 0.0;
	int n = 12;//数据个数
	
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1<< "个数据" << endl;
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
		cout << "对象关于衡量指标的第" << i << "个方案的规范关联度Kx=" << ans << endl;
	}
}
