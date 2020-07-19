#include <iostream>

using namespace std;

// Context Is The Duck class or client class , Strategy Is The Behavier Interface . 
/*
Problem:
we want to (i) define a family of algorithms, (ii) encapsulate
each and make them interchangeable while ensuring that
each algorithm can evolve independently of clients
who use it

Consequences
+ Hierarchical expression of families of algorithms, elimination
of tests to select the right algorithm, leave a choice
of implementation and dynamic selection of the algorithm
- Customers must pay attention to the strategy, additional cost linked to
communication between Strategy and Context, increased
number of objects

*/



class IFlyBehavier {
  public :
    virtual void Fly() = 0;
};

class SimpleFly:public IFlyBehavier {
  public:
    void Fly(){
      cout << "SimpleFlying Fly"<<endl;
    }
};

class NoFly:public IFlyBehavier {
  public:
    void Fly(){
      cout << "Sorry can't Fly."<<endl;
    }
};

class IQuakBehavier {
  public:
    virtual void Quak() = 0;
};

class SimpleQuak:public IQuakBehavier {
  public:
    void Quak(){
      cout<<"SimpleQuaking Quak" <<endl;
    }
};

class NoQuak:public IQuakBehavier {
  public:
    void Quak(){
      cout<<"Sorry Can't Quak." <<endl;
    }
};

class Duck {
  private:
    IFlyBehavier * IFly;
    IQuakBehavier * IQuak;
  public:
    Duck(IFlyBehavier * IFly=nullptr,IQuakBehavier * IQuak=nullptr){
      this->IFly = IFly;
      this->IQuak = IQuak;
    }

    void Fly(){
      this->IFly->Fly();
    }

    void Quak(){
      this->IQuak->Quak();
    }
};



int main(){

  // fly->Fly();

  Duck GoodDuck = Duck(new SimpleFly(), new SimpleQuak());

  GoodDuck.Fly();
  GoodDuck.Quak();

  Duck montainDuck = Duck(new NoFly(),new NoQuak());
  montainDuck.Fly();
  montainDuck.Quak();

  return 0;
}
