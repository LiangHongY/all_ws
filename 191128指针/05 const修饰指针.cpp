#include"stdafx.h"
#include<iostream>
using namespace std;

int main()
{

	int a=10;
	int b=10;
	
	//const int * p    ����ָ�룺ָ���ָ��ɸģ���ָ���ֵ���ɸ�   �� 
	//�ɼǣ�const ��ʾ����  * ���Ϊָ����ʶ����ô�ϲ����ǳ���ָ�룻  
	//const���ε���  * p������ ��ʾ����һ��ֵ��const�������ֵ����ô��ָ��ָ���ֵ�ǲ��ɸĵġ�
	
	//1��const����ָ��   ����ָ��
	
	const int * p=&a;
	//* p=20;����    
	 p=&b;

	//int * const p   ָ�볣����ָ���ָ�򲻿ɸġ���ָ���ֵ�ɸ�
	// �ɼǣ� * ��ʾָ�룬const��ʾ��������ô�ϲ�����ָ�볣��   ��
	//  const���ε���  p,������ָ��Ӣ����˼ָ�룬��ָ����ǵ�ַ����ô������ʾ��ָ���ָ���ǲ��ɸĵġ�
	  //2��const���γ���   ָ�볣��
	 int * const p2=&a;
	// p2=&b   ����ָ�򲻿ɸ�
	 * p2=20;

	 //3��
	//const int * const p  ��ָ���ָ����ָ���ֵ���ɲ��ɸ�
	 const int * const p3=&a;
	// *p3=20;����
	 //p3=&b; ����

	system("pause");
	return 0;
}