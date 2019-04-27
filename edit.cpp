//
//  edit.cpp
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
#include "struct.h"
#include "edit.h"

using namespace std;
// Edit command
//sys: is the company ptr array
//n: number of records in the system currently
void edit(string id_to_edit, company_struct sys[], int n){
  
  string attribute;
  string new_info;
  string line;
  char ans;

  if (stoi(id_to_edit) > 1000 + n || stoi(id_to_edit) < 1000 + n){
    cout << "***Worng ID inputed***" << endl;
  }
  for (int i = 0; i < n; i++){
    string id_in_array = sys[i].id;
    transform(id_in_array.begin(), id_in_array.end(), id_in_array.begin(), ::toupper);
    transform(id_to_edit.begin(), id_to_edit.end(), id_to_edit.begin(), ::toupper);
    if(id_in_array.find(id_to_edit) != string::npos){

      cout << "The original information of employee (ID: " << sys[i].id << "):" << endl;
      cout << "Name:\t" << sys[i].name << endl;
      cout << "ID:\t" << sys[i].id << endl;
      cout << "Age:\t" << sys[i].age << endl;
      cout << "Role:\t" << sys[i].role << endl;
      cout << "Salary:\t" << sys[i].salary << endl;
      cout << endl;

      cout << "Name-----(1)" << endl;
      cout << "Age------(2)" << endl;
      cout << "Role-----(3)" << endl;
      cout << "Salary---(4)" << endl;
      cout << "Please enter the attribute to be edited (1/2/3/4):  ";

      cin >> attribute;

      if (attribute == "1"){
        cout << "Original name of employee (ID: " << id_to_edit << "):  " << sys[i].name << endl;
        getline(cin, line);
        cout << "New name:  ";
        getline(cin, new_info);
        cout << "Are you sure to change name of employee (ID: " << sys[i].id << ")" << " from " << sys[i].name << " to " << new_info << "(y/n) ?";
        cin >> ans;
        if (ans == 'y'){
          sys[i].name = new_info;
          cout << "***The name of employee (ID: " << sys[i].id << ") has been edited.***" << endl;
        }
      }


      if (attribute == "2"){
        cout << "Original age of employee " << id_to_edit << ":  " << sys[i].age << endl;
        getline(cin, line);
        cout << "New age:  ";
        getline(cin, new_info);
        cout << "Are you sure to change age of employee (ID: " << sys[i].id << ")" << " from " << sys[i].age << " to " << new_info << "(y/n) ?";
        cin >> ans;
        if (ans == 'y'){
          sys[i].age = new_info;
          cout << "***The age of employee (ID: " << sys[i].id << ") has been edited.***" << endl;
        }
      }

      if (attribute == "3"){
        cout << "Original role of employee " << id_to_edit << ":  " << sys[i].role << endl;
        getline(cin, line);
        cout << "New role:  ";
        getline(cin, new_info);
        cout << "Are you sure to change role of employee (ID: " << sys[i].id << ")" << " from " << sys[i].role << " to " << new_info << "(y/n) ?";
        cin >> ans;
        if (ans == 'y'){
          sys[i].role = new_info;
          cout << "***The role of employee (ID: " << sys[i].id << ") has been edited.***" << endl;
        }
      }

      if (attribute == "4"){
        cout << "Original salary of employee " << id_to_edit << ":  " << sys[i].salary << endl;
        getline(cin, line);
        cout << "New salary:  ";
        getline(cin, new_info);
        cout << "Are you sure to change salary of employee (ID: " << sys[i].id << ")" << " from " << sys[i].salary << " to " << new_info << "(y/n) ?";
        cin >> ans;
        if (ans == 'y'){
          sys[i].salary = new_info;
          cout << "***The salary of employee (ID: " << sys[i].id << ") has been edited.***" << endl;
        }
      }
      cout << endl;
    }
  }

}
