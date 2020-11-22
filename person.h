#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <fstream>

struct date_s{
	int day, month, year;
};

/*****************************************/
class personWIT_c{
	protected:
		std::string name, jobTitle, divDepMaj;
	public:
		personWIT_c *next, *prev;
		personWIT_c();
		personWIT_c(std::string, std::string, std::string);
		virtual ~personWIT_c(){ std::cout << "Person " << name << " destructed.\n"; }

		std::string getName(){ return name; }
		std::string getJob(){ return jobTitle; }
		std::string getDivDepMaj(){ return divDepMaj; }

		virtual void print();
};

/***********************************/
class student_c:public personWIT_c{
	private:
		date_s gradDate;
		int daysLeft, monthsLeft, yearsLeft;
		std::string minor, extracurricular;
	public:
		student_c();
		student_c(std::string name, std::string jobTitle, std::string divDepMaj, int y, int m, int d, std::string minor, std::string extracurricular);
		~student_c(){ std::cout << "Student " << name << " destructed. --> "; }

		void setGradDate(int, int, int);
		void setMinor(std::string minor){ this->minor = minor; }
		void setExtracurricular(std::string extra){ extracurricular = extra; }

		date_s getGradDate(){ return gradDate; }
		int getDaysLeft(){ return daysLeft; }
		int getMonthsLeft(){ return monthsLeft; }
		int getYearsLeft(){ return yearsLeft; }
		std::string getMinor(){ return minor; }
		std::string getExtracurricular(){ return extracurricular; }

		void calculateTime2Grad();
		void print();
};

/*************************************/
class faculty_c:public personWIT_c{
	private:
		date_s startDate;
	public:
		faculty_c();
		faculty_c(std::string name, std::string jobTitle, std::string divDepMaj, int y, int m, int d);
		~faculty_c(){ std::cout << "Faculty " << name << " destructed. --> "; }

		void setStartDate(int, int, int);

		date_s getStartDate(){ return startDate; }

		void print();
};

/**********************************/
class list_c{
	protected:
		personWIT_c *Head, *Tail;
	public:
		void addHead(std::string &, std::string &, std::string &, int &, int &, int &, std::string &, std::string &);
		void addTail(std::string &, std::string &, std::string &, int &, int &, int &, std::string &, std::string &);
		void remove(std::string &);
		void deleteAll();
		void search(std::string &);
		void printAll();
		list_c(){
			Head = NULL;
			Tail = NULL;
		}
		~list_c(){
			deleteAll();
		}
};

#endif
