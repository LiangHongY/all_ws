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
	cout << "����������ֱ��ʵĿ��wֵ" << endl;
	cin >> w;
	cout << "����������ֱ��ʵĸ߶�hֵ" << endl;
	cin >> h;
	cout << "������Խ������Դ�ɽǣ��Ƕ��ƣ�r" << endl;
	cin >> r; 

	h_fov=calculate(w,h,r);
	cout << "ˮƽ�ɽǣ������ƣ�h_fov=" << h_fov << endl;

	system("pause");
	return 0;
}


////matlab  2017b   �汾
////3x3��ת�������ŷ����
//
//>> a = [0 1 0; 1 0 0; 0 0 1]
//
//a =
//
//0     1     0
//1     0     0
//0     0     1
//
//>> b = rotm2eul(a)//Ĭ��ʱʹ�õ���  ZYX  ��ת˳��
//
//b =
//
//1.5708         0         0//�������������ǣ����� Z ��ʱ�� ת1.5708���ȣ�Ȼ���� Y ת0���ȣ������ X ת0����
//
//>> c = rotm2eul(a, 'XYZ')   //�������˳��Ϊ  XYZ
//
//c =
//
//0         0      - 1.5708 //�������������ǣ����� X ת0���ȣ�Ȼ���� Y ת0���ȣ������ Z ˳ʱ�� ת1.5708����
//
//>> d = rotm2eul(a, 'ZYX')//�Ա�  b=..  ���Կ����ú���Ĭ�ϵ�˳��Ϊ  ZYX
//
//d =
//
//1.5708         0         0  //�������������ǣ����� Z ��ʱ�� ת1.5708���ȣ�Ȼ���� Y ת0���ȣ������ X ת0����
//
////matlab���������rotm2eul()�����ṩ��˳�����xyz��zyx���֣����⻹��һ����zyz�����˸о����������ò���Ͳ�չʾ��