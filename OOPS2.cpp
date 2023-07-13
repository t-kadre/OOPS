#include <bits/stdc++.h>
using namespace std;
class student{
    public:
    int age;
    char* name;
    static int total_students;//static property belongs to a class, not object as its same for every object, if we create object then copy of class with non-static properties will be created
    //if an object wants to access static property it will do so through class as static property will remain in class, object=copy of class with non-static properties
    //this static property will contain the number of objects created so in body of constructor we add total_students++
    student(){
        total_students++;
    };
    //STATIC FUNCTIONS BELONG TO CLASS AND ARE FUNCTIONS WHICH CAN ONLY ACCESS OR ALTER STATIC DATA MEMBERS/PROPERTIES, THEY CANT ACCESS NON-STATIC PROPERTIES OR FUNCTIONS
    //STATIC FUNCTIONS CANT ACCESS "this" keyword
    static int getTotal(){
        return total_students;
    };//student::getTotal();
    student(int age,char * name){
        total_students++;
        this->age=age;//copies whole age value to age property of student
        //this->name=name; //shallow copy, means it only copies the index of first element of array in name, should be avoided
        //deep copy = making full copy of array in new array then making name property of student class point to that new array
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    };
    void display(){
        cout<<name<<" "<<age<<endl;
    };
    //creating copy constructor with deep copy
    //as soon as we write our own copy constructor, inbuilt one is not valid and not available to us
    //if we dont pass by reference, an infinite loop occurs as s argument has a copy of s1(look in main) which involves calling copy constructor, which has argument s which again has a copy of s1 and so on
    //hence we have to pass by reference so as to avoid the copying of s1 involving the very same copy constructor we are creating
    //"student(student s){ body };" is same as "student s = main.s1;" which doesnt involve copy assignment operator but copy constructor
    student(student const &s){//now s and s1 are just alias, and s.age=0 isnt possible as its constant student, we only want to read
        total_students++;
        this->age=s.age;
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
    };
};
int student::total_students=0;//initialization of static property done outside class like this

//writing student1 s3; initializes properties of s3 with garbage values, even const int and that cant be changed later
class student1{
    public:
    int age1;
    const int roll;//declaration and initialization of const has to be done simultaneously
    //using initialization list we create a constructor so that we can initialize const variables with input from user
    student1(int r,int age1):roll(r),age1(age1){//can initialize all variables including const ones
    };
};


int main(){
    char name[]="abcd";//name contains address of first index of array
    student s1(20,name);
    //student s2(s1);//INBUILT COPY CONSTRUCTOR always does shallow copy, so s2.name will also point towards address of s1.name
    student s2(s1);//copy constructor with deep copy called
    //fraction const f; constant object of fraction class created with garbage value initialization of properties
    //YOU CAN ONLY CALL CONSTANT FUNCTIONS FROM CONSTANT OBJECTS
    //CONSTANT FUNCTIONS ARE FUNCTIONS WHICH DOESNT CHANGE ANY PROPERTY OF CURRENT OBJECT
    //add "const" after writing all arguments in () just before {} to declare a function as constant as allow the compiler to at least call that function
    //now if in that function no property of current object is being changed, then no error otherwise error 
    cout<<student::total_students<<endl;//access static property using scope resolution operator [class_name]::[static_property_name]
    //s1.total_students=7; will work and change total_students to 7 in class for every object of class student, but this is logically incorrect
    
    return 0;
}