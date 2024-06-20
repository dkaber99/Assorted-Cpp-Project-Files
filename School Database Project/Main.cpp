#include <iostream>
#include "User.h"
#include "Admin.h"
#include "Instructor.h"
#include "Student.h"
#include <sqlite3.h>

void studentsession(string name);
void instructorsession(); //Overhauled number input system into function system. Now user will be led into looping functions for their respective role.
void adminsession();
void addstudent();
void deletedata();
using std::string;
using std::cin;
using std::cout;
using namespace::std;
sqlite3* db;



/*static int callback(void* NotUsed, int argc, char** argv, char** azColName) { Attempting different versions of this function
	
	for (int i = 0; i < argc; i++) {
		cout << azColName[i] << ": " << argv[i] << endl;
	}
	cout << endl;
	return 0;
}*/

static int callback(void* data, int argc, char** argv, char** azColName)
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}


int main() {

	int active = 1;
	while (active != 0) {
		
		
		cout << "Welcome, Enter Your Username And Password Or 0 To Exit \n";
		
		string username = "";
		string password = "";
		cout << "Username: ";
		cin >> username;
		if (username == "exit") {
			active = 0;
			break;
		}
		cout << "Password: ";
		cin >> password;

		sqlite3* db;
		const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
		sqlite3_open(pathto, &db); //Create pointer
		
		string sql = "SELECT Password FROM STUDENT WHERE NAME = '" + username + "';";
		cout << "\n";
		const char* data("");
		
		
		//string sql = ("EXISTS FROM INSTRUCTOR WHERE ID = '" + username + "'; ");
		sqlite3_exec(db, sql.c_str(),NULL, NULL, NULL);
		
		//void sqlite3_close(FILE * db); //close pointer
		//sql = ("EXISTS FROM ADMIN WHERE ID = '" + username + "'; ");
		if (password.find(sqlite3_exec(db, sql.c_str(), callback, (void*)data, NULL)) == 0) {
			
			void sqlite3_close(FILE * db); //close pointer
			cout << "Logged into student\n";
			studentsession(username);
		}
			
		else if (sqlite3_exec(db, sql.c_str(), callback, NULL, NULL) == true) {
			cout << "Password incorrect or not student";
			cout << "Hello Instructor";
			instructorsession();
		}
		
		else if ((sqlite3_exec(db, sql.c_str(), callback, NULL, NULL)) == true) {
			cout << "Hello ADMIN";
			adminsession();
		}
		else{
			cout << "User Does Not Exist";
		}
		}
	return 0;
	}
		void studentsession(string name) {
			cout << "Hello student\nChoose a function\n1.Search courses\n2.Add Courses\n3.Drop Course\n4.Print Schedule\n 5.Logout";
			int stuin;
			cin >> stuin;
			switch (stuin) {

			case(1):

				break;
			case(2):

				break;

			case(3):

				break;
			case(4):

				break;
			case(5):
				cout << "Logging Out\n";
				break;

			}
			
		}
		void instructorsession() {
			cout << "Hello instructor\nChoose a function\n1.Print courses available\n2.Print Schedule\n";
			int inin;
			cin >> inin;
			switch (inin) {

			case(1):

				break;

			case(2): //Printing Roster
				//const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
				//sqlite3_open(pathto, &db); //Create pointer
				// int courseid;
				// cout << "Please enter a course roster to print
				// cin >> courseid
				//string sql("SELECT Roster FROM Courses WHERE CRN = '" + courseid + "';");				
				//sqlite3_exec(db, sql.c_str(), callback, NULL, 0);
				break;
			case(3):
				cout << "Logging Out";
				break;

			}
			if (inin == 3) {

			}
		}

		void adminsession() {
			cout << "Hello Admin\nChoose a function\n1.Add Course 2. Remove Course 3. Add User 4. Remove User 5. Print Roster 6.Print Courses\n";
			int adminin;
			cin >> adminin;
			switch (adminin) {

			case(1):

				break;
			case(2):

				break;
			case(3):

				break;
			case(4):

				break;
			case(5):

				break;
			case(6):

				break;
			}
		}
		void addstudent() {
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
		void deletedata() {
		   sqlite3* db;
		   const char* pathto = "C:\\Users\\kaberd\\OneDrive - Wentworth Institute of Technology\\Documents\\Junior Year Part 2\\Applied programming\\Lab3\\assignment3.db";
		   sqlite3_open(pathto, &db); //Create pointer
		   cout << "Opening File\n";
		   string sql("DELETE FROM STUDENT WHERE ID = 19023;");
		   sqlite3_exec(db, sql.c_str(), callback, NULL,0);
		   cout << "Removing Student\n";
		   void sqlite3_close(FILE* db); //close pointer

	   }
		void deletestudent(string idnum) {
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
	   */
	   /*void testing() {
		   deletestudent("1000");




	   }*/

	

