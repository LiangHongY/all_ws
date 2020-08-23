#pragma once
#include <iostream>
using namespace std;

//点类
class Point
{
public:
	//设置x
	void setX(int x);

	//获取x
	int getX();

	//设置Y
		void setY(int y);

	//获取Y
	int getY();

private:
	int m_X;
	int m_Y;
};
//只保留声明，去除操作