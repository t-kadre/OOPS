#include <bits/stdc++.h>
using namespace std;
class vehicle{
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
    void print(){
        cout<<"vehicle"<<endl;
    };
    protected:
    int numTyres;
    private:
    int maxSpeed;
}; 
class car:virtual public vehicle{
    public:
    car(){
        cout<<"default car constructor called"<<endl;
    };
};
class truck:virtual public vehicle{
    public:
    truck(){
        cout<<"default truck constructor called"<<endl;
    };
};
class bus:public car, public truck{
    public:
    bus(){
        cout<<"default bus constructor called"<<endl;
    };
};
int main(){
    bus b;//constructor order->vehicle, car, vehicle, truck, bus
    //b.print(); ERROR as print() function found in multiple base classes as 2 vehicles are there, 1 in car, 1 in truck
    //to remove this: 1.we can add print function in bus class itself
    //2.explicitly mention which class we want to access by scope resolution operator 
    b.car::print();//b.vehicle::print(); wouldn't help as there is vehicle in car and truck
    //IF WE CREATE A print() function in car also so above line will call print function of car not vehicle

    //NOW TO AVOID UNNECESSARY COPYING OF CLASS vehicle IN CLASS bus, WE ADD KEYWORD "virtual" WHILE INHERITING vehicle CLASS
    //now constructor order-> vehicle, car, truck, bus
    //bus directly calls vehicle first as car and truck dont have real vehicle objects but instead have pointers pointing to vehicle objects so it seems like both car & truck uses one vehicle object which was called by bus class itself 
    //bus has all 3 classes
    //ONLY IN VIRTUAL INHERITANCE CASES CAN CHILD CLASS CALL GRAND-PARENT CLASSES
    return 0;
}