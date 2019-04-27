#ifndef STRUCT
#define STRUCT

// structure of variables
struct company_struct{
    std::string name;
    std::string id;
    std::string age;
    std::string role;
    std::string salary;
    bool perfect_attendance;
    std::string perfect_attendance_output; // for printing the output report file
    double monthly_revenue;
    int revenue = 0;
    int attendance_count = 0;
    int early_leave_count = 0;
    int late_count = 0;
};

#endif
