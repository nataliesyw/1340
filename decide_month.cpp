//
//  decide_month.cpp
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
#include "decide_month.h"

using namespace std;
int decide_month(int month){
    if (month == 1 || month == 7 || month == 8)
      return 22;

    if (month == 3|| month == 5 || month == 9 || month == 10 || month == 11)
      return 21;

    if (month == 12)
      return 20;

    if (month == 4 || month == 6)
      return 19;

    if (month == 2)
      return 17;
}
