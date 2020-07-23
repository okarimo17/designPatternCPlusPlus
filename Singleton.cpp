#include <iostream>

using namespace std;

/*
Singleton
• Problem
- have a single instance of a class and be able to
to access and handle it easily
• Solution
- only one class is needed to write this pattern
• Consequences
- the uniqueness of the instance is completely controlled by
the class itself. This pattern can easily be
extended to allow the creation of a number
given instances
*/

class Singleton {
  private:
    static Singleton * instance;
    Singleton(){
    }
  public:
    static Singleton* getInstance(){
      if(!instance)
        instance = new Singleton();
      return instance;
    }
};

// Just For c++, initialize value of instance with Null .
Singleton * Singleton::instance = nullptr;


int main(){

  Singleton * obj1 = Singleton::getInstance();
  Singleton * obj2 = Singleton::getInstance();
  cout<<"Obj1 And Obj2 Are the Same Object (Same Pointer) :"<<endl<<obj1<<endl<<obj2;
  return 0;
}