//
//  print_command_header.cpp
//  ENGG 1340 project
//  Staff Management System
//
//  Created by Wong Seung Yee and So Yuk Sze on 20/4/2019.
//  Copyright © 2019 Wong Seung Yee and So Yuk Sze. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "print_command_header.h"

using namespace std;

// print the command page of the employee system
string print_command(){
    // print content page and show all commands
    string command;
    cout << "Please enter the commands according to the following format." << endl;
    cout << "\"LOAD\": Load a file that contains record of employees." << endl;
    cout << "\"CLOCK\": Calulate the attendance of employees." << endl;
    cout << "\"CAL\": Calculate the sales revenue of employees." << endl;
    cout << "\"ADD\": Add a new record of a new employee " << endl;
    cout << "\"DELETE\": Fire an employee." << endl;
    cout << "\"EDIT\" : Edit the record of employee." << endl;
    cout << "\"SHOW\": Show all attributes by the employee by the name." << endl;
    cout << "\"SEARCH\": Search for the employees according to that attribute." << endl;
    cout << "\"SORT\": Sort the employess according to that attribute" << endl;
    cout << "\"CHECK\": Check the late, eary leave record and atttendance of employees." << endl;
    cout << "\"SAVE\": Save the current system into a new textfile. " << endl;
    cout << "\"OUTPUT\": Output the monthly report in current program" << endl;
    cout << "\"EXIT\" : Exit the system." << endl;

    // read user input
    cout << "Please Enter your command: ";
    cin >> command;
    return command;
}
