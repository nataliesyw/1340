
          {
              if (sys[j].salary > max)
              {
                  max = sys[j].salary;
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

    int max_int;          // minimum for interger
    // sort by times for being late
    if (attribute == "Late"){
      for (i = 0; i < num - 1; i++)
      {
          max_int = sys[i].late_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].late_count > max_int)
              {
                  max_int = sys[j].late_count;
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
    if (attribute == "Early leave"){
      for (i = 0; i < num - 1; i++)
      {
          max_int = sys[i].early_leave_count;
          idx = i;

          for (j = i + 1; j < num; j++)
          {
              if (sys[j].early_leave_count > max_int)
              {
                  max_int = sys[j].early_leave_count;