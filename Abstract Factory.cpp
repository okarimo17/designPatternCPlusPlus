#include <iostream>

using namespace std;


/*
Problem
- this pattern is to be used in situations where there is a need to work
with product families while being independent of the type of these
products
- must be configured by one or more product families
• Consequences
+ Separation of concrete classes, customer classes
• the names of the product classes do not appear in the customer code
• Facilitates the exchange of product families
• Promotes consistency between products
+ The creation process is clearly isolated in a classroom
- the introduction of new products in the AbstractFactory is not
easy
*/


class Button {
  protected:
    string label;
  public:
    Button(string label):label{label}{}
    virtual string buttonUI() = 0;
};

class Card {
  protected:
    string childNode;
  public:
    Card(string childNode):childNode{childNode}{}
    virtual string cardUI() = 0;
};

class UIAbstractFactory{
  public:
    virtual Button * createButton(string label)=0;
    virtual Card * createCard(string childNode)=0;
};

class LightButton:public Button {
  public:
    LightButton(string label=""):Button(label){}
    string buttonUI(){
      return "<button style='color:#ddd;'>"+this->label+"</button>";
    }
};

class LightCard:public Card {
  public:
    LightCard(string childNode=""):Card(childNode){}
    string cardUI(){
      return "<div style='color:#ddd;'>\n\t"+this->childNode+"\n</div>";
    }
};

class LightModeUIFactory:public UIAbstractFactory {
  public:
    Button * createButton(string label=""){
      return new LightButton(label);
    }
    Card * createCard(string childNode=""){
      return new LightCard(childNode);
    }    
};

class DarkButton:public Button {
  public:
    DarkButton(string label=""):Button(label){}
    string buttonUI(){
      return "<button style='color:#333;'>"+this->label+"</button>";
    }
};

class DarkCard:public Card {
  public:
    DarkCard(string childNode=""):Card(childNode){}
    string cardUI(){
      return "<div style='color:#333;'>\n\t"+this->childNode+"\n</div>";
    }
};

class DarkModeUIFactory:public UIAbstractFactory {
  public:
    Button * createButton(string label=""){
      return new DarkButton(label);
    }
    Card * createCard(string childNode=""){
      return new DarkCard(childNode);
    }    
};



int main(){

  UIAbstractFactory * UICreater = nullptr ;
  
  int theme = 0;
  choseTheme:
  cout << "Chose Theme Mode :: "<<endl<<"1 for Light Mode"<<endl<<"2 for Dark Mode"<<endl;
  cin>>theme;
  switch (theme)
  { 
    case 1:
      UICreater = new LightModeUIFactory();
      break;
    case 2:
      UICreater = new DarkModeUIFactory();
      break;
    default:
      goto choseTheme;
      break;
  }
  system("cls");
  cout << "Rendering UI For The Theme :: "<<endl;
  Button * btn = UICreater->createButton("Register");
  Card * card = UICreater->createCard(btn->buttonUI());
  cout<<card->cardUI()<<endl;
  return 0;
}