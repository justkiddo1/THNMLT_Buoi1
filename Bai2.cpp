#include <iostream>
#include <conio.h>
#include <time.h>
#include <ctime>
#include <string>

using namespace std;

struct Employee {
	string name;
	struct tm birthDate;
	string gender;
};
int calculateRetirementAge(const Employee& employee, const time_t& currentTime) {
	struct tm currentDate = *localtime(&currentTime);
	int currentYear = currentDate.tm_year + 1900;
	int currentMonth = currentDate.tm_mon + 1;
	int currentDay = currentDate.tm_mday;

	int retirementAge = (employee.gender == "M" ? 62 : 60);

	int yearToRetirement = retirementAge - (currentYear - employee.birthDate.tm_year);

	if (currentMonth < employee.birthDate.tm_mon + 1 || (currentMonth == employee.birthDate.tm_mon + 1 && currentDay < employee.birthDate.tm_mday)) {
		yearToRetirement--;
	}
	return yearToRetirement;
}
void inputEmployeeData(Employee& employee) {
	cout << "Enter employee name :";
	getline(cin, employee.name);
	cout << "Enter employee birth year";
	cin >> employee.birthDate.tm_year;
	cout << "Enter empoyee birth month (1-12) : ";
	cin >> employee.birthDate.tm_mon;
	employee.birthDate.tm_mon--;
	cout << "Enter employee birth day (1-31) :";
	cin >> employee.birthDate.tm_mday;
	cout << "Enter gender (M/F) : ";
	cin >> employee.gender;
}
void outputResult(const Employee& employee, int yearToRetirement) {
	cout << "Employee name : " << employee.name << endl;
	cout << "Retirement age : " << (employee.gender == "M" ? 62 : 60) << endl;
	cout << "Year to retirement : " << yearToRetirement << endl;
}
int main() {
	Employee employee;
	inputEmployeeData(employee);
	time_t currentTime = time(NULL);
	int yearToRetirement = calculateRetirementAge(employee, currentTime);
	outputResult(employee, yearToRetirement);
	return 0;
}