/*
    Name: Graham Atlee
    Course: csc1720
    Date: 11/5/19
    Location of Program: ~/csc1720/Labs/lab11

    This program contains driver code to test all the methods 
    in the unorderedArrayListType class.

*/
#include <iostream>
#include <string>
#include "unorderedArrayListType.h"

using namespace std; 

//Test Data: 2.85 6.74 28.93 61.22 10.00 45.34 61.78 5.75

int main() 
{
    unorderedArrayListType<double> numList(25); 

    double num;
    int loc;                                

    cout << "Enter 8 numbers: ";        

    for (int count = 0; count < 8; count++)     
    {
        cin >> num;                             
        numList.insertEnd(num);                 
    }

    cout << endl;                               

    cout << "numList: ";               
    numList.print();                           
    cout << endl;                               

    cout << "Enter the number to be " 
         << "deleted: ";                        
    cin >> num;                                 
    cout << endl;                               

    numList.remove(num);                        
    cout << "After removing " << num
         << " numList: ";                       
    numList.print();                            
    cout << endl;                              
 
    cout << "Enter the search item: "; 

    cin >> num;                                 
    cout << endl;                               

    if (numList.seqSearch(num) != -1)           
        cout <<  num << " found in numList." << endl;   
    else                                        
        cout <<  num << " is not in numList." << endl;  

/*
==============================================================
NEW TEST CODE EXTENSION BELOW (11 / 5 / 19)
==============================================================
*/

    //lets test replaceAt here 
    cout << "Replace item at a location: " << endl;
    cout << "Type location: ";
    cin >> loc;
    cout << "Type replacement number: ";
    cin >> num;
    numList.replaceAt(loc, num);
    cout << "Updated list: ";
    numList.print();

    //test isItemAtEqual here
    cout << "Check if item is equal at a location" << endl;
    cout << "Type location: ";
    cin >> loc;
    cout << "Type comparison number: ";
    cin >> num;
    bool result = numList.isItemAtEqual(loc, num);
    if(result == 1)
        cout << "Item is equal" << endl;
    else
        cout << "Item is NOT equal" << endl;

    //test removeAt here
    cout << "Remove an item at a location" << endl;
    cout << "Type location: ";
    cin >> loc;
    numList.removeAt(loc);
    cout << "Updated list: ";
    numList.print();

    //will test retrieveAt here 
    cout << "Retrieve a number at a location" << endl;
    cout << "Type location: ";
    cin >> loc;
    cout << "Type retrievable number: ";
    cin >> num;
    numList.retrieveAt(loc, num);
    cout << "Retrieved number: " << num << endl;

    //testing overloaded assignment operator here
    cout << "Assigning a newList to numList" << endl;
    unorderedArrayListType<double> newList(5);
    newList = numList;
    cout << "newList: ";
    newList.print(); 
    cout << endl; //newline 

/*
=====================================
Testing Integer list & and all previous stub functions
in this section
=====================================
*/
    cout << "TESTING INTEGER LIST" << endl;
    cout << "=====================" << endl;

    cout << "Creating integerList of size 5" << endl;
    unorderedArrayListType<int> integerList(5);
    
    //here we will test isEmpty()
    cout << "Testing if integerList is empty. Should return 1" << endl;
    cout << integerList.isEmpty() << endl;

    //test isFull()
    cout << "Testing if integerList isFull. Should return 0" << endl;
    cout << integerList.isFull() << endl;

    //call insertAt 2 times 
    cout << "Inserting 2 and 5 at positions 0, 1" << endl;
    integerList.insertAt(0, 2);
    integerList.insertAt(1, 5);
    cout << "integerList: ";
    integerList.print();

    //check listSize()
    cout << "Calling integerList listSize. Should return 2" << endl;
    cout << integerList.listSize() << endl;

    //call maxListSize()
    cout << "Calling maxListSize. Should return 5" << endl;
    cout << integerList.maxListSize() << endl;

    //test clearList() here
    cout << "Calling clearList and checking the new length" << endl;
    integerList.clearList();
    cout << "integerList: ";
    integerList.print();
    cout << "length: " << integerList.listSize() << endl;

    //try the copy constructor 
    cout << "Creating newIntegerList through copy constructor" << endl;
    unorderedArrayListType <int>newIntegerList(integerList);
    cout << "newIntegerList (should be empty): ";
    newIntegerList.print();

    //test for shallow copy by calling insertAt()
    cout << "Testing for shallow copy by inputting data into newIntegerList" <<endl;
    newIntegerList.insertAt(0,3);
    newIntegerList.insertAt(1,4);
    newIntegerList.insertAt(2,2);
    cout << "newIntegerList: ";
    newIntegerList.print();
    cout << "integerList (should be empty): ";
    integerList.print(); 
    cout << endl; //newline

/*
=====================================
Testing String List 
=====================================
*/
    int i;

    cout << "TESTING STRING LIST" << endl;
    cout << "===================" << endl;

    cout << "Creating stringList with default constructor" << endl;
    unorderedArrayListType <string>stringList;

    //call maxSize to ensure default constructor worked 
    cout << "Printing maxSize of stringList. Should be 100" << endl;
    cout << stringList.maxListSize() << endl;

    //test insertEnd in a loop here 
    cout << "Inserting \"Apple\" into stringList 50 times" << endl;
    for(i=0; i < 50; i++)
        stringList.insertEnd("Apple");
    stringList.print();

    //call remove in a loop
    cout << "Removing \"Apple\" 25 times" << endl;
    for(i=0; i < 25; i++)
        stringList.remove("Apple");
    cout << "Updated stringList: ";
    stringList.print();

    //call insertAt in a loop with new word
    cout << "Calling replaceAt 25 times to replace all \"Apple\"'s " << endl;
    string replacement = "Pear";
    for(i=0; i < 25; i++)
        stringList.replaceAt(i, replacement);
    cout << "Updated stringList: ";
    stringList.print();

    //insert a bunch of random data with insertEnd in loops
    cout << "Inserting random data into the list with insertEnd" << endl;
    for(i=0; i < 25; i++)
        stringList.insertEnd("Orange");
    for(i=0; i< 15; i++)
        stringList.insertEnd("Grape");
    for(i=0; i< 10; i++)
        stringList.insertEnd("Banana");
    stringList.print();
    
    //use seqsearch here 
    cout << "Searching for \"Grape\". Should return index 50" << endl;
    cout << stringList.seqSearch("Grape") << endl;

    //refresh on size and maxs
    cout << "stringList length: " << stringList.listSize() << endl; 
    cout << "stringList max size: " << stringList.maxListSize() << endl;

    //attempt to go over the list limit
    cout << "Attempting to go over stringList maxSize" << endl;
    for(i=0; i<26; i++)
        stringList.insertEnd("Strawberry");

/*
============
END OF TEST
============
*/


    return 0;                                   
}
