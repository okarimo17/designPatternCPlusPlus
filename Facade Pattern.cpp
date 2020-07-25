#include <iostream>

using namespace std;

/*
  in this example Client(main function) can use shapes draw function by ShapesFacade ,
  it doesn't need to work with the actual shape classes (Circle square Rectangle ...).
*/

/*
Problem
- this pattern is to be used to facilitate access to a large
number of modules providing one layer
interface
• Consequences
+ facilitates the use of sub-systems
+ promotes weak coupling between classes and
the application
- BUT functionalities of interfaced classes
may be lost depending on how is
realized the ShapesFacade
*/

class Shape {
  public:
    virtual void Draw() = 0;
};


class Square:public Shape {
  public:
    void Draw(){
      cout<<"Square"<<endl;
      cout <<"****\n****\n****\n****"<<endl; 
    }
};

class Circle:public Shape {
  public:
    void Draw(){
      cout<<"Circle"<<endl;
      cout <<"  ** \n ****\n******\n ****\n  ** "<<endl; 
    }
};

class Rectangle:public Shape {
  public:
    void Draw(){
      cout<<"Rectangle"<<endl;
      cout <<"*******\n*******\n*******"<<endl; 
    }
};



class ShapesFacade {
  private:
    Circle * circle;
    Rectangle * rectangle;
    Square * square;    
  public:
    ShapesFacade(){
      this->circle = new Circle();
      this->rectangle = new Rectangle();
      this->square = new Square();   
    }
    void drawCircle(){
      this->circle->Draw();
    }
    void drawSquare(){
      this->square->Draw();
    }
    void drawRectangle(){
      this->rectangle->Draw();
    }
};


int main(){
  ShapesFacade * shapeFacade = new ShapesFacade();

  shapeFacade->drawCircle();
  shapeFacade->drawRectangle();
  shapeFacade->drawSquare();

  return 0;
}




