

// TODO:
/*
 * C++ 并非变幻莫测的方面是一个 object（对象）的数据被初始化的顺序。
 * 这个顺序总是相同的：base classes（基类）在 derived classes（派生类）之前被初始化（参见 Item 12），
 * 在一个 class（类）内部，data members（数据成员）按照它们被声明的顺序被初始化。
 * */


#include <string>
#include <iostream>

using namespace std;


class Point{
  public:

    Point():x(0) {
      cout<<"Point default constructor"<<endl;
    }

    Point(const Point& rhs) {
      cout<<"Point copy constructor"<<endl;
      x = rhs.x;
    }

    Point& operator=(const Point& rhs) {
      cout<<"Point copy assign operator"<<endl;
      x = rhs.x;
      return *this;
    }

  private:
    int x;
};


class Entry{

public:

  // TODO:
  // 使用初始化列表，会在进入构造函数之前调用
  // Entry(const Point& name)
  //   :theName(name),
  //    num(0) {
  //   cout<<"Entry constructor"<<endl;
  // }

  Entry(const Point& name) {
    theName = name;
    num = 0;
    cout<<"Entry constructor"<<endl;
  }


private:
  Point theName;
  int num;
};


int main() {

  Point p = Point();
  Entry x = Entry(p);
  cout<<&x<<endl;

  unsigned int n = static_cast<unsigned>(2147483647) + 100;
  cout<<n<<endl;

}
