#include <iostream>
#include <list>

using namespace std;

/*
"Compose objects into tree structures to represent part-whole hierarchies. Composite lets
clients treat individual objects and compositions of objects uniformly." [GoF]
*/

class AbstractShape {
  public:
    virtual void draw() = 0;
    virtual string getPosition()=0;
    virtual void add(AbstractShape * child){
    }
    virtual void remove(AbstractShape * child){
    }
};

class Shape : public AbstractShape {

  private:
    list <AbstractShape *> childs;

  public:
    void add(AbstractShape * child)  {
      childs.push_back(child);
    }
    void remove(AbstractShape * child)  {
      childs.remove(child);
    }
    void draw(){
      cout<<"Drawing Shape :: "<<endl;
      for(AbstractShape * child:childs){
        child->draw();
      }
    } 
    string getPosition(){
      string position = "{";
      for(AbstractShape * child:childs){
        if(child == childs.back()){
          position += child->getPosition()+"}";
        }else {
          position += child->getPosition()+",";
        }
      }
      return position;
    }

};

class Point:public AbstractShape {
  private:
    int x;
    int y;
    
  public:
    Point(int x,int y):x(x),y(y){
    }
    void draw(){
      cout<<"Draw Point :: ("<<x<<","<<y<<")"<<endl;
    }
    string getPosition(){
      return  ("(") + to_string(x) + "," + to_string(y) +")";
    }
};

int main(){
  AbstractShape * shape = new Shape();

  shape->add(new Point(0,1));
  shape->add(new Point(2,3));
  shape->add(new Point(4,5));
  shape->add(new Point(7,8));

  cout<<"Shape Points Position :: "<<shape->getPosition()<<endl;

  AbstractShape * point = new Point(4,5);
  cout<<"Point Position :: "<<point->getPosition()<<endl;


  return 0;
}