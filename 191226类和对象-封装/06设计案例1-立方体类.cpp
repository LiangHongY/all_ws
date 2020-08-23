#include<iostream>
using namespace std;

//设计立方体类
//求面积和体积
//分别使用全局函数和成员函数是否相等

//设计立方体类
//设计属性
//设计行为，获取体积和面积
//分别使用全局函数和成员函数，判断两个立方体是否相等

class Cube
{
	//行为
	//获取面积

	//获取体积
public:
	//设置长
	void setL(int l)
	{
		m_L=l;
	}
	//设置宽
		void setW(int w)
	{
		m_W=w;
	}

	//设置高
	void setH(int h)
	{
		m_H=h;
	}
	//获取长
		int getL()
	{
	    return m_L;
	}
	//获取宽
		int getW()
	{
	    return m_W;
	}
	//获取高
		int getH()
	{
	    return m_H;
	}
	//获取面积
		int calulateS()
		{
			return 2*(m_L*m_W+m_L*m_H+m_W*m_H);
		}
		//获取体积
				int calulateV()
		{
			return m_L*m_W*m_H;
		}
		//利用成员函数判断两个立方体是否相等
		bool isSameByclass(Cube &c)
		{
			if(m_L==c.getL()&&m_W==c.getW()&&m_H==c.getH())
			{
				return true;
			}
			else  
				return false;
		}
private:
	//属性，一般设置私有
	int m_L;
	int m_W;
	int m_H;

};
//利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1,Cube &c2)
{
	if(c1.getL()==c2.getL()&&c1.getW()==c2.getW()&&c1.getH()==c2.getH())
	{
		return true;
	}
	return false;
}


int main()
{
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout<<"c1面积为  "<<c1.calulateS()<<endl;
	cout<<"c1体积为  "<<c1.calulateV()<<endl;

	//创建第二个立方体
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(11);//在验证程序是否有问题时候，应该选择简单的数据来验证

	bool ret=isSame(c1,c2);
	if(ret)
	{
		cout <<"c1和c2是相等的"<<endl;
	}
	else
	{
		cout<<"c1和c2是不相等的"<<endl;
	}

	//利用成员函数判断
	ret =c1.isSameByclass(c2);
		if(ret)
	{
		cout <<"成员函数判断： c1和c2是相等的"<<endl;
	}
	else
	{
		cout<<"成员函数判断： c1和c2是不相等的"<<endl;
	}


	system("pause");
	return 0;
}