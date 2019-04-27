//
//  save.cpp
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
#include "save.h"

using namespace std;
// SAVE command
// save all records of the system into a new text file
// return 0 if an error occurs when opening the file
//sys: company ptr array
//n: num of records in the system
// return the number of records
int save_as(string filename, company_struct sys[], int n){
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }

    int i;
    for (i = 0; i < n; i++)
    {
      fout << sys[i].name << ", " << sys[i].id <<  ", "  << sys[i].age <<  ", "  << sys[i].role << ", "  << sys[i].salary <<endl;
    }

    fout.close();
    return i;
}
