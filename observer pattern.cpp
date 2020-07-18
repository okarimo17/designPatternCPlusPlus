#include <iostream>
#include <vector>

using namespace std;
/*
Problème
– on veut assurer la cohérence entre des classes coopérant
entre elles tout en maintenant leur indépendance

• Conséquences
+ couplage abstrait entre un sujet et un observeur, support pour
la communication par diffusion,
– MAIS des mises à jour inattendues peuvent survenir, avec
des coûts importants.

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