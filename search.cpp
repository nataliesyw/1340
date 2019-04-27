//
//  search.cpp
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
#include "search.h"

using namespace std;
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
