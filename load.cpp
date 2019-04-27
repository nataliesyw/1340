//
//  load.cpp
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
#include "load.h"

using namespace std;

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
    cout << "***Size of the employee management system has been enlarged to hold " << sys_size << " records.***" << endl;
    raw_textfile.close();
    return i; // return the number of records in the text file
}
