//
//  delete.cpp
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
#include "delete.h"

using namespace std;
// DELETE command
// delete a record of ONE employee in the company_ptr array
// id_to_search: id of employee to be deleted
// return the number of record (n-1)
//sys: company ptr array
//n : num of records in the system
int delete_record(string id_to_search, company_struct sys[], int n){
     char ans;
          for (int i = 0; i < n; i++){
            string id_in_array = sys[i].id;

            if(id_in_array.find(id_to_search) != string::npos)
            {
              cout << "Name:\t" << sys[i].name << endl;
              cout << "ID:\t" << sys[i].id << endl;
              cout << "Age:\t" << sys[i].age << endl;
              cout << "Role:\t" << sys[i].role << endl;
              cout << "Salary:\t" << sys[i].salary << endl;
              cout << endl;

			       cout << "Delete from system (y/n)? ";
              cin >> ans;
              if (ans == 'y')
               {
                  if ( i == n ){
                    n--;
                    cout << endl;
                    cout << "***Number of records have been changed to " << n << ".***" << endl;
                    cout << endl;
                    return n;
                    break;
                  }
                  else
                   {
                    // skip current record and copy all rest records to sys
                    for (int j = i+1; j < n; j++){
                         sys[j-1] = sys[j];
                     }
                    n--;
                    cout << endl;
           	        cout << "***Number of records have been changed to " << n << ".***" << endl;
                    cout << endl;
  				          return n;
  				          break;
                 }
              }
          }
       }
		return n;
}
