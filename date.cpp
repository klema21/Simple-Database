using namespace std;

int Date::GetYear() const {
	return year.value;
}

int Date::GetMonth() const {
	return month.value;
}

int Date::GetDay() const {
	return day.value;
}

bool operator == (const Date &lhs, const Date &rhs){
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) ==
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator != (const Date &lhs, const Date &rhs) {
	return !(lhs == rhs);
}

bool operator < (const Date &lhs, const Date &rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <
           make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator <=(const Date& lhs, const Date& rhs) {
	return (lhs < rhs) || (lhs == rhs);
}

bool operator > (const Date &lhs, const Date &rhs) {
	return !(lhs <= rhs);
}

bool operator >= (const Date &lhs, const Date &rhs) {
	return !(lhs < rhs);
}

ostream &operator << (ostream &os, const Date &date) {
	os << setfill('0');

	os << setw(4) << date.GetYear() << "-"
       << setw(2) << date.GetMonth() << "-"
       << setw(2) << date.GetDay();

	return os;
}

Date ParseDate(istream &is) {
    int year;
    is >> year;

    is.ignore();

    int month;
    is >> month;
    is.ignore();

    int day;
    is >> day;

    return {year, month, day};
}
