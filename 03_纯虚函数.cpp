
#if 0
#include <iostream>
#include <cstring>

using namespace std;

class Shop{
 public:
 	Shop(int x,int y):x_(x),y_(y){}
 	//virtual void show() = 0;
 	//virtual void area() = 0;   带纯虚函数的类叫虚基类，这种基类不能直接生成对象，而只有被继承，并重写其虚函数后，才能使用。这样的类也叫抽象类。
 	void show()
 	{
                    cout<<x_<<""<<y_<<endl;
 	}


 protected:
 	int x_;
 	int y_;
 	int s_;
};

int main()
{
	Shop k(2,3);
	k.show();
}
#endif