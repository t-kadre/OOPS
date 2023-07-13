#include <bits/stdc++.h>
using namespace std;
//operator overloading=extending the utility of pre-existing operators to user defined classes
//for eg-> we want fraction f3=f1+f2; to work so "+" operator should work on fraction class also
class Fraction {
	private :

		int numerator;
		int denominator;

	public :

		Fraction(int numerator, int denominator) {
			this -> numerator = numerator;
			this -> denominator = denominator;
		}

		void print() {
			cout << this -> numerator << " / " << denominator << endl;
		}


		void simplify() {
			int gcd = 1;
			int j = min(this -> numerator, this -> denominator);
			for(int i = 1; i <= j; i++) {
				if(this -> numerator % i == 0 && this -> denominator % i == 0) {
					gcd = i;
				}
			}
			this -> numerator = this -> numerator / gcd;
			this -> denominator = this -> denominator / gcd;
		}

		Fraction operator+(Fraction const &f2) const{ //constant reference so that no extra space and time is needed during making a copy of f2 and no one can change properties of f2 by f2.denominator=8
			int lcm = denominator * f2.denominator;
			int x = lcm / denominator;
			int y = lcm / f2.denominator;

			int num = x * numerator + (y * f2.numerator);

			Fraction fnew(num,lcm);
			fnew.simplify();
            return fnew;	
		}//if operator+ <-> add,Fraction f4=f1.add(f2) does the same thing as Fraction f4=f1+f2, here f1 is "this" and f2 is argument
        
        Fraction operator*(Fraction const &f2) const{//doing same thing for multiplication
            int a = numerator * f2.numerator;
			int b = denominator * f2.denominator;
			Fraction h(a,b);
			h.simplify();
            return h;
		};
        
        bool operator==(Fraction const &f)const{//these functions are constant functions as they aren't changing data members of current object
            return (numerator==f.numerator && denominator==f.denominator);
        };
        
        //PRE-INCREMENT UNARY OPERATOR SO NO ARGUMENT, it works on the same fraction that is calling it(this)
//if we dont return by reference,it makes a temporary copy of the fraction it is supposed to return and then returns the copy which is stored at some different address
        //so now if we do Fraction f6=++(++f1); it updates f1 by 2 and copies f1 in f6 by copy constructor
		//if we dont return by reference, f1 only gets updated by 1 and then that copy of f1 (which as updated by 1) gets updated and stored in f6
		Fraction& operator++(){
            numerator=numerator+denominator;
            simplify();
            return *this;
        };

		//POST-INCREMENT, nesting not allowed (i++)++ not allowed so no return by reference needed
		Fraction operator++(int){
			Fraction f(numerator,denominator);
			numerator=numerator+denominator;
			simplify();
			f.simplify();
			return f;
		};

		//+= overloading, nesting allowed, (i+=j)+=j updates value of i by 2j
		Fraction& operator+=(Fraction const &f){
			numerator=numerator*f.denominator+denominator*f.numerator;
			denominator=denominator*f.denominator;
			simplify();
			return *this;
		} 

};

int main(){

    return 0;
}