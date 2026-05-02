#include <iostream>
#include <exception>
using namespace std;
void check0(int);

class div0:public exception{ //Class จัดการ ตัวหารเป็น 0 
    public:
    virtual const char* what() const throw() {
        return "Dived by zero"; 
    }
};
class fail:public exception{ //Class จัดการ cinfail()
    public:
    virtual const char* what() const throw() {
        cin.clear();
        cin.ignore(50,'\n');
        return "You Need to input 2 integers "; 
    }
}f;

int main(){
    int x,y;
    double d;
    int a;
do{
    
    try{

        
        cout<<"Enter 2 numbers: ";
        cin>>x>>y;

        //Curated Exception Handling
        if(cin.fail()) throw fail();

        if((abs(x)<-10000 || abs(x)>1000 )||(abs(y)<-10000 || abs(y)>1000)) throw"value out of range";
        
        check0(y);


        //Normal Code
        d=(double) x/y;
        cout<<"The result is "<<d<<endl;

        int i;
        double * myarray;
        for(i=0;i<100000000;i++){
            cout<<"Allocating memory...."<<i<<endl;
            myarray=new double[5000000000000];
        }
        a=0;
}
/*    catch(const char* error){
        cerr<<error<<endl;
        a=1;

    }
    catch(const int e){
        switch(x){
            case 101: cerr<<"Incorrect numbers "<<endl; break;
            case 0: cerr<<"Divided by zero"<<endl; break;
        }
        a=1;
        cin.clear();
        cin.ignore(50,'\n');
    }*/
    catch(exception &e){
        cout<<e.what()<<endl;
        if(typeid(e)==typeid(bad_alloc)) a=0;
        else a=1;
    }


}while(a);
    return 0;
}


void check0(int x){
    div0 e;
    if(x==0) throw e;
}