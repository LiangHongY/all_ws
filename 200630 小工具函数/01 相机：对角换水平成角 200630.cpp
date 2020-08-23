#include<iostream>
#include<cmath>

using namespace std;


double calculate(double a,double b,double c)
{
	double c1 = c * 3.14156 / 180;

	double a1 = (sqrt(a * a + b * b))/2;

	double a11 = a1 /tan(c1 / 2);

	double a111 = 2 * (atan((a / 2) / a11));

	return a111 ;
	
}



int main()
{
	double w = 0.0, h = 0.0, r = 0.0, h_fov = 0.0;
	cout << "请输入相机分辨率的宽度w值" << endl;
	cin >> w;
	cout << "请输入相机分辨率的高度h值" << endl;
	cin >> h;
	cout << "请输入对角线与光源成角（角度制）r" << endl;
	cin >> r; 

	h_fov=calculate(w,h,r);
	cout << "水平成角（弧度制）h_fov=" << h_fov << endl;

	system("pause");
	return 0;
}


////matlab  2017b   版本
////3x3旋转矩阵计算欧拉角
//
//>> a = [0 1 0; 1 0 0; 0 0 1]
//
//a =
//
//0     1     0
//1     0     0
//0     0     1
//
//>> b = rotm2eul(a)//默认时使用的是  ZYX  旋转顺序
//
//b =
//
//1.5708         0         0//三个参数意义是：先绕 Z 逆时针 转1.5708弧度，然后绕 Y 转0弧度，最后绕 X 转0弧度
//
//>> c = rotm2eul(a, 'XYZ')   //定义的是顺序为  XYZ
//
//c =
//
//0         0      - 1.5708 //三个参数意义是：先绕 X 转0弧度，然后绕 Y 转0弧度，最后绕 Z 顺时针 转1.5708弧度
//
//>> d = rotm2eul(a, 'ZYX')//对比  b=..  可以看出该函数默认的顺序为  ZYX
//
//d =
//
//1.5708         0         0  //三个参数意义是：先绕 Z 逆时针 转1.5708弧度，然后绕 Y 转0弧度，最后绕 X 转0弧度
//
////matlab里面有这个rotm2eul()函数提供的顺序就是xyz和zyx两种，另外还有一种是zyz，个人感觉对需求作用不大就不展示了