#include "Employee.h"
Employee::Employee(int number, int type, int name, int surname, int title, double salary, Date birth,
                   Date appointment) { this->lengthofservice=0;
            numbers.push_back(number);
            sort(numbers);}
Employee::Employee(int number, int type, int name, int surname, int title, double salary, Date birth, Date appointment,
                   int length) {numbers.push_back(number);}
}
Employee::Employee() {
}

void Employee::getData() {
    cout<<"Please type the employee number"<<endl;
    int num;cin>>num;
    if(Employee->numbers){
        cout<<"Bu numaraya sahip çalışan zaten bulunmaktadır"<<endl;
        return;
    }
    cout<<"Type the employee type"<<endl;
    int type1;cin>>type1;
    cout<<"Type the name"<<endl;
    string name1;
    getline(cin,name1);
    cout<<"Type the surname"<<endl;
    string sname;
    getline(cin,sname);
    cout<<"Type the title"<<endl;
    string title1;
    getline(cin,title1);
    cout<<"Type salary coefficient"<<endl;
    double num2;cin>>num2;
    cout<<"Type birth date"<<endl;
    string date;getline(cin,date);
    cout<<"Type appointment date"<<endl;
    string date2;getline(cin,date2);
    Employee Employee(num,type1,name1,sname,title1,num2,date,date2);
}
int Employee::getEmployeeNumber() const {
    return employeeNumber;
}

void Employee::setEmployeeNumber(int employeeNumber) {
    Employee::employeeNumber = employeeNumber;
}

int Employee::getEmployeeType() const {
    return employeeType;
}

void Employee::setEmployeeType(int employeeType) {
    Employee::employeeType = employeeType;
}

const string &Employee::getName() const {
    return name;
}

void Employee::setName(const string &name) {
    Employee::name = name;
}

const string &Employee::getSurname() const {
    return surname;
}

void Employee::setSurname(const string &surname) {
    Employee::surname = surname;
}

const string &Employee::getTitle() const {
    return title;
}

void Employee::setTitle(string &title) {
    cout<<"new title : " <<title<<endl;
    Employee::title = title;
}

double Employee::getSalary() {
    return salary;
}

void Employee::setSalary(double salary) {
    cout<<"new salary : " <<salary<<endl;
    Employee::salary = salary;
}

const Date &Employee::getDateofBirth() const {
    return dateofBirth;
}

void Employee::setDateofBirth(const Date &dateofBirth) {
    Employee::dateofBirth = dateofBirth;
}

const Date &Employee::getDateofAppointment() const {
    return dateofAppointment;
}

void Employee::setDateofAppointment(const Date &dateofAppointment) {
    Employee::dateofAppointment = dateofAppointment;
}

int Employee::getLenghtofService() const {
    return lenghtofService;
}

void Employee::setLenghtofService(int lenghtofService) {
    Employee::lenghtofService = lenghtofService;
}


ostream &operator<<(ostream &os, const Employee &employee) {
    os << "Employee Number: " << employee.employeeNumber << " Employee Type: " << employee.employeeType << " Name: "
       << employee.name << " Surname: " << employee.surname << " Title: " << employee.title << " Salary: "
       << employee.salary << " Date of Birth: " << employee.dateofBirth << " Date of Appointment: "
       << employee.dateofAppointment << " Lenght of Service: " << employee.lenghtofService;
    return os;
}