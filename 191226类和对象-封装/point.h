#pragma once
#include <iostream>
using namespace std;

//����
class Point
{
public:
	//����x
	void setX(int x);

	//��ȡx
	int getX();

	//����Y
		void setY(int y);

	//��ȡY
	int getY();

private:
	int m_X;
	int m_Y;
};
//ֻ����������ȥ������