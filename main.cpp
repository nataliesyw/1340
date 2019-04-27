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
#include "struct.h"
#include "print_command_header.cpp"
#include "grow_system.cpp"
#include "load.cpp"
#include "add.cpp"
#include "edit.cpp"
#include "show.cpp"
#include "search.cpp"
#include "sort.cpp"
#include "refresh.cpp"
#include "delete.cpp"
#include "save.cpp"
#include "check.cpp"
#include "clock.cpp"
#include "cal.cpp"
#include "output.cpp"
#include "initialize_attendance.cpp"

using namespace std;


int main(){
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
   string search_input;
   string check_attribute;
   int month;
   int working_days;
   int count;
   string edit_id;
   int target_revenue;
   
   cout << "***** Welcome to the staff management system.  Here are the commands in this system *****" << endl;

    cout << "Please enter the month to be recorded (1-12):  ";
    cin >> month;
    if (month == 1 || month == 7 || month == 8)
        working_days = 22;
    else if (month == 3|| month == 5 || month == 9 || month == 10 || month == 11){
        working_days = 21;
    }
    else if (month == 12){
        working_days = 20;
    }
    else if (month == 4 || month == 6){
        working_days = 19;
    }
    else if (month == 2){
        working_days = 17;
    }
    cout << "Working days:  " << working_days << endl;
    cout << "Please input the target revenue of an employee in this month:  ";
    cin >> target_revenue;
    cout << endl;
    
    while(command_choice != "EXIT"){

         if (command_choice == "LOAD"){
             cout << "Please enter the filename: ";
             cin >> raw_textfile;
             cout << endl;
             number_records = load(raw_textfile, company_ptr, system_size);
             initialize_attendance(working_days, company_ptr, system_size);
             ori_num = number_records + 1000;
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

           cout << endl;
           cout << "***ID could NOT be changed***" << endl;
           cout << "Input the ID of the employee: ";
           cin >> edit_id;
           cout << endl;
           
          edit(edit_id, company_ptr, number_records);
         }

         if (command_choice == "SHOW"){
             show(company_ptr, number_records);
         }

         if (command_choice == "SEARCH"){


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
             cout << "Revenue------(3)" << endl;
             cout << "Early-leave--(4)" << endl;
             cout << "Late---------(5)" << endl;
             cout << "Attendance---(6)" << endl;
             cout << "Please enter the attribute to sort on (1/2/3/4/5/6):  ";

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

           cout << "Check employees with perfect ATTENDANCE--------(1)" << endl;
           cout << "Check employees who have been LATE-------------(2)" << endl;
           cout << "Check employees who have LEFT EARLY------------(3)" << endl;
           cout << "Check employees who reach the monthly target---(4)" << endl;
           cout << "Please enter the attribute to be checked (1/2/3/4):  ";

           cin >> check_attribute;
           cout << endl;
           check(check_attribute, working_days, target_revenue, company_ptr, system_size, number_records);
         }

         if (command_choice == "OUTPUT"){
             cout << "Please enter the filename to output to: ";
             cin >> output_filename;
             output_record(output_filename, company_ptr, number_records, ori_num, working_days, target_revenue);
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
