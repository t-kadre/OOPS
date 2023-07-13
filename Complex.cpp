class ComplexNumbers{
    private:
    int real;
    int imaginary;
    public:
    void print(){
        if(imaginary<0){
            cout<<real<<"-i"<<imaginary*(-1)<<endl;
        }else{
            cout<<real<<"+i"<<imaginary<<endl;
        }
    };
    void plus(ComplexNumbers const &c){
        real=real+c.real;
        imaginary=imaginary+c.imaginary;
    };
    void multiply(ComplexNumbers const &c){
        int x=real,y=imaginary;
        real=x*c.real-y*c.imaginary;
        imaginary=x*c.imaginary+y*c.real;
    };
    ComplexNumbers(int a,int b){
        real=a;
        imaginary=b;
    };
    ~ComplexNumbers(){
    };
};