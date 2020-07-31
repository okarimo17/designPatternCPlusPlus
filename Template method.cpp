#include <iostream>

using namespace std;

/*
"Define the skeleton of an algorithm in an operation, deferring some steps to subclasses.
Template Method lets subclasses redefine certain steps of an algorithm without changing
the algorithm's structure."
gof book definition
*/


class AbstractArticleTemplate {
  public:
    void renderTemplate() final {
      cout<<"<div id='article-page'>"<<endl;
      cout<<pageHeader()<<endl<<pageContent()<<endl<<pagefotter();
      cout<<endl<<"</div>"<<endl;
    }
    virtual string pageHeader()=0;
    virtual string pageContent()=0;
    virtual string pagefotter()=0;
};
class ArticleTemple1:public AbstractArticleTemplate{
  public:
    string pageHeader(){
      return "<div id='header'>article Title</div>";
    }
    string pageContent(){
      return "<div id='article-content'>if you need anything from the ...</div>";
    }
    string pagefotter(){
      return "<div id='fotter'>written by : karimo17</div>";
    }
};

class ArticleTemple2:public AbstractArticleTemplate{
  public:
    string pageHeader(){
      return "<header id='title-holder'><h1 color='green'>article Title</h1></header>";
    }
    string pageContent(){
      return "<p id='content'>if you need anything from the ...</p>";
    }
    string pagefotter(){
      return "<fotter><h3>written by : karimo17<h3/></fotter>";
    }
};

int main(){

  AbstractArticleTemplate * theme1 = new ArticleTemple1();
  AbstractArticleTemplate * theme2 = new ArticleTemple1();
  cout<<"Rendereing Template 1 :: "<<endl;
  theme1->renderTemplate();
  cout<<"Rendereing Template 2 :: "<<endl;
  theme2->renderTemplate();
  

  return 0;
}