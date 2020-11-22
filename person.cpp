#include "person.h"

personWIT_c::personWIT_c(){
	name = "empty";
	jobTitle = "empty";
	divDepMaj = "empty";
}

personWIT_c::personWIT_c(std::string name, std::string jobTitle, std::string divDepMaj){
	this->name = name;
	this->jobTitle = jobTitle;
	this->divDepMaj = divDepMaj;
}

void personWIT_c::print(){
//	std::cout << "***PERSON***\n";
	std::cout << "Name: " << name << std::endl;
	std::cout << "Job Title: " << jobTitle << std::endl;
	std::cout << "Division/Department/Major: " << divDepMaj << std::endl;
}

/***********************************************************************************/
student_c::student_c(){
	gradDate.year = 0;
	gradDate.month = 0;
	gradDate.day = 0;
	yearsLeft = 0;
	monthsLeft = 0;
	daysLeft = 0;
	minor = "empty";
	extracurricular = "empty";
}

student_c::student_c(std::string name, std::string jobTitle, std::string divDepMaj, int y, int m, int d, std::string minor, std::string extracurricular)
	:personWIT_c(name, jobTitle, divDepMaj){
	gradDate.year = y;
	gradDate.month = m;
	gradDate.day = d;
	this->minor = minor;
	this->extracurricular = extracurricular;
	calculateTime2Grad();
	std::cout << "Constructed student: " << name << "\n";
}

void student_c::setGradDate(int y, int m, int d){
        gradDate.year = y;
        gradDate.month = m;
        gradDate.day = d;
}

void student_c::calculateTime2Grad(){

	const int daysOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	yearsLeft = gradDate.year - 2020;	// todays year is 2020
	monthsLeft = gradDate.month - 11;	// todays month is 11
	if(monthsLeft < 0){
		yearsLeft -= 1;
		monthsLeft += 12;
	}
	daysLeft = gradDate.day - 7;		// todays day is 7
	if(daysLeft < 0){
		monthsLeft -= 1;
		if(monthsLeft < 0){
			yearsLeft -= 1;
			monthsLeft += 12;
		}
		if(gradDate.day < 2) daysLeft += daysOfMonth[12];
		else daysLeft += daysOfMonth[gradDate.month - 2];	// # of days in a month is dependent on what month it is
	}
}

void student_c::print(){
//	std::cout << "***STUDENT*** --> ";
	personWIT_c::print();
	std::cout << "Todays Date: 11/7/2020\n";
	std::cout << "Graduation Date: " << gradDate.month << "/" << gradDate.day << "/" << gradDate.year << std::endl;
	std::cout << "Time left until graduation: " << yearsLeft << " years, " << monthsLeft << " months, and " << daysLeft << " days\n";
	std::cout << "Minor: " << minor << std::endl;
	std::cout << "Extracurricular: " << extracurricular << std::endl;
}

/*************************************************************************/
faculty_c::faculty_c(){
	startDate.year = 0;
	startDate.month = 0;
	startDate.day = 0;
}

faculty_c::faculty_c(std::string name, std::string jobTitle, std::string divDepMaj, int y, int m, int d)
	:personWIT_c(name, jobTitle, divDepMaj){
	startDate.year = y;
	startDate.month = m;
	startDate.day = d;
	std::cout <<"Constructed faculty: " << name << "\n";
}

void faculty_c::setStartDate(int y, int m, int d){
	startDate.year = y;
	startDate.month = m;
	startDate.day = d;
}

void faculty_c::print(){
//	std::cout << "***FACULTY*** --> ";
	personWIT_c::print();
	std::cout << "Start date is " << startDate.month << "/" << startDate.day << "/" << startDate.year << std::endl;
}

/***************************************************************************/
void list_c::addHead(std::string &name, std::string &jobTitle, std::string &divDepMaj, int &year, int &month, int &day, std::string &minor, std::string &extracurricular){
	personWIT_c *newEntry = new student_c(name, jobTitle, divDepMaj, year, month, day, minor, extracurricular);
	if(!Head){
		Head = newEntry;
		Tail = newEntry;
		newEntry->next = NULL;
		newEntry->prev = NULL;
	}
	else{
		personWIT_c *temp = Head;
		newEntry->next = Head;
		temp->prev = newEntry;
		Head = newEntry;
		newEntry->prev = NULL;
	}
}

void list_c::addTail(std::string &name, std::string &jobTitle, std::string &divDepMaj, int &year, int &month, int &day, std::string &minor, std::string &extracurricular){
	personWIT_c *newEntry = new faculty_c(name, jobTitle, divDepMaj, year, month, day);
	if(!Tail){
		Head = newEntry;
		Tail = newEntry;
		newEntry->next = NULL;
		newEntry->prev = NULL;
	}
	else{
		personWIT_c *temp = Tail;
		newEntry->prev = Tail;
		temp->next = newEntry;
		Tail = newEntry;
		newEntry->next = NULL;
	}
}

void list_c::remove(std::string &nameToRemove){
	if(Head){
		int found = 0;
		personWIT_c *tempN = Head;
		while(tempN != NULL){
			if(tempN->getName() == nameToRemove){
				personWIT_c *hold = tempN;
				found++;
				if(tempN == Head){ // remove Head
					if(Head == Tail){ // delete last remaining element
						delete tempN;
						Head = NULL;
						Tail = NULL;
					}
					else{
						tempN = tempN->next;
						Head = tempN;
						delete hold;
						tempN->prev = NULL;
					}
				}
				else if(tempN == Tail){ // remove tail
					tempN = tempN->prev;
					Tail = tempN;
					delete hold;
					tempN->next = NULL;
				}
				else{ // remove middle
					personWIT_c *tempP = hold->prev;
					tempN = tempN->next;
					tempP->next = tempN;
					tempN->prev = tempP;
					delete hold;
				}
			}else tempN = tempN->next;
		}if(!found) std::cout << "Not found.\n";
	}else std::cout << "List is empty.\n";
}

void list_c::deleteAll(){
	if(Head){
		personWIT_c *temp = Head;
		while(temp != NULL){
			personWIT_c *hold = temp;
			temp = temp->next;
			delete hold;
		}
		Head = NULL;
		Tail = NULL;
	}std::cout << "List is empty.\n";
}

void list_c::search(std::string &nameToSearch){
	if(Head){
		int found = 0;
		personWIT_c *temp = Head;
		for(temp = Head; temp != NULL; temp = temp->next){
			if(temp->getName() == nameToSearch){
				temp->print();
				found++;
			}
		}if(!found) std::cout << "Not found.\n";
	}else std::cout << "List is empty.\n";
}

void list_c::printAll(){
	if(Head){
		personWIT_c *temp = Head;
		for(temp = Head; temp != NULL; temp = temp->next){
			temp->print();
			std::cout << std::endl;
		}
	}else std::cout << "List is empty.\n";
}
