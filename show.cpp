//
//  show.cpp
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
#include "show.h"

using namespace std;
// SHOW command
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
