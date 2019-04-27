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
