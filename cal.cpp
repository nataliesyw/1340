//
//  cal.cpp
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
#include "cal.h"

using namespace std;
//cal revenue
// filename: revenue filename
// sys: company ptr array
//n :system size
void cal(string filename, company_struct * &sys, int n){
    ifstream fin;
    fin.open(filename.c_str());
    // check if the file can be opened
    if (fin.fail()){
        cout << "Error in file opening." << endl;
    }

    string line, id, revenue;
    int new_revenue;

    while(getline(fin,line)){
      istringstream iss(line);

      getline(iss, id, ',');
      getline(iss, revenue, ',');

      new_revenue = stoi(revenue);

      for (int i = 0; i < n; i++){
        if (stoi(id) == stoi(sys[i].id)){
          sys[i].revenue += new_revenue;
          cout << "revenue: "<<sys[i].revenue<<endl;
        }
      }
    }

    cout << "***The revenue of each employee in this month has been inputed***" << endl;
    cout << "***Enter \"CHECK\" command to see the result.***" << endl;
    cout << endl;
}
