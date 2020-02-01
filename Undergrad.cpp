/* 
 * File:   s_beaton_Undergrad.cpp
 * Author: Sawyer Beaton
 * I have abided by the UNCG Academic Honor Code on this assignment.
 * 
 * A C++ Program that uses STL and inheritance to output and organize 
 * student information read from a file.
 * 
 * REQUIRES "Students.txt" TO OPERATE.
 * 
 * Sample formatting for Students.txt:
 * 
 * Andrew 9173546 Senior 11 3.8
 * Greg 5647851 Junior 12 2.0
 * etc.
 */

// Includes statements
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

//Student class (Base class)
class Student {

public:
	Student(const char[], const char[], const float, const int);
        // Getters
	void getName()const;
	void getSSN()const;
	float getGPA()const{return gpa;}
	int getCredit()const{return credits;}
	virtual float tuition()const = 0;
	virtual void print()const;

// Declarations
protected:
	char name[21];
	char ssn[10];
	float gpa;
	int credits;

};

// Constructor
Student::Student(const char sNamess[]= " ", const char sSSN[] = " ", 
	const float sGpa = 0, const int sCredit = 0){
	for(int i = 0; i < 20; i++){
		name[i] = sNamess[i];
	}
	for(int i = 0; i < 10; i++){
		ssn[i] = sSSN[i];
	}
	gpa = sGpa;
	credits = sCredit;
}

// Builds name from chars
void Student::getName()const{
	for(int i = 0; i < 20 && (name[i] != 0); i++){
		cout << name[i];
	}
}

// Builds SSN from chars
void Student::getSSN()const{
	for(int i = 0; i < 11 && (ssn[i] != 0); i++){
		cout << ssn[i];
	}
}

// Prints Student info
void Student::print() const{
	cout << "Name: "; 
	getName();
	cout << endl;
	cout << "SSN: ";
	getSSN();
	cout << endl;
	cout << setprecision(2) << fixed << "GPA: " << getGPA() << endl;
	cout << "Credits: " << getCredit() << endl;
}

#endif

// Undergrad class that inherits from Student class
#ifndef X_UNDERGRAD_H
#define X_UNDERGRAD_H

class X_Undergrad : public Student{

// Declarations
protected:
	float undergrad_rate;
	char year[10];

public:
	X_Undergrad(const char[], const char[], const float, const int, const char[], const float);
	// Getters
        void get_year()const;
	float get_rate()const{return undergrad_rate;}
	// Setter
        void set_year(char*);
	
	virtual float tuition() const;
	virtual void print() const;
	bool operator<(const X_Undergrad &rhs)const;
	friend ostream& operator<<(ostream & out, const X_Undergrad &rhs);
};

// Constructor
X_Undergrad::X_Undergrad(const char sNames[], const char sSSN[], const float sGpa, 
	const int sCredit, const char sYear[] = " ", const float sUGRate = 0.0):
	Student(sNames, sSSN, sGpa, sCredit), undergrad_rate(sUGRate){
		for(int i = 0; i < 10; i++){
			year[i] = sYear[i];
		}
};

void X_Undergrad::set_year(char uYear[10]){
	*year = *uYear;
}

void X_Undergrad::get_year()const{
	for(int i = 0; i < 10 && (year[i] != 0); i++){
		cout << year[i];
	}
}

float X_Undergrad::tuition()const{
	return credits * undergrad_rate;
}

// Prints Undergraduate Information
void X_Undergrad::print()const{
	Student::print();
	cout << "Year: " << year << endl;
	cout << "Tuition: $" << tuition() << endl;
}

// Aligns information correctly using ostream formatting
ostream& operator<<(ostream & out, const X_Undergrad &rhs){
	out << setw(20) << left << rhs.name;
	out << setw(10) << left << rhs.ssn;
	out << setw(10) << left << rhs.year;
	out << setw(10) << left << rhs.credits;
	out << "$" <<  setw(9) << right << setprecision(2) << fixed << rhs.tuition();
	out << setw(10) << right << setprecision(2) << fixed << rhs.gpa;
	return out;
}

bool X_Undergrad::operator<(const X_Undergrad &rhs)const{
	if(gpa < rhs.gpa)
		return true;
	else 
		return false;
}
#endif

#ifndef GRAD_H
#define GRAD_H

//Graduate class that inherits Student class
class Grad: public Student{

protected:
        // Variable declarations
	float grad_rate;
	char* thesis;

public:
	Grad(const char[], const char[], const float, const int, const float, char*);
	// Getters
        char* get_thesis()const{return thesis;}
	float get_rate()const{return grad_rate;}
	// Setter
        void set_thesis(char* &);	
	virtual float tuition()const;
	virtual void print()const;
};

// Constructor
Grad::Grad(const char sName[], const char sSSN[], const float sGpa, const int sCredit, 
	const float sGradRate = 0, char* sThesis = " "):
	Student(sName, sSSN, sGpa, sCredit), grad_rate(sGradRate), 
	thesis(sThesis){};

