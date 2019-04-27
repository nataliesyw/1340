//
//  check.cpp
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
#include "check.h"

using namespace std;

// CHECK command
// multiple options
// perfect attendence: show the employees who have perfect attendance
// all attendance: show the percentage of attendance of each employee
// early leave
// late
//sys: company ptr array
//n: num of records in the system
void check(string attribute, int days, int target, company_struct sys[], int n, int num_records){

  int num;
  int sal_ded = 0; //number of employees who had absent for 3 days or above (salary_deducted)


  if (attribute == "1"){
    cout << "Working days: " << days << endl;
    int i;
    cout << setw(25) << "Name" << setw(7) << "ID" << endl;
    for (i = 0; i < n; i++){

      if (sys[i].attendance_count == days){
        num++;
        cout << setw(25) << sys[i].name << setw(7) << sys[i].id << setw(7) << endl << endl;
      }
    }

    if (num == num_records){
      cout << "***All employees had perfect attendance performance in this month.***" << endl;
    }
    else {
      char ans_show;
      cout << "***There are total " << num << " employee(s) with perfect attendance.***" << endl << endl;
      cout << "Show the attendacne performace of rest of the employees (y/n)?  ";
      cin >> ans_show;
      cout << endl;
        if (ans_show == 'y'){
        cout << setw(25) << "Name" << setw(7) << "ID" << setw(20) << "Absence days" << endl;
          for (int i = 0; i < n; i++){
            if (sys[i].attendance_count != days){
              int abs_days = days - sys[i].attendance_count;
              if (abs_days >= 3){
                sal_ded++;
              }
              cout << setw(25) << sys[i].name << setw(7) << sys[i].id << setw(15) << abs_days << endl << endl;
          }
        }
      }
      if (sal_ded > 0){     // there is employee who has to be punished
        char abs_ded;
        cout << "***Employee who had absent for 3 days or above would be punished by deducting salary with $500.***" << endl;
        cout << "Processing deduction (y/n)?  ";
        cin >> abs_ded;
        if (abs_ded == 'y'){
          for (int i = 0; i < n; i++){
            if (sys[i].attendance_count != days){
              int abs_days = days - sys[i].attendance_count;
              if (abs_days >= 3){
                int temp;
                temp = stoi(sys[i].salary) - 500;
                sys[i].salary = to_string(temp);
              }
            }
          }
          cout << "***The salary of required employee(s) has been deducted.***" << endl << endl;
        }

      }
    }
  } 
    


  else if (attribute == "2"){
    cout << "Working days: " << days << endl;
    cout << setw(25) << "Name" << setw(7) << "ID" << setw(20) << "Late arrivals" << endl;
    for (int j = 0; j < n; j++){
      if (sys[j].late_count > 0){
        num++;
        cout << setw(25) << sys[j].name << setw(7) << sys[j].id << setw(20) << sys[j].late_count << endl << endl;
      }
    }
    cout << "***There are total " << num << " employee(s) being late in this month.***" << endl << endl;
  }

  else if (attribute == "3"){
    cout << "Working days: " << days << endl;
    cout << setw(25) << "Name" << setw(7) << "ID" << setw(20) << "Early Leave" << endl;
    for (int k = 0; k < n; k++){
      if (sys[k].early_leave_count > 0){
        num++;
        cout << setw(25) << sys[k].name << setw(7) << sys[k].id << setw(20) << sys[k].early_leave_count << endl << endl;
      }
    }
    cout << "***There are total " << num << " employee(s) leaving early in this month.***" << endl << endl;
  }

  else if (attribute == "4"){
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
