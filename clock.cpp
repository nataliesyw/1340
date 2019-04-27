//
//  clock.cpp
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
#include "clock.h"

using namespace std;

// calculate the late record according to clock in and clock out time
// filename: the clock-in and clock-out raw text file filename
//sys: company ptr array
//n: num of records in the system
void clock(string filename, company_struct * &sys, int n){
    ifstream fin;
    fin.open(filename.c_str());
    // check if the file can be opened
    if (fin.fail()){
        cout << "Error in file opening." << endl;
    }
    string line, id, start_time, end_time;
    while(getline(fin,line)){
      istringstream iss(line);

      getline(iss, id, ',');
      getline(iss, start_time, ',');
      getline(iss, end_time, ',');

      int new_start, new_end;
      new_start = stoi(start_time);
      new_end = stoi(end_time);


      for (int i = 0; i < n; i++){
        if (stoi(id) == stoi(sys[i].id)){
          // absent
          if (new_start == 9999 && new_end == 9999){
            sys[i].attendance_count -= 1;
          }
          else{
            //late
            if (new_start > 900){
                sys[i].late_count += 1;
            }
            // early leave
            if (new_end < 1700){
                sys[i].early_leave_count += 1;
            }
          }
        }
      }
    }

    cout << endl;
    cout << "***Attendance, late and early leave of each employee has been calculated.***" << endl;
    cout << "***Enter \"CHECK\" command to see the result.***" << endl;
    cout << endl;
  }
