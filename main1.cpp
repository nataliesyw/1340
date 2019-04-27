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
    string perfect_attendance_output; // for printing the output report file
    double monthly_revenue;
    int revenue = 0;
    int attendance_count = 0;
    int early_leave_count = 0;
    int late_count = 0;
};

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
    // cin >> attribute; // attribute of employees
    return command;
}
// grow the size of the employee system
// n: the size to be growed
//sys: is the company ptr array
// sys_size: number of size of system currently

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

    cout << "***Size of the employee management system has been enlarged to hold " << sys_size << " records.***" << endl;
}

//LOAD (Load employee data from a text file into the array parameter)
//return the number of records loaded in the text file
//sys: is the company ptr array
//sys_size: number of size of system currently
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
//sys: is the company ptr array
//current num record: number of records in the system currently
// return the number of records currently in the system
int add_record(company_struct sys[], int current_num_record){
    char ans;
    string line;
    // extract user input
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
    // confirm if user add this data
    cout << "Name:\t" << sys[current_num_record].name << endl;
    cout << "ID:\t" << sys[current_num_record].id << endl;
    cout << "Age:\t" << sys[current_num_record].age << endl;
    cout << "Role:\t" << sys[current_num_record].role << endl;
    cout << "Salary:\t" << sys[current_num_record].salary << endl;
    cout << endl;
    cout << "Add to the system (y/n)?:  ";
    cin >> ans;
    cout << endl;
    if (ans == 'y')
    {
        cout << "***1 record added.***" << endl;
        current_num_record++;
    }

    return current_num_record; // return the number of records currently in the system
}

