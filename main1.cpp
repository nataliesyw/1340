//
//  main.cpp
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

using namespace std;


// structure of variables
struct company_struct{
    string name;
    string id;
    string age;
    string role;
    string salary;
    bool perfect_attendance;
    double monthly_revenue;
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
    cout << "\"CAL\": Calulate the the attdence of employees." << endl;
    cout << "\"ADD\": Add a new record of a new employee " << endl;
    cout << "\"DELETE\": Fire an employee." << endl;
    cout << "\"SHOW\": Show all attribute by the employee by the name." << endl;
    cout << "\"SEARCH\": Search for the employees according to that attribute." << endl;
    cout << "\"SORT\": Sort the employess according to that attribute" << endl;
    cout << "\"CHECK\": Check the late, eary leave record and atttendance of employees." << endl;
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
            grow_system(sys, sys_size, 1);

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


//SEARCH command
// return the number of records found
// attribute: the parameter that the user input to search for
// n: numbr of records found
int search(string attribute, company_struct sys[], int n){
    int i, count = 0;

      if (attribute == "Name"){
          cout << "Please enter employees name to search:  ";
          string name_to_search;
          cin >> name_to_search;
          for (i = 0; i < n; i++){
            string name_in_array = sys[i].name;
            transform(name_in_array.begin(), name_in_array.end(), name_in_array.begin(), ::toupper);
            transform(name_to_search.begin(), name_to_search.end(), name_to_search.begin(), ::toupper);
            if(name_in_array.find(name_to_search) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              count ++;
            }
          }
      }

      if (attribute == "ID"){
          cout << "Please enter employees id to search:  ";
          string id_to_search;
          cin >> id_to_search;
          for (i = 0; i < n; i++){
            string id_in_array = sys[i].id;
            transform(id_in_array.begin(), id_in_array.end(), id_in_array.begin(), ::toupper);
            transform(id_to_search.begin(), id_to_search.end(), id_to_search.begin(), ::toupper);
            if(id_in_array.find(id_to_search) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              count ++;
            }
          }
      }

      if (attribute == "Age"){
          cout << "Please enter employees age to search:  ";
          string age_to_search;
          cin >> age_to_search;
          for (i = 0; i < n; i++){
            string age_in_array = sys[i].age;
            transform(age_in_array.begin(), age_in_array.end(), age_in_array.begin(), ::toupper);
            transform(age_to_search.begin(), age_to_search.end(), age_to_search.begin(), ::toupper);
            if(age_in_array.find(age_to_search) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              count ++;
            }
          }
      }

      if (attribute == "Role"){
          cout << "Please enter employees role to search:  ";
          string role_to_search;
          cin >> role_to_search;
          for (i = 0; i < n; i++){
            string role_in_array = sys[i].role;
            transform(role_in_array.begin(), role_in_array.end(), role_in_array.begin(), ::toupper);
            transform(role_to_search.begin(), role_to_search.end(), role_to_search.begin(), ::toupper);
            if(role_in_array.find(role_to_search) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              count ++;
            }
          }
      }
      if (attribute == "Salary"){
          cout << "Please enter employees salary to search:  ";
          string salary_to_search;
          cin >> salary_to_search;
          for (i = 0; i < n; i++){
            string salary_in_array = sys[i].salary;
            transform(salary_in_array.begin(), salary_in_array.end(), salary_in_array.begin(), ::toupper);
            transform(salary_to_search.begin(), salary_to_search.end(), salary_to_search.begin(), ::toupper);
            if(salary_in_array.find(salary_to_search) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              count ++;
            }
          }
      }

    return count;
}


// SORT command
// print out all records which are sorted
// selectively print out the records *******if we have time*******
void sort(company_struct sys[], int current_num_record){
    cout << "Sort accroding to:" << endl;
    cout << "Age" << endl;
    cout << "Salary" << endl;
    cout << "Early-leave" << endl;
    cout << "Late" << endl;
    cout << "Attendence" << endl;

    string attribute;
    cin >> attribute;

    cout << "Would you like to ";



}


// DELETE command
// delete a record of ONE employee in the company_ptr array
// id_to_search: id of employee to be deleted
// return the number of record (n-1)
int delete_record(string id_to_search, company_struct sys[], int n){
    char ans;

    for (int i = 0; i < n; i++){
      string id_in_array = sys[i].id;

      if (id_in_array.find(id_to_search) != string::npos){
          cout << "Name:\t" << sys[i].name << endl;
          cout << "ID:\t" << sys[i].id << endl;
          cout << "Age:\t" << sys[i].age << endl;
          cout << "Salary:\t" << sys[i].salary << endl;
          cout << endl;
          cout << "Delete from the system (y/n)? ";
          cin >> ans;

          if (ans == 'y'){
            // skip current record and copy all rest records to sys
            for (int j = i+1; j < n; j++){
              sys[j-1] = sys[j];
            }
            n--;
            cout << "Number of records in the management system has been changed to " << n << "."<< endl;
            cout << "Enter the command SHOW to show all existing records in the system."<< endl;
            cout << endl;
            return n;
            break;
          }
      }
    }
    return n;
}

// OUTPUT command
// output the monthly report that includes attendance, early leave, monthly target and late record
// save all records of the system into a new text file
// return 0 if an error occurs when opening the file
int output(string filename, company_struct sys[], int n){
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

// CHECK command
// multiple options
// perfect attendence: show the employees who have perfect attendance
// all attendance: show the percentage of attendance of each employee
// early leave
// late

void check(){

 }


// not yet refined!!!
// calculate the late record according to clock in and clock out time
// filename: the clock-in and clock-out raw text file filename
// n: system_size
void cal(string filename, company_struct * &sys, int n){
    ifstream fin;
    fin.open(filename.c_str());
    // check if the file can be opened
    if (fin.fail()){
        cout << "Error in file opening." << endl;
    }
    string line, id, start_time, end_time;
    while(getline(fin,line)){
      istringstream iss(line);

      getline(iss, id, ',');
      getline(iss, start_time, ',');
      getline(iss, end_time, ',');

      int new_start, new_end;
      new_start = stoi(start_time);
      new_end = stoi(end_time);
      cout << "ID:" << stoi(id) << endl;
      cout << "id in sys:" << stoi(sys[0].id)<< endl;
      cout << "start_time: " << new_start << endl;
      cout << "end_time: " << new_end << endl;
        // int diff_hrs = new_int2 / 100 - new_int1 / 100;
        // int diff_minutes = new_int2 % 100 - new_int1 % 100;
        // cout << "diff_hrs: " << diff_hrs << endl;
        // cout << "diff_minutes: " << diff_minutes << endl;
      for (int i = 0; i <= n; i++){
        if (stoi(id) == stoi(sys[i].id)){
          if (new_start == 9999 && new_end == 9999){
            sys[i].attendance_count -= 1;
            cout << "attendace_count +=1" << endl;
          }
          else{
            if (new_start > 900){
                sys[i].late_count += 1;
                cout << "late_count +=1" << endl;
            }
            if (new_end < 1700){
              sys[i].early_leave_count += 1;
              cout << "early_leave_count +=1" << endl;
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++){
      cout << "attendance_count:" << sys[i].attendance_count << endl;
      cout << "late_count:" << sys[i].late_count << endl;
      cout << "early_leave_count:" << sys[i].early_leave_count << endl;
    }
  }



int main(){
     // attribute: the parameter that the user would like to search for
    int system_size = 5;
    company_struct * company_ptr = new company_struct[system_size];
    int number_records = 0;
    string raw_textfile;
    string command_choice;
    string save_as_filename;
    string search_attribute;
    string clock_filename;
    string employee_id_delete;
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

        if (command_choice == "DELETE"){
          cout << "Please input employee's id to delete: ";
          cin >> employee_id_delete;
    	    number_records = delete_record(employee_id_delete, company_ptr, system_size);
         }

        if (command_choice == "SHOW"){
            show(company_ptr, number_records);
        }

        if (command_choice == "SEARCH"){
            cout << "Please enter the attribute to search for employees:  "<< endl;
            cout << "(Name/ Age/ ID/ Role/ Salary) ";
            cin >> search_attribute;
            count = search(search_attribute, company_ptr, number_records);
            cout << endl << count << " record(s) found." << endl;
            cout << endl;
        }

        // if (command_choice == "SORT"){
        //    sort();
        // }
        if (command_choice == "OUTPUT"){
            cout << "Please enter the filename to save as:  ";
            cin >> save_as_filename;
            count = output(save_as_filename, company_ptr, number_records);
            cout << count << " record(s) found." << endl;
            cout << "The system is saved into "<< save_as_filename<< endl;
            cout << endl;
        }

        if (command_choice == "CAL"){
          cout << "Please enter the clock.io filename: ";
          cin >> clock_filename;
          cal(clock_filename, company_ptr, system_size);
        }

        command_choice = print_command();
      }






    cout << "Exit the system."<< endl;
    // delete the dynamic memeory array
    delete [] company_ptr;
    // close file
    return 0;
}
