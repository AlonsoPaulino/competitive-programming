#include<iostream>
using namespace std;
int main ()
{
        int testCases;
        int num1 , num2;
 
        cin>>testCases;
       
        for(int i=0; i<testCases ; i++)
        {
                cin>>num1>>num2;
                if(num1 > num2){
                        cout<<">"<<endl;
                }
                else if(num1 < num2){
                        cout<<"<"<<endl;
                }
                else {
                        cout<<"="<<endl;
                }
        }
        return 0;
}