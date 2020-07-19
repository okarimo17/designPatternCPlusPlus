#include <iostream>
#include <vector>

using namespace std;
/*
Problem
- we want to ensure consistency between cooperating classes
while maintaining their independence
• Consequences
+ abstract coupling between a subject and an observer, support for
broadcast communication,
- BUT unexpected updates may occur, with
significant costs.

*/


class Observer{
  public:
    virtual void update()=0;
};

class Subject{
  private:
    vector <Observer *> Observers = vector <Observer *> (0);
    
  public:
    void attach(Observer * observer) {
      vector<Observer *>::iterator place = Observers.end();
      Observers.insert(place,observer);
    }

    void detach(Observer * observer) {
      for(vector<Observer *>::iterator iter = Observers.begin();iter != this->Observers.end();iter++){
        if(*iter == observer){
          Observers.erase(iter--);
          delete observer;
          break;
        }
      }
    }

    void notify(){
      for(Observer * obs:Observers){
        obs->update();
      }
    }
};

class ConcreteSubject : public Subject {
  private:
    string state = "";
  public:
    string getState(){
      return this->state;
    }
    void setState(string state){
      this->state = state;
      notify();
    }
};

class ConcreteObserver:public Observer {
  private:
    string state;
    ConcreteSubject * subject;
  public:
    ConcreteObserver(ConcreteSubject * subject = nullptr){
      this->subject = subject;
    }

    void update(){
      this->state = subject->getState();
      cout <<"name updated new :: "<<this->state<<endl;
    }
};

int main(){

  ConcreteSubject * myname = new ConcreteSubject();
  ConcreteObserver * chatOBS = new ConcreteObserver(myname);
  ConcreteObserver * chatOBS2 = new ConcreteObserver(myname);

  myname->attach(chatOBS);
  myname->attach(chatOBS2);

  myname->detach(chatOBS2);

  myname->setState("karimo");
  myname->setState("dizad");

  return 0;
}
