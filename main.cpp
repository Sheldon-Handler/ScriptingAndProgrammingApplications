#include <iostream>
#include <vector>
#include <string>
#include "student.h"
#include "roster.h"
#include "degree.h"
using namespace std;

int main() {

	// details at top of printout screen
	cout << "Scripting and Programming - Applications" << "\t" << "C++" << "\t" << "007830903" << "\t" << "Sheldon Handler" << endl;
	cout << endl;

	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Sheldon,Handler,shandl8@wgu.edu,24,0,0,7,SOFTWARE" };

//	string strDegree[] = {"SECURITY", "NETWORK", "SOFTWARE"};

	// define individual classRoster
	Roster classRoster{};

	// parse each substring into temp array while removing the "," seperator
	string temp[9] = {};
	string tempString = "";
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	DegreeProgram degree = DegreeProgram::NETWORK;

	for (size_t i = 0; i < 5; i++) {
		string tempString = studentData[i];
		for (size_t j = 0; j < 8; j++) {
			size_t position = tempString.find(',');
			temp[j] = tempString.substr(0, position);
			tempString.erase(0, position+1);
		}
		temp[8] = tempString;
		tempString.clear();

		// convert numbers to int
		age = atoi(temp[4].c_str());

		// convert days in courses to int array
		daysInCourse1 = atoi(temp[5].c_str());
		daysInCourse2 = atoi(temp[6].c_str());
		daysInCourse3 = atoi(temp[7].c_str());

		// convert string to enum DegreeProgram
		if (temp[8] == "SECURITY") {
			degree = DegreeProgram::SECURITY;
		}
		else if (temp[8] == "NETWORK") {
			degree = DegreeProgram::NETWORK;
		}
		else if (temp[8] == "SOFTWARE") {
			degree = DegreeProgram::SOFTWARE;
		}

		// insert from temp array into classRosterVector using the add() function created in roster.h
		classRoster.add(temp[0], temp[1], temp[2], temp[3], age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	};

	// print entire classRosterArray
	classRoster.printAll();

	// print all invalid emails in classRosterVector
	classRoster.printInvalidEmails();

	// print average days in course for each student in classRoster
	for (size_t i = 0; i < classRoster.newRoster.size(); i++) {
		classRoster.printAverageDaysInCourse(classRoster.newRoster.at(i).getStudentID());
	};

	// print all student roster entries for SOFTWARE
	classRoster.printByDegreeProgram(SOFTWARE);

	// remove student with studentID "A3" from classRoster
	classRoster.remove("A3");

	//// print entire classRoster
	classRoster.printAll();

	// try removing a student that was already removed to get the error message
	classRoster.remove("A3");

	// running destructor
	_Destroy_in_place(classRoster);
};
