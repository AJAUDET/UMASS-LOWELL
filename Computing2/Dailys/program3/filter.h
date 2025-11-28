#ifndef FILTER
#define FILTER

typedef enum status {FAILURE, SUCCESS} Status;
typedef enum boolean {FALSE, TRUE} Boolean;

typedef void* MY_FILTER;

// precondition: None
// postcondition: returns a valid MY_FILTER object
MY_FILTER init_filter_default(void);

// precondition: hFilter is a valid abject, item is a valid integer
// postcondition: the item is properly inserted into the filter, returns a status of FAILURE/SUCCESS
Status insert_to_filter(MY_FILTER hFilter, int item);

// precondition: hFilter is a valid object
// post condition: the size of the filter is returned
int get_size(MY_FILTER hFilter);

// precondition: hFilter is a valid object
// post condition: the capacity of the filter is returned
int get_capacity(MY_FILTER hFilter);

// precondition: hFilter is a valid object, the index value is in bounds of the array
// post condition: the item at position index is returned
int* item_at(MY_FILTER hFilter, int index);

// precondition: hFilter is a valid object
// postondition: the remaining items in the filter are sorted
void sort_items_in_filter(MY_FILTER hFilter);

// precondition: hFilter is a valid object
// postcondition: duplicate items are removed from the filter, returns a status of FAILURE/SUCCESS
Status filter_items(MY_FILTER hFilter);

// precondition: phFilter is a valid pointer to the object
// postcondition: the filter is destroyed
void destroy_filter(MY_FILTER* phFilter);

#endif