// Determines and sets thesis
void Grad::set_thesis(char*& sThesis){
	thesis = sThesis;
}

// Calculates and returns tuition
float Grad::tuition() const{
	return credits * grad_rate;
}

// Print information for Grad Student
void Grad::print()const{
	Student::print();
	cout << "Year: Graduate Student" << endl; 
	cout << "Tuition: $" << tuition() << endl;
	cout << "Thesis: " << get_thesis() << endl;
}
#endif


#ifndef GRADASST_H
#define GRADASST_H

// Graduate Assist class that inherits Student class
class GradAsst: public Grad{

private:
        // Variable declarations
	float hourPay;
	char* superviser;
	char* task;

public:
	GradAsst(const char[], const char[], const float, const int, const float, char*, char*, const float, 
	char*);
	// Getters
        char* get_superviser()const{return superviser;}
	float get_hourPay()const{return hourPay;}
        char* get_task()const{return task;}
	// Setters
        void set_superviser(char*);
	void set_hourPay(float);
	void set_task(char*);	
	virtual float tuition()const;
	virtual void print()const;
};

// Constructor
GradAsst::GradAsst(const char sName[], const char sSSN[], const float sGpa, 
	const int sCredit, const float studentGrad_rate, char* studentThesis, char* sTask = " ", 
	const float sPay = 0, char* sSupervisor = " "):
	Grad(sName, sSSN, sGpa, sCredit, studentGrad_rate, studentThesis), 
	task(sTask), hourPay(sPay), superviser(sSupervisor){};

void GradAsst::set_superviser(char* gSupervisor){
	superviser = gSupervisor;
}

void GradAsst::set_hourPay(float gPay){
	hourPay = gPay;
}

// Calculate and return the tuition rate
float GradAsst::tuition()const{
	return credits * grad_rate;
}

void GradAsst::set_task(char* gTask){
	task = gTask;
}

void GradAsst::print()const{
	Grad::print();
	cout << "Task: " << get_task() << endl;
	cout << "Hourly Pay: $" << get_hourPay() << endl;
	cout << "Supervisor: " << get_superviser() << endl;
}


#endif

int main(){
	// Pointer  
	Student *sPointer;
	const float under_rate = 380.0;
	const float grad_rate = 500.0;

	//Information for the three students
	                      
	X_Undergrad sMary("Mary", "000111222", 4.0, 12, "Junior", under_rate);
	Grad sDavid("David", "111222333", 3.7, 9, grad_rate, "How to learn data structures using C++/STL?");
	GradAsst sJason("Jason", "222333444", 3.9, 9, grad_rate, "Design of efficient algorithms", 
		"Grading 330 projects and implementing a data mining algorithm", 20.00, "Dr. Fu");
	
	sPointer = &sMary;
	sPointer -> print();
	cout << endl;
		
	sPointer = &sDavid;
	sPointer -> print();
	cout << endl;

	sPointer = &sJason;
	sPointer -> print();
	cout << endl << endl;
	
	cout << "Unsorted Student List:" << endl << endl;
	ifstream fin;
	fin.open("Students.txt");
	if(!fin){
		cerr << "No Students.txt found. Please try again. \n";
		exit(1);
	}
	
	list<X_Undergrad> Undergrad;
	char sNames[21], sSSN[10], sYear[10];
	int sCredit;
	float sGpa;

	while(fin >> sNames >> sSSN >> sYear >> sCredit >> sGpa){
		X_Undergrad temp = X_Undergrad(sNames, sSSN, sGpa, sCredit, 
			sYear, under_rate);
		Undergrad.push_back(temp);
	}

	// Removes last student in student in list and places them in front
	Undergrad.push_front(Undergrad.back());
	Undergrad.pop_back();
	
        // Align print out
	cout.setf(ios::left);
	cout << setw(20) << "Name" << setw(10) << "SSN" << setw(10) << "Year" << setw(10) << "Credits" 
		<< setw(10) << "Tuition" << setw(10) << "GPA" << endl;
        
        // Create an iterator to go through the list
	list<X_Undergrad>::const_iterator listIterator = Undergrad.begin();
	
	for(int i = 0; i < Undergrad.size(); i++){
		X_Undergrad temp = *listIterator;
		cout << temp << endl;
		listIterator++;
	}
	cout << endl << endl;
	cout << "Sorted Student List by GPA:" << endl << endl;
	vector<X_Undergrad> vector;
	listIterator = Undergrad.begin();

	for(int i = 0; i < Undergrad.size(); i++){
		vector.push_back(*listIterator);
		listIterator++;
	}

	// Sort students by GPA and print sorted list by using a vector
	sort(vector.begin(), vector.end());
	cout << left << setw(20) << "Name" << setw(10) << "SSN" << setw(10) << "Year" << setw(10) << "Credits" 
		<< setw(10) << "Tuition" << setw(10) << "GPA" << endl;
	for(int i = 0; i < vector.size(); i++)
		cout << vector[i] << endl;
	cout << endl;

        char end;
	cout << "Press a character and hit Enter to exit program!" << endl;
	cin >> end;
	return 0;
}
