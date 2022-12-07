#pragma once
#include <iostream>
#include <vector>
#include "degree.h"
#include "student.h"

class Roster {
public:

	vector<Student*> classRosterArray;

	// add a student to the roster
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	// remove a student from the roster
	void remove(string studentID);

	// print complete list of student data
	void printAll();

	// print average number of days in three courses
	void printAverageDaysInCourse(string studentID);

	// print invalid email addresses
	void printInvalidEmails();

	// print the information of each student in a specific degree program
	void printByDegreeProgram(DegreeProgram degreeProgram);

	vector<Student> newRoster;
};
