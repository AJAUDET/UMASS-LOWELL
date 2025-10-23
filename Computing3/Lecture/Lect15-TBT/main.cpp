/***********************************************
Author: AJ Audet
Date: 10 / 19 / 25
Time Spent: 3 hours

Observation for Task 3: The copy list constructor created by the compiler changed the values that were
stored in the copyArray when values in the arrList changed. This means a shallow copy was created,
we want to have a deep copy for our constructor, the one that I have created for my code works
correctly and creats a deep copy of the two

What learned: A shallow copy ties two variables to the same memory address allowing for changes in one 
to affect the other, while a deep copy creates it's own seperate instance of the linked 
list, the memory addresses are different ie: arrList == 0x16af86ba0, copyList == 0x16af86b98

***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for
maintaining good order in the classroom, providing an enriching
learning experience for students, and as training as a practicing
computing professional upon graduation. This practice is
manifested in the University’s Academic Integrity policy.
Students are expected to strictly avoid academic dishonesty and
adhere to the Academic Integrity policy as outlined in the course
catalog. Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the
instructor and approved tutors.
I certify that the work submitted with this assignment is mine
and was generated in a manner consistent with this document, the
course academic policy on the course website on Blackboard, and
the UMass Lowell academic code.
Date: 10/19/25
Name: AJ Audet
*/
#include "LinkedList.hpp"

int main()
{
    int nums[] = {10, 20, 30, 40, 50};
    LinkedList arrList(nums, 5);
    LinkedList copyList(arrList);
    LinkedList singleList(33);
    LinkedList testList(432), otherTest;
    otherTest = testList;

    cout << "---Assignment Linked Lists---" << endl;
    
    cout << "Test linked List:\t\t";
    cout << testList << endl;

    cout << "Copy of Test linked List:\t\t";
    cout << otherTest << endl;

    cout << "---Unmodified Linked Lists---" << endl;

    cout << "Array to linked List:\t\t";
    cout << arrList << endl;

    cout << "Copy of Array Linked List:\t";
    cout << copyList << endl;

    cout << "Single Value Linked List:\t";
    cout << singleList << endl;

    cout << "Address of Array List: " << &arrList << endl;
    cout << "Address of Copy List: " << &copyList << endl;

    cout << "---Altered Lists---" << endl;

    arrList.preAppend(42);
    copyList.postAppend(34);
    singleList.postAppend(550);
    singleList.postAppend(336);

    cout << "Pre Append Array Linked List:\t";
    cout << arrList << endl;

    cout << "Post Append Copy Linked List:\t";
    cout << copyList << endl;

    cout << "Post Append x2 Single Value Linked List:\t";
    cout << singleList << endl;

    return 0;
}