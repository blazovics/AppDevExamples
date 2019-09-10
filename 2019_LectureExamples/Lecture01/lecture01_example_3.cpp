//Inheritance
/*
 * Related material about this topic
 * http://www.cplusplus.com/doc/tutorial/inheritance/
 */

class Animal{
    
    //protected members are unreachable from outside but can be reached from
    //descendant classes
protected:
    int headCount;
    
public:
    Animal(int headCount){
        this->headCount = headCount;
    }
    
    int getHeadCount(){
        return headCount;
    }
};

//The child class will be a specialized ParentClass
class Cow: public Animal{
    
private:
    int legCount;
    
public:
    //the constructor of the descendant class can call the parents constructor direcrtly
    //otherwise the default constructor will be called by default
    Cow(int legCount, int headCount):Animal(headCount){
        this->legCount = legCount;
    }
    int getLegCount(){
        return legCount;
    }
};

int main()
{
    //Mark, that there is no default constructor, so we cannot create a cow
    //without parameters
    Cow cow1(1,4);
    //calling the Cow's member function
    int legs = cow1.getLegCount();
    //calling the inherited member function
    int heads = cow1.getHeadCount();
    
    return 0;
}
