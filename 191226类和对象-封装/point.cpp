#include"point.h"

	//设置x
	void Point::setX(int x)
	{
		m_X=x;
	}
	//获取x
	int Point::getX()
	{
		return m_X;
	}
	//设置Y
		void Point::setY(int y)
	{
		m_Y=y;
	}
	//获取Y
	int Point::getY()
	{
		return m_Y;
	}
	//只保存操作，去除声明；需要定义在Point作用域下面进行的，否则会报错，因为在默认情况下这些是全局参数
