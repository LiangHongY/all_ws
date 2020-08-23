//自己的通用的数组类
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造  参数  容量
	MyArray(int capacity)
	{
		//cout << "Myarray有参构造的调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//这里数组T的this没有自动跳出选项，copy进去的
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "Myarray拷贝构造的调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;//这是浅拷贝,会带来堆区数据重复释放问题

		//深拷贝
		this->pAddress=new T[arr.m_Capacity];

		//将arr数组的数据拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}//如果T为对象，而且包含指针，必须需要重载 = 操作符，因为这个等号不是  构造  而是赋值，
	 //普通类型可以直接 = 但是指针类型需要深拷贝

	//operator= 重载= 操作符 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)//MyArray& 作用是 可以进行连等操作a=b=c [个人还是不理解这里重载=意义]
	{
		//cout << "Myarray的operator=的调用" << endl;
		//先判断原来的堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	////重载[]操作符， arr[0]
	//T& operator [](int index)
	//{
	//	return this->pAddress[index];//不考虑越界，用户自己去处理？200512
	//}

	//尾插法
	void Push_back(const T& val)
	{
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//在数组末尾插入数据
		this->m_Size++;//更新数组大小
	}

	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//通过下标方式访问数组中元素   赋值操作arr[0]=100
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "Myarray析构的调用" << endl;
			delete[] this->pAddress;
			this->pAddress=NULL;
		}
	}

private:
	T * pAddress;//指针指向堆区开辟的真实数组

	int m_Capacity;//数组容量

	int m_Size;//数组大小
};