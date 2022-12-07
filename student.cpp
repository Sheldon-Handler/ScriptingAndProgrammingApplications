#include <iostream>
#include "student.h"
#include "degree.h"

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDaysInCourse(daysInCourse);
	setDegreeProgram(degreeProgram);
};

// getters for each instance variable
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int Student::getDaysInCourse() {
	return *daysInCourse;
}
DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

// setters for each instance variable
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysInCourse(int daysInCourse[]) {
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;

	if (degreeProgram == SECURITY) {
		this->degreeString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		this->degreeString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		this->degreeString = "SOFTWARE";
	};
}

// print() function for printing dataSets
void Student::print() { 
	cout << getStudentID() << "\t"
		<< "First Name: " << getFirstName() << "\t"
		<< "Last Name: " << getLastName() << "\t"
		<< "Email Address: " << getEmailAddress() << "\t"
		<< "Age: " << getAge() << "\t"
		<< "daysInCourse: " << "{" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}" << "\t"
		<< "Degree Program: " << degreeString << endl;
}
