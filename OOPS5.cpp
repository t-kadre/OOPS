#include <bits/stdc++.h>
using namespace std;
//POLYMORPHISM=simple meaning of this word is many forms, in our context, this occurs when a code behaves differently in different situations or different context

//Compile time polymorphism=at compile time we'll decide what we need to do, what operations we need to perform
//Can be achieved using function overloading or operator overloading and method overriding or function overriding
//function overloading=when we have different functions with same name but different number of arguments, the compiler decides at compile time which function it needs to execute depending upon the number of arguments we pass in that
//we CANT differentiate functions with same name & same number of arguments even if the return types are different
//function overriding=when there is a function in the base class and derived class also creates a function with the same name, that function overrides as now if we write that function's name through derived class, we always access the derived class one unless specified using scope resolution operator at compile time
//pointer of base class can point to an object of derived class BUT vice versa IS NOT TRUE.  
//pointer of base class which is pointing to an object of derived class can only access properties of base class. Example:
// vehicle->car. car c. vehicle *v=&c. (if car & vehicle both have print functions). v->print() THIS LINE CALLS print of vehicle class as the pointer v is of vehicle class so the compiler goes to vehicle class for print function at compile time. 

//Run time polymorphism=at run time we'll decide what we need to do, what operations we need to perform
//to execute this, we need virtual functions
//virtual functions=those functions which are present in base class and are overriden in derived class. eg-virtual void print()
//adding "virtual" keyword in functions in base class & creating same name function in derived class, we override those functions at run time
//adding "virtual" keyword tells the compiler to check which print to call at run time NOT compile time
//IF NO "virtual" keyword, compile time
//now, v->print() calls print function of car class as at run time it calculates by seeing which class's object is v pointing to, in this case, car class ka object

//PURE virtual functions are those virtual functions that have NO definition. Eg - virtual void print()=0; 
//ABSTRACT CLASS=those classes which contain PURE virtual function. These classes are incomplete as they have function with no definition. We CANT CREATE OBJECT OF ABSTRACT CLASS as when we create object of any class, all its properties are initialized, but if a property is incomplete, we cant create object. 
//derived classes of abstract class, either they can complete all the pure virtual functions by overriding their definitions OR they can themselves become abstract class. Used where we want to force child classes to make certain functions.
//FOR EXAMPLE OF USAGE OF THESE THINGS, WATCH VIDEO

//if we want to use private & protected data members of a class in certain functions in another class, we can make those functions friend of the class. These are friend functions.
void test();
class bus{
    public:
    void print();//print function of bus class is friend function of truck class
    //access x, y, z of truck
    //now we cant define print function here as it access x, y, z of truck class BUT truck class not yet defined so we only declare friend function in class and define them afterwards 
};
class truck{
    private:
    int x;
    protected:
    int y;
    public:
    int z;
    //friend void bus::print(); ERROR as compiler starts reading from top to bottom and till now, we dont have any bus class as its defined after truck class
    friend void bus::print();// now no error
    friend void test();
    //Friend functions DONT have access to "this" keyword as they're NOT part of the class. Friend functions can be under any access modifiers, it DOESNT matter.
    friend class bus;//bus class is FRIEND CLASS of truck class and can access all data members of truck class BUT NOT VICE VERSA.
};
void test(){
    truck t;
    t.x=10;
    t.y=20;
    t.z=30;
    cout<<t.x<<" "<<t.y<<" "<<t.z<<endl;
}
//bus class now defined before truck class
void bus::print(){//defining friend class
    truck t;
    t.x=10;
    t.y=20;
    t.z=30;
    cout<<t.x<<" "<<t.y<<" "<<t.z<<endl;
}
int main(){
    bus b;
    b.print();
    test();
    return 0;
}