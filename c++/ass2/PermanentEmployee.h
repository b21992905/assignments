class PermanentEmployee : Employee {
public:
    PermanentEmployee(int employeeNumber, int employeeType, const string &name, const string &surname,
                      const string &title, double salary, const Date &dateofBirth, const Date &dateofAppointment,
                      int lenghtofService);
    PermanentEmployee();
};