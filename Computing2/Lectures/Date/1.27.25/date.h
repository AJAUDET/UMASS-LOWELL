
typedef void* DATE; // handle type definition

// handle == a pointer that cannot be dereferenced

DATE date_init_default(void);
 
//accessor functions
int date_get_day(DATE hDate);
int date_get_month(DATE hDate);
int date_get_year(DATE hDate);
char* date_get_year_name(DATE hDate);

// mutator functions
Satus date_set_day(DATE hDate, int day);

void date_output(DATE hDate);

void date_destroy(DATE* phDate);