/*********
Jackson Smith
Professor Aaron Carpenter
Object Oriented Programming for Engineers
Quest 6: Data Structures
*********/

#include "person.h"

int main(){

	int choice = 0;
	std::string name, jobTitle, divDepMaj, minor, extracurricular, temp;
	int day = 0, month = 0, year = 0;
	list_c FullList;

	std::ifstream inputStudent("6.0-student.txt");
	if(inputStudent.fail()){
		std::cout << "Unable to open file 6.0-student.txt.\nShutting down ...\n";
		return 1;
	}
	std::ifstream inputFaculty("6.0-faculty.txt");
	if(inputFaculty.fail()){
		std::cout << "Unable to open file 6.0-faculty.txt.\nShutting down ...\n";
		return 1;
	}
	for(int i = 0; i < 1; i++){
		getline(inputStudent, name);
		getline(inputStudent, jobTitle);
		getline(inputStudent, divDepMaj);
		inputStudent >> year;
		inputStudent >> month;
		inputStudent >> day;
		inputStudent.ignore();
		getline(inputStudent, minor);
		getline(inputStudent, extracurricular);
		FullList.addHead(name, jobTitle, divDepMaj, year, month, day, minor, extracurricular);
	}
	for(int i = 0; i < 5; i++){
		getline(inputFaculty, name);
		getline(inputFaculty, jobTitle);
		getline(inputFaculty, divDepMaj);
		inputFaculty >> year;
		inputFaculty >> month;
		inputFaculty >> day;
		inputFaculty.ignore();
		FullList.addTail(name, jobTitle, divDepMaj, year, month, day, minor, extracurricular);
	}
	std::cout << "List populated.\n";

	do{
		std::cout << "___________________\n";
		std::cout << "1. Print \n2. Search for person \n3. Add a student \n4. Add a faculty \n5. Remove a person \n6. Delete all \n0. Quit \n";
		std::cout << "Choice: "; std::cin >> choice;
		std::cout << "___________________\n\n";
		switch(choice){
			case 1: FullList.printAll(); break;
			case 2: {
				std::cin.ignore();
				std::cout << "Enter person's name: "; getline(std::cin, name);
				std::cout << std::endl;
				FullList.search(name);
				break;
			}
			case 3: {
				std::cin.ignore();
				std::cout << "Enter student's details.\n";
				std::cout << "Name: "; getline(std::cin, name);
				jobTitle = "Student";
				std::cout << "Major: "; getline(std::cin, divDepMaj);
				std::cout << "Graduation year: "; std::cin >> year;
				std::cout << "Graduation month: "; std::cin >> month;
				std::cout << "Graduation day: "; std::cin >> day;
				std::cin.ignore();
				std::cout << "Minor: "; getline(std::cin, minor);
				std::cout << "Extracurricular: "; getline(std::cin, extracurricular);
				std::cout << std::endl;
				FullList.addHead(name, jobTitle, divDepMaj, year, month, day, minor, extracurricular);
				break;
			}
			case 4: {
				std::cin.ignore();
				std::cout << "Enter faculty's details.\n";
				std::cout << "Name: "; getline(std::cin, name);
				std::cout << "Job title: "; getline(std::cin, jobTitle);
				std::cout << "Division/Departement/Major: "; getline(std::cin, divDepMaj);
				std::cout << "Start year: "; std::cin >> year;
				std::cout << "Start month: "; std::cin >> month;
				std::cout << "Start day: "; std::cin >> day;
				std::cin.ignore();
				std::cout << std::endl;
				FullList.addTail(name, jobTitle, divDepMaj, year, month, day, minor, extracurricular);
				break;
			}
			case 5: {
				std::cin.ignore();
				std::cout << "Enter person's name: "; getline(std::cin, name);
				std::cout << std::endl;
				FullList.remove(name);
				break;
			}
			case 6: {
				FullList.deleteAll();
				break;
			}
		}
	}while(choice);

	return 0;
}
