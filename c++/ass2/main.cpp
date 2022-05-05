#include <iostream>
using namespace std;
#include "Employee.h"
int main() {
    string operations="___ Employee Recording System ___\n+"
                      "Please select for the following Menu Operations:\n+"
                      "1) Appointment of a new employee\n+"
                      "2) Appointment of a transferred employee\n+"
                      "3) Updating the title and salary coefficient of an employee\n+"
                      "4) Deletion of an employee\n+"
                      "5) Listing the information of an employee\n+"
                      "6) Listing employees ordered by employee number\n+"
                      "7) Listing employees ordered by appointment date\n+"
                      "8) Listing employees appointed after a certain date\n+"
                      "9) Listing employees assigned in a given year\n+"
                      "10) Listing employees born before a certain date\n+"
                      "11) Listing employees born in a particular month\n+"
                      "12) Listing the information of the last assigned employee with a given title";
    do{
        int x;
        cout<<operations<<endl;
        cin>>x;
        if(x==1){
            Employee *e1;
            e1->getData();
            delete e1;
        }else if(x==2){

        }else if(x==3){

        }else if(x==4){

        }else if(x==5){

        }else if(x==6){

        }else if(x==7){

        }else if(x==8){

        }else if(x==9){

        }else if(x==10){

        }else if(x==11){

        }else{

        }

    }while(true);
}