#include <iostream>

using namespace std;

/*
Problem
- we want to perform queries on objects without
have to know their structure
• Consequences
+ decoupling between the object that calls and the one that
executed
+ adding new commands is easy in the
as far as modifying existing classes is not
not necessary
*/


class Command {
  public:
    virtual void execute () = 0;
};


class LampReceiver {
  private:
    bool lampActive = false;
  public:
    void turnOn(){
      cout << "Lamp Turned On ."<<endl;
      this->lampActive = true;
    }
    void turnOff(){
      cout << "Lamp Turned Off ."<<endl;
      this->lampActive = false;
    }
};

class TurnOnCommand:public Command {
  private:
    LampReceiver * lamp=nullptr;
  public:
    TurnOnCommand(LampReceiver * lamp):lamp(lamp){} 
    void execute(){
      this->lamp->turnOn();
    }
};

class TurnOffCommand:public Command {
  private:
    LampReceiver * lamp=nullptr;
  public:
    TurnOffCommand(LampReceiver * lamp):lamp(lamp){} 
    void execute(){
      this->lamp->turnOff();
    }
};

class LightInvoker{
  private:
    Command * turnOn = nullptr;
    Command * turnOff = nullptr;
  public:
    LightInvoker(Command* turnOn,Command* turnOff):turnOn(turnOn),turnOff(turnOff){}
    void turnLightOn(){
      this->turnOn->execute();
    }
    void turnLightOff(){
      this->turnOff->execute();
    }    
};


int main(){
  LampReceiver * lampRec = new LampReceiver();

  LightInvoker * lightInvoke = new LightInvoker(new TurnOnCommand(lampRec),new TurnOffCommand(lampRec));
  
  lightInvoke->turnLightOn();
  lightInvoke->turnLightOff();
  
  
  return 0;
}