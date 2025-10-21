typedef void* DATE; // void* is any pointer 

DATE dateInitDefault();
dateDestroy(DATE hDate);

int dateSet(DATE hDate, int newMonth, int newDay, int newYear);
void dateOutput(DATE hDate); 