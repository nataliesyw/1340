//
//  refresh.cpp
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
#include "refresh.h"

using namespace std;
// Refresh command
// To sort all the infomation according to their ID
//sys: company ptr array
//num : num of records in the system
void refresh(company_struct sys[], int num){
  int i, j ,idx;
  string min;

  for (i = 0; i < num - 1; i++){
    min = sys[i].id;
    idx = i;

    for (j = i + 1; j < num; j++){
      if (sys[j].id < min){
          min = sys[j].id;
          idx = j;
      }
    }

    if (idx != i){
      company_struct temp;
      // swap pb[i] & pb[idx]
      temp    = sys[i];
      sys[i]   = sys[idx];
      sys[idx] = temp;
    }
  }

}
