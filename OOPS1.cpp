#include <bits/stdc++.h>
using namespace std;
//implementing functions to access/change properties of objects
//CLASS is basically a blueprint that defines the properties and functions of a particular object (say student)
//classes are user defined data types
//an OBJECT is a specific copy of class (say s1 is an object which is a copy of student class)
class student{
    public://public,private,and protected access modifiers
    int roll;//2 properties of class student -> roll no. and age
    int age;//these properties have their access modifiers as public so they are visible and accessible outside the class in main function
    //if not mentioned, properties have their access modifiers as private meaning those properties are only visible and accessible within that class 
    int GetPhone(){
        return phone;
    }

    //default constructor looks like the one below (empty with no return type and arguments), gets called in main function while declaring an object so public
    student(){//if I comment out this function, student s1; will give error 
        //we can add anything like cout<<"constructor called"<<endl; in this to see when its called, it'll work the same as before
    }//if constructor is mentioned explicitly in class then this is always used while declaring an object
    //PARAMETRIZED CONSTRUCTOR below as it takes arguments
    student(int a){
        roll=a;//sets roll=a and rest to garbage values
    }
    student(int roll,int age){
    //roll=roll; doesnt make a difference as when variables of same name being accessed, that variable is used which has closest scope(in this case, argument roll) 
    this->roll=roll;//"this" keyword holds the address of current object
    }
    ~student(){//destructor
    }
    private:
    int phone;//private properties of a class CAN BE ACCESSED only by the functions inside the class
};
//if a class is defined in a different file and we want to create objects of that class in this file so we have to include that file here
//"#include "file.cpp" -> all the code in file.cpp is copied and pasted here in this line 
//file.cpp should be in the same location as this file
int main(){
    //creating a variable with name s1 (which is actually an object, not a variable) which is of type student
    student s1;//8 bytes(4 for roll, 4 for age) statically allocated with garbage value in properties for s1 while declaring
    student* ss=new student;//DYNAMICALLY ALLOCATING 8 bytes of memory in heap(4 for roll, 4 for age) and 8 bytes in stack for pointer variable
    s1.roll=24;
    s1.age=69;
    (*ss).age=99;
    (*ss).roll=9;
    ss->age=8;
    //IMP (*ss).age IS SAME AS ss->age
    cout<<s1.GetPhone()<<endl;//to access phone property which is private we use this function = getter function
    //when "student s1;" is written it acts as "s1.student();"   
    //student() is function that sets each member/property of s1 object to garbage value
    //so this function is called the default CONSTRUCTOR: same name as class,no return type,no input arguments
    //this constructor is made automatically when creating a class if not created explicitly in class
    student s4(10);//parametrized constructor called
    //FOR EVERY OBJECT ONLY ONE CONSTRUCTOR IS CALLED, AND ONE TIME IN THEIR LIVES, as one declaration
    student*g=new student(33);//same thing done dynamically
    //COPY CONSTRUCTOR used when we want to create an object s2 having same values of properties as s1
    //created automatically when creating class
    student s2(s1);//passing whole object as argument
    s4=s1;//copy assignment operator, copies s1 to s4 when both s1 and s4 are already created
    //DESTRUCTOR deallocates the memory of object->same name as class,no return type,no input arguments
    //created automatically when creating class, called one time automatically when scope of object finishes in stack memory
    //if explicitly creating constructor, we have to explicitly create destructor as well
    //in heap memory, we have to explicitly write "delete ss;" to call destructor on *ss
    student s5=s1;//copy constructor is called, its read as student s5(s1);
    
    return 0;
}