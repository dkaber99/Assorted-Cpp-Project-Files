#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream; //read
using std::ifstream; //write

int userin;
int available = 0;
int reserved = 0;
int availwindow = 0;
int availisle = 0;
int decision = 0;


int main() {

    char seating[24][6];


    ifstream readfile("seats.txt");

    //Importing seat chart
    for (int rows = 0; rows < 24; rows++) {
        for (int col = 0; col < 6; col++) {
            readfile >> seating[rows][col]; //Assigning each char in file to location in seating array
        }
    }
    readfile.close();
    for (int y = 0; y < 24; y++) {
        for (int x = 0; x < 6; x++) {
            if (seating[y][x] == 'A') {
                available++;
            }                               //Counting up each of the different types of available seats. It checks for each one at every seating location
            if ((seating[y][x] == 'A') && (x == 0 || x == 5)) {
                availwindow++;
            }
            if (seating[y][x] == 'A' && (x == 2 || x == 3)) {
                availisle++;
            }
        }
    }
    while (decision == 0) {

        //Shows stats for seats //Update single seat    //Shows plane chart
        std::cout << "Please choose an option:\n 0-Exit  \n 1-Check Seat Status  \n 2-Update Seat Status  \n 3-Show Seats  \n";
        std::cin >> userin;
        switch (userin) {

        case 0:
            decision = 1;
            std::cout << "Thanks for testing the Final Version of Dylan's Plane Seating Lab! \n"; //Goodbye message
            break;
        case 1:

            std::cout << "Available Seats: " << available << "\n";
            std::cout << "Available Window Seats: " << availwindow << "\n";
            std::cout << "Available Aisle Seats: " << availisle << "\n";

            break;

        case 2:
            int changerow;
            int changecol;
            char newstatus;
            cout << "Please enter the row of the seat you want to change: ";
            cin >> changerow;
            cout << "Please enter the col of the seat you want to change: ";
            cin >> changecol;
            cout << "Please enter the new status of the seat: ";
            cin >> newstatus;
            seating[changerow][changecol] = newstatus;
            break;
            available = 0;
            availwindow = 0;
            availisle = 0;                  //The program recounts the available seats every time it is asked. This is to prevent it from using an old count or starting off of old numbers
            for (int y = 0; y < 24; y++) {

                for (int x = 0; x < 6; x++) {
                    if (seating[y][x] == 'A') {
                        available++;
                    }
                    if ((seating[y][x] == 'A') && (x == 0 || x == 5)) {
                        availwindow++;
                    }
                    if (seating[y][x] == 'A' && (x == 2 || x == 3)) {
                        availisle++;
                    }
                }

            }
        case 3:
            std::cout << "Seating For Your Flight: \n";
            for (int y = 0; y < 24; y++) {
                cout << (y+1) << "  ";
                for (int x = 0; x < 6; x++) {
                    std::cout << seating[y][x] << " ";
                    if (x == 5) {
                        std::cout << "\n";
                    }
                }
            }

            break;
        default:
            cout << "Invalid option \n";
            break;
        }
    }
    ofstream outputFile("seats.txt");
    for (int rows = 0; rows < 24; rows++) {
        for (int col = 0; col < 6; col++) {
            outputFile << seating[rows][col];   //Writing the final seating chart to the seats file
            outputFile << "\t";
        }
        outputFile << "\n";
    }
    outputFile << endl;
}