using namespace std;
#include "Date.h"
#include <vector>
class Employee {
private:
    const int number,type;
    const string name,surname,title;
    const double salary;
    const Date birth,appointment;
    const int lengthofservice;
public:
    static vector<int> numbers;
    Employee(int number,int type,string name,string surname,string title,double salary
            ,Date birth,Date appointment);
    Employee(int number,int type,string name,string surname,string title,double salary
            ,Date birth,Date appointment,int length);
    Employee();
    void getData();

    int getEmployeeNumber() const;

    void setEmployeeNumber(int employeeNumber);

    int getEmployeeType() const;

    void setEmployeeType(int employeeType);

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    const string &getTitle() const;

    double getSalary();

    void setSalary(double salary);

    const Date &getDateofBirth() const;

    void setDateofBirth(const Date &dateofBirth);

    const Date &getDateofAppointment() const;

    void setDateofAppointment(const Date &dateofAppointment);

    int getLenghtofService() const;

    void setLenghtofService(int lenghtofService);

    friend ostream &operator<<(ostream &os, const Employee &employee);

    void setTitle(string &title);

};