// Edit command
//sys: is the company ptr array
//n: number of records in the system currently
void edit(string attribute, string id_to_edit, company_struct sys[], int n){

  string new_info;
  string line;
  cout << id_to_edit << endl;
  for (int i = 0; i < n; i++){
    string id_in_array = sys[i].id;
    transform(id_in_array.begin(), id_in_array.end(), id_in_array.begin(), ::toupper);
    transform(id_to_edit.begin(), id_to_edit.end(), id_to_edit.begin(), ::toupper);
    if(id_in_array.find(id_to_edit) != string::npos){

      if (attribute == "1"){
        cout << "Original name of employee " << id_to_edit << ":  " << sys[i].name << endl;
        getline(cin, line);
        cout << "New name:  ";
        getline(cin, new_info);
        sys[i].name = new_info;
        cout << sys[i].name << endl;
      }

      if (attribute == "2"){
        cout << "Original age of employee " << id_to_edit << ":  " << sys[i].age << endl;
        getline(cin, line);
        cout << "New age:  ";
        getline(cin, new_info);
        sys[i].age = new_info;
        cout << sys[i].age << endl;
      }

      if (attribute == "3"){
        cout << "Original role of employee " << id_to_edit << ":  " << sys[i].role << endl;
        getline(cin, line);
        cout << "New role:  ";
        getline(cin, new_info);
        sys[i].role = new_info;
        cout << sys[i].role << endl;
      }

      if (attribute == "4"){
        cout << "Original salary of employee " << id_to_edit << ":  " << sys[i].salary << endl;
        getline(cin, line);
        cout << "New salary:  ";
        getline(cin, new_info);
        sys[i].salary = new_info;
        cout << sys[i].salary << endl;
      }
      //name id age role salary
      cout << endl;
    }
  }

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
// n: number of records found
// detail: the string to be search
int search(string attribute, string detail, company_struct sys[], int n){
    int i, count = 0;
    //count: number of records matching the string found

      //search by name
      if (attribute == "1"){
          for (i = 0; i < n; i++){
            string name_in_array = sys[i].name;
            // turning the string and name in the array into upper case
            // make the string into not case-sensitive
            transform(name_in_array.begin(), name_in_array.end(), name_in_array.begin(), ::toupper);
            transform(detail.begin(), detail.end(), detail.begin(), ::toupper);
            if(name_in_array.find(detail) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              //increase one if it mathces the string
              count ++;
            }
          }
      }
      // search by id
      if (attribute == "2"){
          for (i = 0; i < n; i++){
            string id_in_array = sys[i].id;
            // turning the string and name in the array into upper case
            // make the string into not case-sensitive
            transform(id_in_array.begin(), id_in_array.end(), id_in_array.begin(), ::toupper);
            transform(detail.begin(), detail.end(), detail.begin(), ::toupper);
            if(id_in_array.find(detail) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              // increase one if it matches the string
              count ++;
            }
          }
      }

      // search by age
      if (attribute == "3"){
          for (i = 0; i < n; i++){
            string age_in_array = sys[i].age;
            // turning the string and name in the array into upper case
            // make the string into not case-sensitive
            transform(age_in_array.begin(), age_in_array.end(), age_in_array.begin(), ::toupper);
            transform(detail.begin(), detail.end(), detail.begin(), ::toupper);
            if(age_in_array.find(detail) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              // increase one if it matches the string
              count ++;
            }
          }
      }
      // search by role
      if (attribute == "4"){
          for (i = 0; i < n; i++){
            string role_in_array = sys[i].role;
            // turning the string and name in the array into upper case
            // make the string into not case-sensitive
            transform(role_in_array.begin(), role_in_array.end(), role_in_array.begin(), ::toupper);
            transform(detail.begin(), detail.end(), detail.begin(), ::toupper);
            if(role_in_array.find(detail) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              // increase one if it matches the string
              count ++;
            }
          }
      }
      // search by salary
      if (attribute == "5"){
          for (i = 0; i < n; i++){
            string salary_in_array = sys[i].salary;
            // turning the string and name in the array into upper case
            // make the string into not case-sensitive
            transform(salary_in_array.begin(), salary_in_array.end(), salary_in_array.begin(), ::toupper);
            transform(detail.begin(), detail.end(), detail.begin(), ::toupper);
            if(salary_in_array.find(detail) != string::npos){
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;
              // increase one if it matches the string
              count ++;
            }
          }
      }

    // return the number of records found
    return count;
}


// SORT command
// print out all records which are sorted
// selectively print out the records *******if we have time*******
// num: number of records in the system
// sys: the company array
// ori_num: the last id of the original input company text file
void sort_record(string attribute, string order, company_struct sys[], int num, int ori_num){
  int i, j ,idx;
  int min;
  int max;
  // selection sort

  // sort by ascending order
  if (order == "a"){

    // sort by age
    if (attribute == "1"){
      for (i = 0; i < num - 1; i++)
      {
          min = stoi(sys[i].age);
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (stoi(sys[j].age) < min)
              {
                  min = stoi(sys[j].age);
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by salary
    if (attribute == "2"){
      for (i = 0; i < num - 1; i++)
      {
          min = stoi(sys[i].salary);
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (stoi(sys[j].salary) < min)
              {
                  min = stoi(sys[j].salary);
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by times for being late
    if (attribute == "3"){
      for (i = 0; i < num - 1; i++)
      {
          min = sys[i].late_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].late_count < min)
              {
                  min = sys[j].late_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by times for left early
    if (attribute == "4"){
      for (i = 0; i < num - 1; i++)
      {
          min = sys[i].early_leave_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].early_leave_count < min)
              {
                  min = sys[j].early_leave_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    //sort by attdence
    if (attribute == "5"){
      for (i = 0; i < num - 1; i++)
      {
          min = sys[i].attendance_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].attendance_count < min)
              {
                  min = sys[j].attendance_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

  }

  // sort by descending order
  if (order == "d"){

    // sort by age
    if (attribute == "1"){
      for (i = 0; i < num - 1; i++)
      {
          max = stoi(sys[i].age);
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (stoi(sys[j].age) > max)
              {
                  max = stoi(sys[j].age);
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by salary
    if (attribute == "2"){
      for (i = 0; i < num - 1; i++)
      {
          max = stoi(sys[i].salary);
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (stoi(sys[j].salary) > max)
              {
                  max = stoi(sys[j].salary);
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by times for being late
    if (attribute == "3"){
      for (i = 0; i < num - 1; i++)
      {
          max = sys[i].late_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].late_count > max)
              {
                  max = sys[j].late_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by times for left early
    if (attribute == "4"){
      for (i = 0; i < num - 1; i++)
      {
          max = sys[i].early_leave_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].early_leave_count > max)
              {
                  max = sys[j].early_leave_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    //sort by attdence
    if (attribute == "5"){
      for (i = 0; i < num - 1; i++)
      {
          max = sys[i].attendance_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].attendance_count > max)
              {
                  max = sys[j].attendance_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

  }
  // newly added record: no late, attendance, early leave record
  if (attribute == "3" || attribute == "4" || attribute == "5"){
    for ( int k = 0; k < num; k++){
      // newly added record
      if (stoi(sys[k].id) > ori_num){
        cout << "***No such record for this employee***" << endl;
        cout << "Name:\t" << sys[k].name << endl;
        cout << "ID:\t" << sys[k].id << endl;
        cout << "Age:\t" << sys[k].age << endl;
        cout << "Role:\t" << sys[k].role << endl;
        cout << "Salary:\t" << sys[k].salary << endl;
        cout << endl;
      }

      else{
        cout << "Name:\t" << sys[k].name << endl;
        cout << "ID:\t" << sys[k].id << endl;
        cout << "Age:\t" << sys[k].age << endl;
        cout << "Role:\t" << sys[k].role << endl;
        cout << "Salary:\t" << sys[k].salary << endl;
        cout << endl;
      }
    }
  }

  else{
    for ( int k = 0; k < num; k++){

      cout << "Name:\t" << sys[k].name << endl;
      cout << "ID:\t" << sys[k].id << endl;
      cout << "Age:\t" << sys[k].age << endl;
      cout << "Role:\t" << sys[k].role << endl;
      cout << "Salary:\t" << sys[k].salary << endl;
      cout << endl;
    }
  }

}

// Refresh command
// To sort all the infomation according to their ID
//sys: company ptr array
//num : num of records in the system
void refresh(company_struct sys[], int num){

  int i, j ,idx;
  string min;

  for (i = 0; i < num - 1; i++){
    min = sys[i].id;
    idx = i;

    for (j = i + 1; j < num; j++){
      if (sys[j].id < min){
          min = sys[j].id;
          idx = j;
      }
    }

    if (idx != i){
      company_struct temp;
      // swap pb[i] & pb[idx]
      temp    = sys[i];
      sys[i]   = sys[idx];
      sys[idx] = temp;
    }
  }

}


// DELETE command
// delete a record of ONE employee in the company_ptr array
// id_to_search: id of employee to be deleted
// return the number of record (n-1)
//sys: company ptr array
//n : num of records in the system
int delete_record(string id_to_search, company_struct sys[], int n){
  char ans;
  for (int i = 0; i < n; i++){
    string id_in_array = sys[i].id;

    if(id_in_array.find(id_to_search) != string::npos){
      cout << "Name:\t" << sys[i].name << endl;
      cout << "ID:\t" << sys[i].id << endl;
      cout << "Age:\t" << sys[i].age << endl;
      cout << "Role:\t" << sys[i].role << endl;
      cout << "Salary:\t" << sys[i].salary << endl;
      cout << endl;

			cout << "Delete from system (y/n)? ";
      cin >> ans;
      if (ans == 'y')
      {
        // skip current record and copy all rest records to sys
        for (int j = i+1; j < n; j++){
          sys[j-1] = sys[j];
        }
      n--;
      cout << "***Number of records have been changed to " << n << ".***" << endl << endl;
			return n;
			break;
      }
    }
  }
		return n;
}

// SAVE command
// save all records of the system into a new text file
// return 0 if an error occurs when opening the file
//sys: company ptr array
//n: num of records in the system
// return the number of records
int save_as(string filename, company_struct sys[], int n){
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }

    int i;
    fout << setw(25)<< "Name"<< setw(7) << "ID" << setw(6) << "Age" << setw(13) << "Role" << setw(9) << "Salary" <<endl;
    for (i = 0; i < n; i++)
    {
      fout << setw(25) << sys[i].name << setw(7) << sys[i].id << setw(6) << sys[i].age << setw(13) << sys[i].role << setw(9) << sys[i].salary <<endl;
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
//sys: company ptr array
//n: num of records in the system
void check(string attribute, int days, company_struct sys[], int n){

  int num;

  if (attribute == "1"){
    int attendance_percent;
    int i;

    attendance_percent = (sys[i].attendance_count / days)*100;
    
    for (i = 0; i < n; i++){

      if (sys[i].attendance_count == days){
        num++;
        cout << setw(25) << sys[i].name << setw(7) << sys[i].id << setw(7) << attendance_percent << endl << endl;
      }
    }
    cout << "***There are total " << num << " employee(s) with perfect attendance.***" << endl << endl;

    char ans;
    cout << "Show the attendacne performace of rest of the employees (y/n)?  ";
    cin >> ans;
      if (ans = 'y'){
        for (int i = 0; i < n; i++){
          if (sys[i].attendance_count != days){
          cout << setw(25) << sys[i].name << setw(7) << sys[i].id << setw(7) << attendance_percent << endl << endl;
        }
      }
    }
  }  
    


  if (attribute == "2"){
    cout << setw(25) << "Name" << setw(7) << "ID" << setw(20) << "Late arrivals" << endl;
    for (int j = 0; j < n; j++){
      if (sys[j].late_count > 0){
        num++;
        cout << setw(25) << sys[j].name << setw(7) << sys[j].id << setw(20) << sys[j].late_count << endl << endl;
      }
    }
    cout << "***There are total " << num << " employee(s) being late in this month.***" << endl << endl;
  }

  if (attribute == "3"){
    cout << setw(25) << "Name" << setw(7) << "ID" << setw(20) << "Early Leave" << endl;
    for (int k = 0; k < n; k++){
      if (sys[k].early_leave_count > 0){
        num++;
        cout << setw(25) << sys[k].name << setw(7) << sys[k].id << setw(20) << sys[k].early_leave_count << endl << endl;
      }
    }
    cout << "***There are total " << num << " employee(s) leaving early in this month.***" << endl << endl;
  }

  if (attribute == "4"){
    int target;
    cout << "Please input the monthly target for an employee:  ";
    cin >> target;
    cout << endl;
    cout << setw(25) << "Name" << setw(7) << "ID" << setw(25) << "Sales performance" << endl;
    for (int q = 0; q < n; q++){
      if (sys[q].revenue >= target){
        num++;
        cout << setw(25) << sys[q].name << setw(7) << sys[q].id << setw(25) << sys[q].revenue << endl << endl;
      }
    }
    cout << "***There are total " << num << " employee(s) reached the target in this month.***" << endl << endl;
  }

}



// calculate the late record according to clock in and clock out time
// filename: the clock-in and clock-out raw text file filename
//sys: company ptr array
//n: num of records in the system
void clock(string filename, company_struct * &sys, int n){
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


      for (int i = 0; i < n; i++){
        if (stoi(id) == stoi(sys[i].id)){
          // absent
          if (new_start == 9999 && new_end == 9999){
            sys[i].attendance_count -= 1;
          }
          else{
            //late
            if (new_start > 900){
                sys[i].late_count += 1;
            }
            // early leave
            if (new_end < 1700){
                sys[i].early_leave_count += 1;
            }
          }
        }
      }
    }

    cout << endl;
    cout << "***Attendance, late and early leave of each employee has been calculated.***" << endl;
    cout << "***Enter \"CHECK\" command to see the result.***" << endl;
    cout << endl;
  }

void cal(string filename, company_struct * &sys, int n){

    ifstream fin;
    fin.open(filename.c_str());
    // check if the file can be opened
    if (fin.fail()){
        cout << "Error in file opening." << endl;
    }

    string line, id, revenue;
    int new_revenue;

    while(getline(fin,line)){
      istringstream iss(line);

      getline(iss, id, ',');
      getline(iss, revenue, ',');

      new_revenue = stoi(revenue);

      for (int i = 0; i < n; i++){
        if (stoi(id) == stoi(sys[i].id)){
          sys[i].revenue += new_revenue;
        }
      }
    }

    cout << "***The revenue of each employee in this month has been inputed***" << endl;
    cout << "***Enter \"CHECK\" command to see the result.***" << endl;
    cout << endl;
} 
  // OUTPUT command
  // output the monthly report of the company
  // print the name, id, age, role, salary, monthly_revenue, perfect attendance
  // filename: the filename of report to output to
  // n: number of records in the system
  // sys: the company array
  // ori_num: the last id of the original input company text file
void output_record(string filename, company_struct sys[], int n, int ori_num){
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail())
    {
        cout << "Error in file opening." << endl;
    }
    // calculate the perfect attendance
    for (int i = 0; i < ori_num; i++){
      if (sys[i].attendance_count == 20) {
        sys[i].perfect_attendance = true;
      }
      else{
        sys[i].perfect_attendance = false;
      }
    }
    //original record
    for (int i = 0; i < ori_num-1000; i++) {
      if (sys[i].perfect_attendance == true){
        sys[i].perfect_attendance_output = "True";
      }
      else{
        sys[i].perfect_attendance_output = "False";
      }
    }
    // newly added record
    for (int i = ori_num-1000; i < n; i++){
      sys[i].perfect_attendance_output = "No Records";
      sys[i].perfect_attendance_output = "No Records";
    }

    // printing format
    const int name_width = 25;
    const int id_width = 7;
    const int role_width = 13;
    const int age_width = 6;
    const int salary_width = 9;
    const int attendance_width = 15;
    const int perfect_width = 25;
    const int el_count_width = 20;
    const int l_count_width = 15;

    fout << setw(name_width)<< "Name"<< setw(id_width) << "ID" << setw(age_width) << "Age" << setw(role_width) << "Role" << setw(salary_width) << "Salary"<< setw(perfect_width)<< "Perfect Attendance"  << endl;
    for (int i = 0; i < n; i++){
      fout << setw(name_width) << sys[i].name << setw(id_width) << sys[i].id << setw(age_width) << sys[i].age << setw(role_width) << sys[i].role << setw(salary_width) << sys[i].salary << setw(perfect_width) << sys[i].perfect_attendance_output <<endl;
    }
    fout.close();
  }

int decide_month(char month){
    if (month == 'Jan' || month == 'Jul' || month == 'Aug'){
      return 22;
    }

    if (month == 'Mar' || month == 'May' || month == 'Sep' || month == 'Oct' || month == 'Nov'){
      return 21;
    }

    if (month == 'Dec'){
      return 20;
    }

    if (month == 'Apr' || month == 'Jun'){
      return 19;
    }

    if (month == 'Feb'){
      return 17;
    }
}

void initialize_attendance(int days, company_struct * &sys, int n){
  
  for (int i = 0; i < n; i++){
    sys[i].attendance_count += days;
  }
}

int main(){
     // attribute: the parameter that the user would like to search for
    int system_size = 5;
    company_struct * company_ptr = new company_struct[system_size];
    int number_records = 0;
    int ori_num;
    string raw_textfile;
    string revenue_file;
    string command_choice;
    string save_as_filename;
    string search_attribute;
    string edit_attribute;
    string sort_attribute;
    string sort_order;
    string clock_filename;
    string employee_id_delete;
    string output_filename;
    string current_month;
    int count;
    char month;
    int working_days;



    cout << "Welcome to the staff management system.  Here are the commands in this system." << endl;

    cout << "Please enter the month to be recorded (Jan/Feb/Mar/Apr/May/Jun/Jul/Aug/Sep/Oct/Nov/Dec):  ";
    cin >> month;
    working_days = decide_month(month);

    while(command_choice != "EXIT"){

        if (command_choice == "LOAD"){
            cout << "Please enter the filename: ";
            cin >> raw_textfile;
            cout << endl;
            number_records = load(raw_textfile, company_ptr, system_size);
            initialize_attendance(working_days, company_ptr, system_size);
            ori_num = number_records + 1000;
            cout << "***" << number_records << " number of records loaded.***" << endl;
            cout << endl;

        }

        if (command_choice == "ADD"){
            if (number_records >= system_size)
                grow_system(company_ptr, system_size, 1);
            if (number_records < system_size)
                number_records = add_record(company_ptr, number_records);
            cout << "***There are now " << number_records << " record(s) in the system.***" << endl << endl;
        }

        if (command_choice == "DELETE"){
          cout << "Please input employee's id to delete: ";
          cin >> employee_id_delete;
    	    number_records = delete_record(employee_id_delete, company_ptr, system_size);
         }

        if (command_choice == "EDIT"){

          string edit_id;

          cout << "***ID could NOT be changed***" << endl;
          cout << "Input the ID of the employee: ";

          cin >> edit_id;

          cout << "Name-----(1)" << endl;
          cout << "Age------(2)" << endl;
          cout << "Role-----(3)" << endl;
          cout << "Salary---(4)" << endl;
          cout << "Please enter the attribute to be edited (1/2/3):  ";

          cin >> edit_attribute;

          edit(edit_attribute, edit_id, company_ptr, number_records);
        }

        if (command_choice == "SHOW"){
            show(company_ptr, number_records);
        }

        if (command_choice == "SEARCH"){

            string search_input;

            cout << "Name-----(1)" << endl;
            cout << "ID-------(2)" << endl;
            cout << "Age------(3)" << endl;
            cout << "Role-----(4)" << endl;
            cout << "Salary---(5)" << endl;
            cout << "Please enter the attribute to search for employees (1/2/3/4/5):  ";


            cin >> search_attribute;

            if (search_attribute == "1"){
              cout << "Please enter employees name to search:  ";
              getline(cin >> ws, search_input);
            }

            if (search_attribute == "2"){
              cout << "Please enter employees id to search:  ";
              cin >> search_input;
            }

            if (search_attribute == "3"){
              cout << "Please enter employees age to search:  ";
              cin >> search_input;
            }

            if (search_attribute == "4"){
              cout << "Please enter employees role to search:  ";
              cin >> search_input;
            }

            if (search_attribute == "5"){
              cout << "Please enter employees salary to search:  ";
              cin >> search_input;
            }
            count = search(search_attribute, search_input, company_ptr, number_records);
            cout << endl << count << " record(s) found." << endl;
            cout << endl;
        }

        if (command_choice == "SORT"){

            cout << "Age----------(1)" << endl;
            cout << "Salary-------(2)" << endl;
            cout << "Early-leave--(3)" << endl;
            cout << "Late---------(4)" << endl;
            cout << "Attendance---(5)" << endl;
            cout << "Please enter the attribute to sort on (1/2/3/4/5):  ";

            cin >> sort_attribute;

            cout << "Sorting in ascending or descending order? (a/d): ";

            cin >> sort_order;

            sort_record(sort_attribute, sort_order, company_ptr, number_records, ori_num);

            refresh(company_ptr, number_records);

        }

        if (command_choice == "SAVE"){
            cout << "Please enter the filename to save as:  ";
            cin >> save_as_filename;
            count = save_as(save_as_filename, company_ptr, number_records);
            cout << count << " record(s) found." << endl;
            cout << "The system is saved into "<< save_as_filename<< endl;
            cout << endl;
        }

        if (command_choice == "CLOCK"){
          cout << "Please enter the clock.io filename: ";
          cin >> clock_filename;
          clock(clock_filename, company_ptr, system_size);
        }

        if (command_choice == "CAL"){
            cout << "Please enter the filename: ";
            cin >> revenue_file;
            cout << endl;
            cal(revenue_file, company_ptr, system_size);

        }

        if (command_choice == "CHECK"){
          string check_attribute;

          cout << "Check employees with perfect ATTENDANCE--------(1)" << endl;
          cout << "Check employees who have been LATE-------------(2)" << endl;
          cout << "Check employees who have LEFT EARLY------------(3)" << endl;
          cout << "Check employees who reach the monthly target---(4)" << endl;
          cout << "Please enter the attribute to be checked (1/2/3/4):  ";

          cin >> check_attribute;
          cout << endl;
          check(check_attribute, working_days, company_ptr, system_size);
        }
        if (command_choice == "OUTPUT"){
            cout << "Please enter the filename to output to: ";
            cin >> output_filename;
            output_record(output_filename, company_ptr, number_records, ori_num);
            cout << "The system is saved into "<< output_filename<< endl;
            cout << endl;
        }

        command_choice = print_command();
      }

    cout << "Exit the system."<< endl;
    // delete the dynamic memeory array
    delete [] company_ptr;
    // close file
    return 0;
}
