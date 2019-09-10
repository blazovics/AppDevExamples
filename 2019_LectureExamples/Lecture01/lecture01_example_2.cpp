/*
 * Related material about this topic
 * http://www.cplusplus.com/doc/tutorial/classes/
 */

//A class encapsulates variables and function with three different access rights into one structure

//a class declaration starts with the class keyword
//It is usually located in a header file (i.e.: MyClass.h)
class MyClass{
    //this is a private variable it cannot be access from outside
    int privateInt;
    
    //below this keyword all variable and function will be private
private:
    bool privateBool;
    //until we use different access specifier
    //below this specifier everything will be public
public:
    
    int publicInt;
    //Contructor, default constructor
    //Does not have a return type
    MyClass();
    
    //Another constructor
    MyClass(int publicInt, int privateInt);
    
    //Destructor
    //Will be called indirectly
    ~MyClass();
    
    //Copy Constructor
    //Takes anothe class instance as reference
    MyClass(MyClass &otherInstance);
    
    //simple member function
    void simplePublicFunction();
};

//Implementaion of a class.
//It is usually located in a .cpp file (i.e.: MyClass.cpp)
//Only the functions can be implemented

//implementing the constructor
MyClass::MyClass(){
    //this is a special pointer which points to the actual object
    this->privateInt = 0;
    //if a local variable does not have the same name, the this can be omitted
    privateBool = false;
}

//Implementation of the other constructor
MyClass::MyClass(int publicInt, int privateInt)
{
    //In this case using the this pointer is mandatory
    this->publicInt = publicInt;
    this->privateInt = privateInt;
}

//Implementation of the copy constructor
MyClass::MyClass(MyClass &theOther){
    this->publicInt = theOther.publicInt;
    this->privateInt = theOther.privateInt;
    this->privateBool = theOther.privateBool;
}

//implementation of a member function
void MyClass::simplePublicFunction()
{
    //some function
}


int main()
{
    //instatiation of a class
    //m1 will be an instance of the class
    //Default constructor will be called
    MyClass m1;
    
    //calling the other constructor
    MyClass m2(1,2);
    
    //reaching the member variables of a class instance
    m1.publicInt = 33;
    
    //calling member fuction
    m1.simplePublicFunction();
    
    return 0;
}
