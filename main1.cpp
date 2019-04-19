//
//  main.cpp
//
//  1340project
//
//  Created by So Yuk Sze and Wong Seung Yee on 19/4/2019.
//  Copyright © 2019 So Yuk Sze and Wong Seung Yee. All rights reserved.
//
//  staff management system


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


// structure of variables
struct company_struct{
    string name;
    int id;
    int age;
    string role;
    int salary;
    bool perfect_attendance;
    double monthly_target;
    int attendance_count = 0;
    int early_leave_count = 0;
};

// grow the size of the employee system
void grow_system(){
    
}

//LOAD (Load employee data from a text file into the array parameter)
// return the number of records loaded in the text file
int load(string raw_filename, company_struct * &sys, int & sys_size){
    ifstream raw_textfile;
    raw_textfile.open(raw_filename.c_str());
    if (raw_textfile.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }
    int i = 0;
    string line;
    while (getline(raw_textfile, line))
    {
        if (i >= sys_size)
            grow_system();
        
        // extract a record : name, id, age, role, salary
        if (i < sys_size) {
            istringstream iss(line);
            if (!getline(iss, sys[i].name,','))
                break;
            if (!getline(iss, sys[i].id,','))
            ++i;
        }
        
    }
    
    raw_textfile.close();
    return i;
}





// ADD
void add(){
    
}


// SHOW
void show(){
    
}

// FIND
void find(){
    
}

// SORT
void sort(){
    
}

// DELETE
void delete_record(){
    
}

// EXIT
void exit(){
    
}

int main(){
    string command, attribute; // attribute: the parameter that the user would like to search for
    int system_size = 5;
    company_struct * company_ptr = new company_struct[system_size];
    int number_records = 0;
    string raw_textfile;
    
    // output text file
    ofstream monthly_report;
    monthly_report.open("monthly_report.txt");
    
    // check if the file can be opened
    if (! monthly_report){
        cout << "Failed to open monthly_report.txt" << endl;
        exit(1);
    }
    
    // print content page and show all commands
    
    cout << "Welcome to the staff management system.  Here are the commands in this system." << endl;
    cout << "Please enter the commands according to the following format." << endl;
    cout << "\"LOAD\": Load a file that contains record of employees." << endl;
    cout << "\"ADD\": Add a new record of a new employee " << endl;
    cout << "\"SHOW\": Show all attribute by the employee by the name." << endl;
    cout << "\"FIND (ATTRIBUTE)\": Search for the employees according to that attribute." << endl;
    cout << "\"SORT (ATTRIBUTE)\": Sort the employess according to that attribute" << endl;
    cout << "\"DELETE (ATTRIBUTE)\": Delete a employee according to that attribute " << endl;
    cout << "\"EXIT\" : Exit the system." << endl;
    
    // read user input
    cin >> command;
    cin >> attribute; // attribute of employees
    
    
    while(command != "EXIT"){
        if (command == "LOAD"){
            cout << "Please enter the filename: " << endl;
            cin >> raw_textfile;
            number_records = load(raw_textfile, company_ptr, system_size);
            cout << number_records << " number of records loaded." << endl;
        }
        if (command == "ADD"){
            add();
        }
        if (command == "SHOW"){
            show();
        }
        if (command == "FIND"){
            find();
        }
        if (command == "SORT"){
            sort();
        }
        if (command == "DELETE"){
            delete_record();
        }

        if (command == "EXIT"){
            exit();
        }
    }
    
    
    // close file
    return 0;
}
