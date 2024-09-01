    #include <iostream>
    #include <cmath>
    using namespace std;
    class SimpleCal{
        protected:
        double num1;
        double num2;
        public:
        SimpleCal(): num1(0), num2(0) {}
        void setnums(double num1, double num2){
            this->num1 = num1;
            this->num2 = num2;
        }
        double plus(){
        return num1+num2;
        }
        double sub(){
        return num1-num2;
        }
        double mult(){
        return num1*num2;
        }
        double div(){
        if(num2==0){
            throw runtime_error("Error: Division by zero, Please use any number greater than zero");
        }
        return num1/num2;
        }
    };
    class SciCal{
        public:
        double srt(double n1){
            if(n1>=0){
            return sqrt(n1);
            }
            else{
            throw runtime_error("Error : Negative input for square root, Please use number equal aur greater than zero");
            }
        }
        double crt(double n1){
            return cbrt(n1);
        }
    };
    class HybirdCal : public SciCal, public SimpleCal{
        public:
        void perfromCalculation(){
        int x,y;
        char z;
        cout<<"Enter number A : ";
        cin>>x;
        cout<<"------ For Example : + , - , * , / , SquareRoot -> s, CubeRoot -> c-------------------"<<endl;
        cout<<"Enter Calculation type : ";
        cin>>z;
            setnums(x,y);
        switch(z){
            case 's' :
            cout<<"√"<<x<<" = " <<srt(x);
            break;
            case 'c' :
            cout<<"³√"<<x<<" = " <<crt(x);
            break;
            case '+' :
            case '-' :
            case '*' :
            case '/' :
        cout<<"Enter number B : ";
        cin>>y;
        }
        setnums(x,y);
        switch (z)
        {
        case '+' :
            cout<<x<<" + "<<y<<" = " <<plus();
            break;
        case '-' :
            cout<<x<<" - "<<y<<" = " <<sub();
            break;
        case '*' :
            cout<<x<<" * "<<y<<" = " <<mult();
            break;
        case '/' :
            cout<<x<<" / "<<y<<" = " <<div();
            break;
        case 's' :
            break;
        case 'c' :
            break;
            default:
            cout<<endl<<"------------ N/A ------------"<<endl;
            cout<<endl<<"Please enter valid input (+,-,*,/,s,c)\n"<<endl;
        }
        }
    };
    int main(){
        HybirdCal calculation;
        calculation.perfromCalculation();
    return 0;
    }