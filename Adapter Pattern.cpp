#include <iostream>

using namespace std;
/*
  Simply We allow client (main) to use SpecificOperation of the adapted class by calling operation on adapter class.
  Another Example we can adapt A linked list as stack or queue , were Stack/Queue Operation uses The linked list operations 
*/

/*
Problem
- Use of an existing class whose interface does not suit us (
convert the interface from one class to another)
- Use of several subclasses whose adaptation of interfaces is
not possible by derivation ( Object Adapter)
• Consequences
- Adapt class
+ it only introduces a new class, an indirection to the appropriate class
is not necessary
• BUT it will not work if the adapted class is the root of a
derivation
- Adapt object
+ it can work with several adapted classes
• BUT it can hardly redefine behaviors of the adapted class
*/

class Adapte {
  public:
    void specificOperation(){
      cout << "Adapte Operation Here."<<endl;
    }
};

class Target {
  public:
    virtual void operation() = 0;
};

class Adapter:public Target {
  private:
    Adapte * adapte=nullptr;
  public:
    Adapter(Adapte * adapte):adapte(adapte){}
    void operation() {
      this->adapte->specificOperation();
    }
};




int main(){
  Target * target = new Adapter(new Adapte);
  target->operation();
  return 0;
}