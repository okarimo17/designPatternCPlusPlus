#include <iostream>


using namespace std;
/*
  IDatabase :: is the subject interface,
  RealDatabase :: is RealSunject class
  ProxyDatabaes :: the proxy class , RealDatabase object gonna instanciated only in need.
*/
/*
  Problem
  - this pattern is to be used to act by proxy for an object in order to control the operations which are applied to it
  • Hide access problems (eg: file)
  • Delay the execution of costly operations
  • Control access rights
  • Consequences
  + added a level of indirection when accessing an object to hide the fact that the object is in another address space, is not created, ...
*/
/*
  there is three common types of proxy :: 
    virtual       :: defer object creation until they are actually needed.
    protection    :: check if the client the required access rights.
    remote proxy  :: hide complex network communications.
    in this example i have tried to implement a virtual proxy for database simple case.
*/

class IDatabase {
  public:
    virtual void query(string req) = 0;
};

class RealDatabase : public IDatabase{
  private:
    // in real world project this gonna a db connection variable not just string
    string databaseConnection = "";
  public:
    RealDatabase(string dbURI){
      // here cames connection to database code
      databaseConnection = dbURI;
    }
    void query(string req){
      cout<<"Result of Request :: "<<req<<endl;
    }
};

class ProxyDatabase:public IDatabase{
  private:
    string dbURI = "";
    RealDatabase * databaseInstance = nullptr;
  public: 
    ProxyDatabase(string dbURI):dbURI(dbURI){
    }
    void query(string req){
      if(databaseInstance == nullptr)
        databaseInstance = new RealDatabase(this->dbURI);
      this->databaseInstance->query(req);
    }    

};

int main(){ 
  ProxyDatabase * proxy = new ProxyDatabase("mysql://localhost:3000/dbname");

  proxy->query("select * from users ");

  return 0;
}