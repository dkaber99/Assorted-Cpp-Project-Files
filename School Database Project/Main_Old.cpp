#include <iostream>
#include "User.h"
#include "Admin.h"
#include "Instructor.h"
#include "Student.h"
#include <sqlite3.h>

using std::string;
using std::cin;
using std::cout;
using namespace::std;
sqlite3* db;
void addstudent(student newStud);
void deletedata(string delname);
//void editadmin();
//void querydata();
static int callback(void* NotUsed, int argc, char** argv, char** azColName);
int main() {
	int active = 1;
	string courses[10];
	user* test = new user();
	student* teststudent = new student();
	Admin* testadmin = new Admin();
	Instructor* testinstructor = new Instructor();
	test->printinfo(); cout << "\n";
	test->setfirstname("Ryan");
	test->setlastname("Lenoy\n");
	test->setId("123456789");
	test->printinfo();
	cout << "\n";
	
	

	
	//char* messageerror;
	//editadmin();
	//querydata();
	deletedata("Grace");
	//cout << "Student Removed";
	addstudent(*teststudent);
	//void sqlite3_free(ERROR MESSAGE FROM EXEC);
	
	
	
	while (active != 0) {
		cout << "Welcome enter an id \n1.Student\n2.Instructor\n3.Admin\n0.Exit\n";
		cin >> active;
		if (active == 1) {
			cout << "Hello student\nChoose a function\n1.Search courses\n2.Add Courses\n3.Drop Course\n4.Print Schedule\n";
			cin >> active;
			switch (active) {

			case(1):
				teststudent->searchcourse();
				break;
			case(2):
				teststudent->addcourse();
				break;

			case(3):
				teststudent->dropcourse();
				break;
			case(4):
				teststudent->printsched();
			}
		}
			else if (active == 2) {
				cout << "Hello instructor\nChoose a function\n1.Print courses available\n2.Print Schedule\n";
				cin >> active;
				switch (active) {

				case(1):
					testinstructor->searchcourses();
					break;

				case(2):
					testinstructor->printsched();
					break;
				}
			}
			else if (active == 3) {
					cout << "Hello Admin\nChoose a function\n1.Add Course 2. Remove Course 3. Add User 4. Remove User 5. Print Roster 6.Print Courses\n";
					cin >> active;
					switch (active) {

					case(1):
						testadmin->addtolist();
						break;
					case(2):
						testadmin->removeuser();
						break;
					case(3):
						testadmin->adduser();
						break;
					case(4):
						testadmin->removeuser();
						break;
					case(5):
						testadmin->printroster();
						break;
					case(6):
						testadmin->printcourses();
						break;
					}
				}
			else if(active != 0) {
			cout << "Invalid Option";
		}
				
			}
		
	cout << "Test Complete";
	
	return 0;
}
static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	for (int i = 0; i < argc; i++) {
		cout << azColName[i] << ": " << argv[i] << endl;
	}
	cout << endl;
	return 0;
}
void addstudent(student newStud) {
	sqlite3* db;
	const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
	sqlite3_open(pathto, &db); //Create pointer
	string sql("INSERT INTO STUDENT(ID,NAME,SURNAME,GRADYEAR,MAJOR,EMAIL) VALUES( 19023,'Todd','Howard',2024,'BSCO','howardt');");
	//string sql("INSERT INTO STUDENT (ID,NAME,SURNAME,GRADYEAR,MAJOR,EMAIL) VALUES(" + newStud.getID() +"," + newStud.getname() +", 2024,BSCO," + newStud.returnemail() +");");
	sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
	void sqlite3_close(FILE* db); //close pointer

}
/*void addstudent2(student newStud) {
	sqlite3* db;
	const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
	sqlite3_open(pathto, &db); //Create pointer
	string sql("INSERT INTO STUDENT(ID,NAME,SURNAME,GRADYEAR,MAJOR,EMAIL) VALUES( 13456,Thomas,,Smith, 2024,BSME,Smitht);");
	//string sql("INSERT INTO STUDENT (ID,NAME,SURNAME,GRADYEAR,MAJOR,EMAIL) VALUES(" + newStud.getID() +"," + newStud.getname() +", 2024,BSCO," + newStud.returnemail() +");");
	sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
	void sqlite3_close(FILE * db); //close pointer

}*/
 void deletedata(string delname) {
	sqlite3* db;
	const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
	sqlite3_open(pathto, &db); //Create pointer
	cout << "Opening File\n";
	string sql("DELETE FROM STUDENT WHERE ID = 10001;");
	sqlite3_exec(db, sql.c_str(), callback, NULL,0);
	cout << "Removing Student\n";
	void sqlite3_close(FILE* db); //close pointer

}
 void deletestudent(int idnum) {
	sqlite3* db;
	const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
	sqlite3_open(pathto, &db); //Create pointer
	cout << "Opening File";
	string sql("DELETE FROM STUDENT WHERE ID = '" + idnum + "';");
	sqlite3_exec(db, sql.c_str(), callback, NULL, 0);
	cout << "Removing Student \n";
	void sqlite3_close(FILE * db); //close pointer

}
/*void deleteteacher(string delname) {
	sqlite3* db;
	const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
	sqlite3_open(pathto, &db); //Create pointer
	cout << "Opening File";
	string sql("DELETE FROM INSTRUCTOR WHERE ID = '20004';");
	sqlite3_exec(db, sql.c_str(), callback, NULL, 0);
	cout << "Removing Instructor \n";
	void sqlite3_close(FILE * db); //close pointer

}*/
/*void querydata() {
	sqlite3* db;
	const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
	sqlite3_open(pathto, &db); //Create pointer
	string sql("SELECT FROM Courses Group BY Credits;");
	cout << sqlite3_exec(db, sql.c_str(), callback, NULL, 0) << "\n";

	void sqlite3_close(FILE * db); //close pointer

}*/
/*void editadmin() {
	sqlite3* db;
	const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
	sqlite3_open(pathto, &db); //Create pointer
	cout << "Opening File";
	string sql("UPDATE ADMIN SET TITLE = 'VICE-PRESIDENT' WHERE ID = 30002; ");
	sqlite3_exec(db, sql.c_str(), callback, NULL, 0);
	cout << "Title Changed  \n";
	void sqlite3_close(FILE * db); //close pointer

}*/
/*void giveteacher(string coursename, string dept) {
	sqlite3* db;
	const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
	sqlite3_open(pathto, &db); //Create pointer
	cout << "Opening File";
	string sql("UPDATE Courses WHERE TEACHER = NULL SELECT FROM TEACHER WHERE DEPT  ");
	sqlite3_exec(db, sql.c_str(), callback, NULL, 0);
	cout << "Removing Instructor \n";
	void sqlite3_close(FILE * db); //close pointer

}*/


 /*
 Remove first student from course roster add roster search by ID number with for loop
 Print course roster by printing list, use for loop to print if needed
 setup login by adding password cloumn to database and login function
 Search course by printing course list
 Search courses based on name, department,credits
 
 void testing(){
 




 }

 */

