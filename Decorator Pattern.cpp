#include <iostream>


using namespace std;
/*
Beverage is the Component Interface , Caffe Milk and Tea are the Concrete component
Caramel Mocha and Soya Are The concrete Decorator classes , Cost method is the added responsabilité
*/

/*
• Problem
   - we want to add / remove responsibilities to
   objects in operation
   - inheritance is impossible because of the number of
   combinations, or because of access rights
• Consequences
   + more flexibility than inheritance
   + reduction in the size of the upper classes
   hierarchy
   - BUT a lot of small items
*/

void menu();

class Beverage {
  public:
    virtual double Cost() = 0;
};

class Caffe: public Beverage {
  public:
    double Cost(){
      return 2;
    }
};

class Milk: public Beverage {
  public:
    double Cost(){
      return 2;
    }
};

class Tea: public Beverage {
  public:
    double Cost(){
      return 2.5;
    }
};


class Decorator: public Beverage{
  protected:
    Beverage * component;
  public:
    Decorator(Beverage * component){
      this->component = component;
    }
    virtual double Cost()=0;
};

class Caramel: public Decorator{

  public:
    Caramel(Beverage * component=nullptr):Decorator(component){}
    double Cost(){
      return 1.2+this->component->Cost();
    }
};

class Mocha: public Decorator{

  public:
    Mocha(Beverage * component=nullptr):Decorator(component){}
    double Cost(){
      return 0.99+this->component->Cost();
    }
};

class Soya: public Decorator{

  public:
    Soya(Beverage * component=nullptr):Decorator(component){}
    double Cost(){
      return 0.7+this->component->Cost();
    }
};


int main(){
  menu();
  return 0;
}

void menu(){
  // I tried to make That Part as Simple as possible , so i have used only switch case that can be modified with something like factory pattern .
  int chose = 0;
  Beverage * beverage;
  start:
  cout<<"Chose Your Beverage : "<<endl;
  cout<<"1 for Caffe"<<endl;
  cout<<"2 for Milk"<<endl;
  cout<<"3 for Tea"<<endl;
  cin>>chose;
  switch (chose)
  {
    case 1:
      beverage = new Caffe();
      break;
    case 2:
      beverage = new Milk();
      break;
    case 3:
      beverage = new Tea();
      break;
    default:
      cout<<"Doesn't Exist"<<endl;
      goto start;
      break;
  }
  
  bool addon=false;
  cout<<"To Take Addon To The beverage Enter 1 , else 0:: ";
  cin>>chose;
  addon = chose != 0;
  while(addon) {
    cout<<"Chose Your Addon : "<<endl;
    cout<<"1 for Caramel"<<endl;
    cout<<"2 for Mocha"<<endl;
    cout<<"3 for Soya"<<endl;
    cin>>chose;
    switch (chose)
    {
      case 1:
        beverage = new Caramel(beverage);
        break;
      case 2:
        beverage = new Mocha(beverage);
        break;
      case 3:
        beverage = new Soya(beverage);
        break;
      default:
        cout<<"Doesn't Exist"<<endl;
        break;
    }
    cout<<"Add Another Addon Enter 1 , else 0 :: ";
    cin>>chose;
    addon = chose != 0;
  }
  cout<<"Your beverage Cost :: "<<beverage->Cost()<<endl;
}