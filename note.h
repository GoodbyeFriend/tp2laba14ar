#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>

class NOTE {
private:
	std::string first_name;
	std::string last_name;
	long long phone;
	int birthday[3];
public:
	NOTE(std::string fname, std::string lname, long long num, int* bth);
	NOTE(const NOTE& obj);
	NOTE();

	~NOTE();

	friend std::ostream& operator << (std::ostream& os, const NOTE& clown);

	friend std::istream& operator >> (std::istream& in, NOTE& clown);

	friend bool operator<(const NOTE& a, const NOTE& b);
	friend bool operator>(const NOTE& a, const NOTE& b);

	void push(std::string fname, std::string lname, long long num, int* buff_array);

	std::string getName();
	std::string getSecondName();
	long long getNumber();
	int getBirthday(int i);
};

