//
//  grow_system.cpp
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
#include "grow_system.h"

using namespace std;


// grow the size of the employee system
// n: the size to be growed
//sys: is the company ptr array
// sys_size: number of size of system currently
void grow_system(company_struct * &sys, int &sys_size, int n){
    cout << "Success" << endl;
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
