#include "note.h"

NOTE::NOTE(std::string fname, std::string lname, long long num, int* bth) {
    first_name = fname;
    last_name = lname;
    phone = num;
    for (int i = 0; i < 3; i++) {
        birthday[i] = bth[i];
    }
}
NOTE::NOTE(const NOTE& obj) {
    first_name = obj.first_name;
    last_name = obj.last_name;
    phone = obj.phone;
    for (int i = 0; i < 3; i++) {
        birthday[i] = obj.birthday[i];
    }
}
NOTE::NOTE() {
    first_name = "";
    last_name = "";
    phone = 0;
    birthday[0] = 0;
    birthday[1] = 0;
    birthday[2] = 0;
    std::cout << "Called constructor of NOTE" << std::endl;
}

NOTE::~NOTE() {
    std::cout << "CAlled destructor of NOTE" << std::endl;
}

std::ostream& operator << (std::ostream& os, const NOTE& note) {
    os << "Name: " << note.first_name << std::endl
        << "Second name: " << note.last_name << std::endl
        << "Date of birth: ";
    for (int i = 0; i < 2; i++) {
        os << note.birthday[i] << ".";
    }
    os << note.birthday[2] << std::endl << "Mobile phone " << note.phone << std::endl << std::endl;
    return os;
}

std::istream& operator>> (std::istream& in, NOTE& note) {
    std::string str1;
    std::string str2;
    long long num;
    int buff_array[3];
    std::cout << "Enter name: ";
    in >> str1;
    std::cout << "Enter second name: ";
    in >> str2;
    std::cout << "Enter mobile phone: ";
    in >> num;
    std::cout << "Enter day of birth: ";
    in >> buff_array[0];
    std::cout << "Enter month of birth: ";
    in >> buff_array[1];
    std::cout << "Enter year of birth: ";
    in >> buff_array[2];
    note.push(str1, str2, num, buff_array);
    return in;
}

bool operator<(const NOTE& a, const NOTE& b) {
    int buff_a = a.phone / 100000000;
    int buff_b = b.phone / 100000000;
    return buff_a < buff_b;
}
bool operator>(const NOTE& a, const NOTE& b) {
    int buff_a = a.phone / 100000000;
    int buff_b = b.phone / 100000000;
    return buff_a > buff_b;
}

void NOTE::push(std::string fname, std::string lname, long long num, int* buff_array) {
    first_name = fname;
    last_name = lname;
    phone = num;
    for (int i = 0; i < 3; i++) {
        birthday[i] = buff_array[i];
    }
}

std::string NOTE::getName() { return first_name; }
std::string NOTE::getSecondName() { return last_name; }
long long NOTE::getNumber() { return phone; }
int NOTE::getBirthday(int i) { return birthday[i]; }