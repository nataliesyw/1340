//
//  sort.cpp
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
#include "sort.h"

using namespace std;
// SORT command
// print out all records which are sorted
// selectively print out the records *******if we have time*******
// num: number of records in the system
// sys: the company array
// ori_num: the last id of the original input company text file
void sort_record(string attribute, string order, company_struct sys[], int num, int ori_num){
  int i, j ,idx;
  int min;
  int max;
  // selection sort

  // sort by ascending order
  if (order == "a"){

    // sort by age
    if (attribute == "1"){
      for (i = 0; i < num - 1; i++)
      {
          min = stoi(sys[i].age);
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (stoi(sys[j].age) < min)
              {
                  min = stoi(sys[j].age);
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by salary
    if (attribute == "2"){
      for (i = 0; i < num - 1; i++)
      {
          min = stoi(sys[i].salary);
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (stoi(sys[j].salary) < min)
              {
                  min = stoi(sys[j].salary);
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by revenue
    if (attribute == "3"){
      for (i = 0; i < num - 1; i++)
      {
          min = sys[i].revenue;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].revenue < min)
              {
                  min = sys[j].revenue;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }
    // sort by times for being late
    if (attribute == "4"){
      for (i = 0; i < num - 1; i++)
      {
          min = sys[i].late_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].late_count < min)
              {
                  min = sys[j].late_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by times for left early
    if (attribute == "5"){
      for (i = 0; i < num - 1; i++)
      {
          min = sys[i].early_leave_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].early_leave_count < min)
              {
                  min = sys[j].early_leave_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    //sort by attdence
    if (attribute == "6"){
      for (i = 0; i < num - 1; i++)
      {
          min = sys[i].attendance_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].attendance_count < min)
              {
                  min = sys[j].attendance_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

  }

  // sort by descending order
  if (order == "d"){

    // sort by age
    if (attribute == "1"){
      for (i = 0; i < num - 1; i++)
      {
          max = stoi(sys[i].age);
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (stoi(sys[j].age) > max)
              {
                  max = stoi(sys[j].age);
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by salary
    if (attribute == "2"){
      for (i = 0; i < num - 1; i++)
      {
          max = stoi(sys[i].salary);
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (stoi(sys[j].salary) > max)
              {
                  max = stoi(sys[j].salary);
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by revenue
    if (attribute == "3"){
      for (i = 0; i < num - 1; i++)
      {
          max = sys[i].revenue;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].revenue > max)
              {
                  max = sys[j].revenue;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }
    // sort by times for being late
    if (attribute == "4"){
      for (i = 0; i < num - 1; i++)
      {
          max = sys[i].late_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].late_count > max)
              {
                  max = sys[j].late_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    // sort by times for left early
    if (attribute == "5"){
      for (i = 0; i < num - 1; i++)
      {
          max = sys[i].early_leave_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].early_leave_count > max)
              {
                  max = sys[j].early_leave_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

    //sort by attdence
    if (attribute == "6"){
      for (i = 0; i < num - 1; i++)
      {
          max = sys[i].attendance_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].attendance_count > max)
              {
                  max = sys[j].attendance_count;
                  idx = j;
              }
          }

          if (idx != i)
          {
              company_struct temp;
              // swap pb[i] & pb[idx]
              temp    = sys[i];
              sys[i]   = sys[idx];
              sys[idx] = temp;
          }
      }
    }

  }
  // newly added record: no late, attendance, early leave record
  if (attribute == "3" || attribute == "4" || attribute == "5"){
    for ( int k = 0; k < num; k++){
      // newly added record
      if (stoi(sys[k].id) > ori_num){
        cout << "***No such record for this employee***" << endl;
        cout << "Name:\t" << sys[k].name << endl;
        cout << "ID:\t" << sys[k].id << endl;
        cout << "Age:\t" << sys[k].age << endl;
        cout << "Role:\t" << sys[k].role << endl;
        cout << "Salary:\t" << sys[k].salary << endl;
        cout << endl;
      }

      else{
        cout << "Name:\t" << sys[k].name << endl;
        cout << "ID:\t" << sys[k].id << endl;
        cout << "Age:\t" << sys[k].age << endl;
        cout << "Role:\t" << sys[k].role << endl;
        cout << "Salary:\t" << sys[k].salary << endl;
        cout << endl;
      }
    }
  }

  else{
    for ( int k = 0; k < num; k++){

      cout << "Name:\t" << sys[k].name << endl;
      cout << "ID:\t" << sys[k].id << endl;
      cout << "Age:\t" << sys[k].age << endl;
      cout << "Role:\t" << sys[k].role << endl;
      cout << "Salary:\t" << sys[k].salary << endl;
      cout << endl;
    }
  }

}
