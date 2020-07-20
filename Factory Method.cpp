#include <iostream>

using namespace std;

/*
Problem
- this pattern is to be used in situations where there is a need
to standardize the architectural model for a set
applications, while allowing applications
individuals to define their own objects to
create
• Consequences
+ Elimination of the need for application-specific code in
the framework code (only the Product interface)
- Multiplication of the number of classes
*/

class Product {
  public:
    virtual string prodInfo()=0;
};

class ConcreteProduct1:public Product{
  public:
    string prodInfo(){
      return "{Product Number 1}";
    }
};

class ConcreteProduct2:public Product{
  public:
    string prodInfo(){
      return "{Product Number 2}";
    }
};

class ConcreteProduct3:public Product{
  public:
    string prodInfo(){
      return "{Product Number 3}";
    }
};

class Factory {
  public:
    virtual Product * factoryMethod() = 0;
    string operation(){
      Product * prod = this->factoryMethod();
      string result = "Factory Classes Has Created "+prod->prodInfo()+" With The Same Operation Method.";
      delete prod;
      return result;
    }
};

class ConcreteFactory1 : public Factory{
  public:
    Product * factoryMethod(){
      return new ConcreteProduct1();
    }
};

class ConcreteFactory2 : public Factory{
  public:
    Product * factoryMethod(){
      return new ConcreteProduct2();
    }
};

class ConcreteFactory3 : public Factory{
  public:
    Product * factoryMethod(){
      return new ConcreteProduct3();
    }
};


int main(){
  cout<<"ConcreteFactory1 Code :: "<<endl;
  Factory * creater1 = new ConcreteFactory1();
  cout<<creater1->operation()<<endl;

  Factory * creater2 = new ConcreteFactory2();
  cout<<creater2->operation()<<endl;

  delete creater1;
  delete creater2;

  return 0;
}