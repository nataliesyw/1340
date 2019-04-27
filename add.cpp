//
//  add.cpp
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
#include "add.h"

using namespace std;
// ADD command
//sys: is the company ptr array
//current num record: number of records in the system currently
// return the number of records currently in the system
int add_record(company_struct sys[], int current_num_record){
    char ans;
    string line;
    // extract user input
    getline(cin, line);
    cout << "Please enter the employee name: " << endl;
    getline(cin, sys[current_num_record].name);
    cout << "Please enter the employee ID: " << endl;
    getline(cin, sys[current_num_record].id);
    cout << "Please enter the employee age: " << endl;
    getline(cin, sys[current_num_record].age);
    cout << "Please enter the employee role: " << endl;
    getline(cin, sys[current_num_record].role);
    cout << "Please enter the employee salary: " << endl;
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
