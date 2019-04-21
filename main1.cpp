//
//  reverse_string.cpp
//  Module7_rev
//
//  Created by Natalie on 15/4/2019.
//  Copyright © 2019 Natalie. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;


// structure of variables
struct company_struct{
    string name;
    string id;
    string age;
    string role;
    string salary;
    bool perfect_attendance;
    double monthly_target;
    int attendance_count = 0;
    int early_leave_count = 0;
    int late_count = 0;
};

// print the command page of the employee system
string print_command(){
    // print content page and show all commands
    string command;
    cout << "Welcome to the staff management system.  Here are the commands in this system." << endl;
    cout << "Please enter the commands according to the following format." << endl;
    cout << "\"LOAD\": Load a file that contains record of employees." << endl;
    cout << "\"ADD\": Add a new record of a new employee " << endl;
    cout << "\"SHOW\": Show all attribute by the employee by the name." << endl;
    cout << "\"FIND\": Search for the employees according to that attribute." << endl;
    cout << "\"SORT\": Sort the employess according to that attribute" << endl;
    cout << "\"DELETE\": Delete a record of ONE employee" << endl;
    cout << "\"OUTPUT\": Output the monthly report" << endl;
    cout << "\"EXIT\" : Exit the system." << endl;

    // read user input
    cout << "Please Enter your command: ";
    cin >> command;
    // cin >> attribute; // attribute of employees
    return command;
}
// grow the size of the employee system
// n is the size to be growed
void grow_system(company_struct * &sys, int &sys_size, int n){

    // create a new dynamic array with a new size = max_size + n
    company_struct * sys_new = new company_struct[sys_size + n];

    // copy all the records from the original array to the new dynamic array
    for (int i = 0; i < sys_size; i++){
        sys_new[i] = sys[i];
    }

    // destroy the old dynamic array to free up the memory allocated to it
    delete [] sys;
    // assign the pointer to the new dynamic array to the pointer variable
    sys = sys_new;
    // update the size of the array
    sys_size += n;

    cout << "Size of the employee management system has been enlarged to hold " << sys_size << " records." << endl;
}

//LOAD (Load employee data from a text file into the array parameter)
// return the number of records loaded in the text file
int load(string raw_filename, company_struct * &sys, int & sys_size){

    ifstream raw_textfile;
    raw_textfile.open(raw_filename.c_str());
    // check if the file can be opened
    if (raw_textfile.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }

    int i = 0;
    string line;
    while (getline(raw_textfile, line)){

        if (i >= sys_size)
            grow_system(sys, sys_size, 1); // to be confirm: the number that array will grow !!!! ***********

        // extract ONE employee record : name, id, age, role, salary
        if (i < sys_size) {
            istringstream iss(line);
            if (!getline(iss, sys[i].name,','))
                break;
            if (!getline(iss, sys[i].id,','))
                break;
            if (!getline(iss, sys[i].age,','))
                break;
            if (!getline(iss, sys[i].role,','))
                break;
            if (!getline(iss, sys[i].salary))
                break;
            ++i;
        }
    }

    raw_textfile.close();
    return i; // return the number of records in the text file
}


// ADD command
int add_record(company_struct sys[], int current_num_record){
    char ans;
    string line;
    getline(cin, line);
    cout << "Please enter the employee name" << endl;
    getline(cin, sys[current_num_record].name);
    cout << "Please enter the employee ID" << endl;
    getline(cin, sys[current_num_record].id);
    cout << "Please enter the employee age" << endl;
    getline(cin, sys[current_num_record].age);
    cout << "Please enter the employee role" << endl;
    getline(cin, sys[current_num_record].role);
    cout << "Please enter the employee salary" << endl;
    getline(cin, sys[current_num_record].salary);

    cout << endl;
    cout << "Name:\t" << sys[current_num_record].name << endl;
    cout << "ID:\t" << sys[current_num_record].id << endl;
    cout << "Age:\t" << sys[current_num_record].age << endl;
    cout << "Role:\t" << sys[current_num_record].role << endl;
    cout << "Salary:\t" << sys[current_num_record].salary << endl;
    cout << endl;
    cout << "Add to the system (y/n)? ";
    cin >> ans;
    if (ans == 'y')
    {
        cout << "1 record added." << endl;
        current_num_record++;
    }

    return current_num_record;
}


