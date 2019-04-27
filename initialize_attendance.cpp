//
//  initialize_attendance.cpp
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
#include "initialize_attendance.h"

using namespace std;
void initialize_attendance(int days, company_struct * &sys, int n){
  for (int i = 0; i < n; i++){
    sys[i].attendance_count += days;
  }
}
