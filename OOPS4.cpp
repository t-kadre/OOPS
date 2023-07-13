#include <bits/stdc++.h>
using namespace std;

//ENCAPSULATION=to combine/club data members and functions of an entity in a single unit->can be done using class
//eg->student class combines its properties/data members with its functions in a single unit
//ABSTRACTION=simple meaning is hiding, hiding the unnecessary details from the outside world
//eg->while using the inbuilt sort funcion in c++, we dont need to understand the details of the inside working of it
//eg->making properties as private in a class
//Reasons for implementing abstraction in code:1)updation/changes in internal code by coder wouldn't affect the working of the code written by end user
//2)to avoid errors by restricting end users to change the internal working/logic of the code

//INHERITANCE=if multiple classes have some common properties and some specific properties, we can create a parent class with those common properties and can tell the classes to inherit those properties from the parent class
//enables us to reuse the code and save time
//eg->vehicle class (parent class) with properties name, color, plate no. and car, truck, bike classes (child classes) which inherit properties of vehicle class along with some properties specific to themselves

//ACCESS MODIFIERS=the access power of "protected" lies in between public and private. protected properties of a parent class can be accessed within the parent class itselves and its child classes outside the parent class.
//PARENT CLASS=BASE CLASS, CHILD CLASS=DERIVED CLASS

class vehicle{//base class
    public:
    string color;
    vehicle(){
        cout<<"default vehicle constructor called"<<endl;
    };
    vehicle(int z){
        cout<<"parametrized vehicle constructor called"<<endl;
        maxSpeed=z;
    };
    ~vehicle(){
        cout<<"default vehicle destructor called"<<endl;
    };
    protected:
    int numTyres;
    private:
    int maxSpeed; 
};   

class car:public vehicle{//derived class inheriting base class publically->private properties of base class dont get inherited as they're private and cant be used outside the base class, whereas protected and public properties of base class are inherited. numTyres becomes protected property and color becomes public property of car class.
    public:
    int numGears;
    void print(){//maxSpeed cant be accessed even after inheriting publically
        cout<<"No. of Tyres: "<<numTyres<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"No. of Gears: "<<numGears<<endl;
    };
    car():vehicle(5){//vehicle parametrized constructor called instead of default
    //a derived class can call constructor of immediate parent only
        cout<<"default car constructor called"<<endl;
    };
    ~car(){
        cout<<"default car destructor called"<<endl;
    };
};

//PROTECTED INHERITANCE=private properties wont be inherited, public & protected properties of base class becomes protected properties of derived class
//PRIVATE INHERITANCE=private properties wont be inherited, public & protected properties of base class becomes private properties of derived class
//BY DEFAULT->PRIVATE INHERITANCE
//A->B->C = C inherits B, B inherits A. if we create an object of class C, firstly A() constructor called then B() then C()
//DESTRUCTOR ORDER COMPLETELY OPPOSITE
//these constructor destructor calls happens implicitly (automatically) BUT implicitly always DEFAULT CONSTRUCTOR 

//TYPES OF INHERITANCE: 1.SINGLE INHERITANCE= 1 PARENT CLASS, 1 CHILD CLASS= A->B
//2.MULTI-LEVEL INHERITANCE=A->B->C->D, CHAIN OF SINGLE PARENT CHILD
//3.HIERARCHAL INHERITANCE=MULTIPLE DERIVED CLASSES OF A SINGLE PARENT CLASS, A->B, A->C, A->D
//4.MULTIPLE INHERITANCE=SINGLE DERIVED CLASS FROM MULTIPLE PARENT CLASSES, A->B, C->B, D->B, for example class TA is derived from classes student and teacher
//class TA:public teacher, public student{
//} -> in this case, first teacher constructor called as its written first then student then TA
//if print function is in both teacher and student classes, and its called from an object of TA class, error, so to resolve this we need to specify which print function we want to call -> 
//TA a;
//a.print(); ERROR 
//a.student :: print();
//if TA class also has print function, then a.print() will execute print function of TA class, so it first checks TA class members then parent class members
//5.HYBRID/VIRTUAL INHERITANCE=MIX OF VARIOUS TYPES OF INHERITANCE, DIAMOND PROBLEM WHERE A->B, A->C, B->D, C->D. SO D CLASS HAS 2 COPIES OF A. THIS CREATES AMBIGUITY AS IF THERE IS A PRINT FUNCTION IN CLASS A AND WE CALL IT FROM AN OBJECT OF CLASS D, ERROR SHOWS AS COMPILER GETS CONFUSED AS 2 COPIES OF PRINT ARE THERE. 

int main(){
    vehicle v;//vehicle class ka constructor called
    v.color="red";
    //v.numTyres=4; WRONG as can only be accessed in the derived classes NOT outside derived classes
    //v.maxSpeed=120; WRONG as private property
    car c;//first vehicle class ka constructor called then car class ka constructor called as car class has some properties of vehicle class so we need to initialize those properties first using vehicle class constructor then we initialize car class specific properties
    c.color="blue";
    c.numGears=5;
    //c.numTyres=4; WRONG as its now a protected property of derived class so can only be accessed in the derived class and those classes which publically inherit this derived class

    return 0;
}