// SHOW command
// print out all records of the current system
// current_num_record: number of records current stored in the system
void show(company_struct sys[], int current_num_record){
    int i;

    for (int i = 0; i < current_num_record; i++){
      cout << "Name:\t" << sys[i].name << endl;
      cout << "ID:\t" << sys[i].id << endl;
      cout << "Age:\t" << sys[i].age << endl;
      cout << "Role:\t" << sys[i].role << endl;
      cout << "Salary:\t" << sys[i].salary << endl;
      cout << endl;
    }
}


//FIND command
// return the number of records found
void search(){

}


// SORT command
void sort(){

}


// DELETE command
// delete a record of ONE employee
void delete_record(){

}

// OUTPUT command
// output the monthly report that includes attendance, early leave, monthly target and late record
void output(){

}

// SAVE command
// save all records system into a new text file
// return 0 if an error occurs when opening the file
int save_as(string filename, company_struct sys[], int n){
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }

    int i;
    fout << "Name"<< setw(25) << "ID" << setw(5) << "Age" << setw(3) << "Role" << setw(10) << "Salary" << setw(7) <<endl;
    for (i = 0; i < n; i++)
    {
      fout << sys[i].name << " " << sys[i].id << " " << sys[i].age << " " << sys[i].role << " " << sys[i].salary << endl;
    }

    fout.close();
    return i;

}

// calculate the late record according to clock in and clock out time

int main(){
     // attribute: the parameter that the user would like to search for
    int system_size = 5;
    company_struct * company_ptr = new company_struct[system_size];
    int number_records = 0;
    string raw_textfile;
    string command_choice;
    string save_as_filename;
    int count;

    // output text file
//    ofstream monthly_report;
//    monthly_report.open("monthly_report.txt");

    // check if the file can be opened
//    if (! monthly_report){
//        cout << "Failed to open monthly_report.txt" << endl;
//        exit(1);
//    }


    while(command_choice != "EXIT"){

        if (command_choice == "LOAD"){
            cout << "Please enter the filename: ";
            cin >> raw_textfile;
            cout << endl;
            number_records = load(raw_textfile, company_ptr, system_size);
            cout << number_records << " number of records loaded." << endl;
        }

        if (command_choice == "ADD"){
            if (number_records >= system_size)
                grow_system(company_ptr, system_size, 1);
            if (number_records < system_size)
                number_records = add_record(company_ptr, number_records);
            cout << "There are now " << number_records << " record(s) in the system." << endl << endl;
        }
        if (command_choice == "SHOW"){
            show(company_ptr, number_records);
        }
        if (command_choice == "SAVE"){
            cout << "Please enter the filename to save as:  ";
            cin >> save_as_filename;
            count = save_as(save_as_filename, company_ptr, number_records);
            cout << count << " record(s) found." << endl;
            cout << "The system is saved into "<< save_as_filename<< endl;
            cout << endl;
        }
        if (command_choice == "SEARCH"){
          cout << "Please enter the attribute to search for employees:  ";
          cin << search_attribute;

        }
        command_choice = print_command();
  //      if (command_choice == "FIND"){
    //        find();
//        }
  //      if (command_choice == "SORT"){
    //        sort();
      //  }
        // if (command_choice == "DELETE"){
//          delete_record();
  //      }
    //    if (command_choice == "OUTPUT"){
      //      output();
        // }
    }


    cout << "Exit the system."<< endl;
    // delete the dynamic memeory array
    delete [] company_ptr;
    // close file
    return 0;
}
