#include <iostream>


using namespace std;
/*
Problem
- this pattern is to be used when we want to decouple the implementation of the abstraction so that the two can vary independently
• Consequences
+ interfaces and implementations can be coupled / decoupled at runtime
*/


class ColorImplementor{//The Implementer Class
  public:
    virtual string getColor()=0;//The Implementer Operation
};
/* Start of Implementer Implemenation*/
class RedImplementer:public ColorImplementor {
  public:
    string getColor(){
      return "Red";
    }
};
class BlueImplementer:public ColorImplementor {
  public:
    string getColor(){
      return "Blue";
    }
};
class GreenImplementer:public ColorImplementor {
  public:
    string getColor(){
      return "Green";
    }
};


class ShapeAbstraction {//Abstraction Class
  protected:
    ColorImplementor *  colorImplementer;
  public:
    ShapeAbstraction(ColorImplementor * color):colorImplementer(color){}
    virtual void render()=0;
};
////Abstraction Class implemenation
class Sphere: public ShapeAbstraction{
  public:
    Sphere(ColorImplementor * color):ShapeAbstraction(color){}    
    void render(){
      cout <<"Sphere Shape "<<this->colorImplementer->getColor()<<endl;  
    }
};
class Cube: public ShapeAbstraction{
  public:
    Cube(ColorImplementor * color):ShapeAbstraction(color){}    
    void render(){
      cout <<"Cube Shape "<<this->colorImplementer->getColor()<<endl;  
    }
};

int main(){
  // if we didn't use the bridge pattern here 
  //than we have to make a class for every case we have (RedSphere , GreenSpheren,BlueSphere) and the same for cube Class 
  // so if we have a bigger number of Shapes or color classes number going to increase 
  ShapeAbstraction * redSphere = new Sphere(new RedImplementer());
  ShapeAbstraction * blueSphere = new Sphere(new BlueImplementer());
  ShapeAbstraction * greenSphere = new Sphere(new GreenImplementer());
  ShapeAbstraction * greenCube = new Cube(new GreenImplementer());

  redSphere->render();
  blueSphere->render();
  greenSphere->render();
  greenCube->render();
  
  return 0;
}