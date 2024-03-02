#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char op;
    float num1,num2,result;

    cout<<"Welcome To MathMaverick"<<endl<<endl;
    
    cout<<"Enter operator (+, -, *, /, %) : ";
    cin>>op;
    cout<<endl;
    
    cout<<"Enter First Number : ";
    cin>>num1;
    cout<<endl;
    
    cout<<"Enter Second Number : ";
    cin>>num2;
    cout<<endl;
    
    switch(op){
 
        case'+':
        result=num1+num2;
        cout<<"Result of "<<num1<<" "<<op<<" "<<num2<<" = "<<result<<endl<<endl;
        break;
 
        case'-':
        result=num1-num2;
        cout<<"Result of "<<num1<<" "<<op<<" "<<num2<<" = "<<result<<endl<<endl;
        break;
 
        case'*':
        result=num1*num2;
        cout<<"Result of "<<num1<<" "<<op<<" "<<num2<<" = "<<result<<endl<<endl;
        break;
 
        case'/':
        if(num2 != 0) {
        result=num1/num2;
        cout<<"Result of "<<num1<<" "<<op<<" "<<num2<<" = "<<result<<endl<<endl;
        } 
        else{
        cout << "Error : Division By Zero Is Not Possible"<<endl<<endl;
        }
        break;
        
        case '%':
        int n1,n2;    // Converting Floats To Integers Because Modulus Function Does Not Operates With Float Data Type
        n1=num1;
        n2=num2;
        result=n1%n2;
        cout<<"Result of "<<num1<<" "<<op<<" "<<num2<<" = "<<result<<endl<<endl;;
        break;
     
        default:
        cout << "Error : Invalid operator";
        }

return 0;
}

