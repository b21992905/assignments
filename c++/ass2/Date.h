class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(string date);
    Date();
    bool operator<(const Date &rhs) const;
    bool operator>(const Date &rhs) const;
    bool operator<=(const Date &rhs) const;
    bool operator>=(const Date &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const Date &date);
};