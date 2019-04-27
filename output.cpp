//
//  output.cpp
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
#include "output.h"

using namespace std;
// OUTPUT command
  // output the monthly report of the company
  // print the name, id, age, role, salary, monthly_revenue, perfect attendance
  // filename: the filename of report to output to
  // n: number of records in the system
  // sys: the company array
  // ori_num: the last id of the original input company text file
void output_record(string filename, company_struct sys[], int n, int ori_num, int days, int target){
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail())
    {
        cout << "Error in file opening." << endl;
    }
    // calculate the perfect attendance
    for (int i = 0; i < n; i++){
      if (sys[i].attendance_count == days) {
        sys[i].perfect_attendance = true;
      }
      else{
        sys[i].perfect_attendance = false;
      }
    }
    //original record
    for (int i = 0; i < n; i++) {
      if (sys[i].perfect_attendance == true){
        sys[i].perfect_attendance_output = "True";
      }
      else{
        sys[i].perfect_attendance_output = "False";
      }
    }

    // printing format
    const int name_width = 25;
    const int id_width = 7;
    const int role_width = 13;
    const int age_width = 6;
    const int revenue_width = 12;
    const int salary_width = 9;
    const int attendance_width = 15;
    const int perfect_width = 25;
    const int el_count_width = 20;
    const int l_count_width = 15;

    int reach_target = 0;  // number of employees who DID NOT reach the monthly target
    int temp;
    if (target == 0){
      cout << "Please input the monthly target:  ";
      cin >> temp;
      target = temp;
    }
    fout << setw(name_width)<< "Name"<< setw(id_width) << "ID" << setw(age_width) << "Age" << setw(role_width) << "Role" << setw(revenue_width) << "Revenue" << setw(salary_width) << "Salary"<< setw(l_count_width) << "Late arrvivals" << setw(el_count_width) << "Early leave" << setw(perfect_width) << "Perfect Attendance"  << endl;
    for (int i = 0; i < n; i++){
      if (sys[i].revenue < target){
        fout << "*" << setw(name_width) << sys[i].name << setw(id_width) << sys[i].id << setw(age_width) << sys[i].age << setw(role_width) << sys[i].role << setw(revenue_width) << sys[i].revenue << setw(salary_width) << sys[i].salary  << setw(l_count_width) << sys[i].late_count << setw(el_count_width) << sys[i].early_leave_count<< setw(perfect_width) << sys[i].perfect_attendance_output << endl;
        reach_target++;
      }
      else{
        fout << setw(name_width) << sys[i].name << setw(id_width) << sys[i].id << setw(age_width) << sys[i].age << setw(role_width) << sys[i].role << setw(revenue_width) << sys[i].revenue << setw(salary_width) << sys[i].salary  << setw(l_count_width) << sys[i].late_count << setw(el_count_width) << sys[i].early_leave_count<< setw(perfect_width) << sys[i].perfect_attendance_output << endl;
      }
    }
    if (reach_target == 0){
      fout << endl;
      fout << "All employees reach the monthly target---" << target << "." << endl;
    }
    else{
      fout << endl;
      fout << "Employees with * before their name did not reach the monthly target---" << target << "." << endl;
    }
    fout.close();
}
