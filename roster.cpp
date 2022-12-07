#include <iostream>
#include <vector>
#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;

// add a student to the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	// create Student to add to Roster
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	newRoster.push_back(Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram));

	// update classRosterArray[] to match newRoster[]
	classRosterArray.push_back(&newRoster[newRoster.size() - 1]);

};

// remove a student from the roster
void Roster::remove(string studentID) {

	bool flag = false;

	// erase the pointer from classRosterArray and object from newRoster
	for (size_t i = 0; i < newRoster.size(); i++) {
		if (newRoster.at(i).getStudentID() == studentID) {
			classRosterArray.erase(classRosterArray.begin() + i);
			newRoster.erase(newRoster.begin() + i);
			flag = true;
			break;
		}
	}

	// update classRosterArray[] if studentID was found
	if (flag == false) {
		cout << "studentID not found" << endl;
	}
};

// print complete list of student data
void Roster::printAll() {
	for (size_t i = 0; i < newRoster.size(); i++) {
		newRoster.at(i).print();
	}
};

// print average number of days in three courses
void Roster::printAverageDaysInCourse(string studentID) {
	for (size_t i = 0; i < newRoster.size(); i++) {
		if (newRoster.at(i).getStudentID() == studentID) {
			int days[3] = { newRoster.at(i).getDaysInCourse() };
			int average = (days[0] + days[1] + days[2]) / 3;
			cout << average << endl;
		}
	}
};

// print invalid email addresses
void Roster::printInvalidEmails() {
	for (size_t i = 0; i < newRoster.size(); i++) {
		if (newRoster.at(i).getEmailAddress().find(" ") || !(newRoster.at(i).getEmailAddress().find("@")) || !(newRoster.at(i).getEmailAddress().find("."))) {
			cout << newRoster.at(i).getEmailAddress() << endl;
		}
	}
};

// print the information of each student in a specific degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (size_t i = 0; i < newRoster.size(); i++) {
		if (newRoster.at(i).getDegreeProgram() == degreeProgram) {
			newRoster.at(i).print();
		}
	}
};
