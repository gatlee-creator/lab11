//Data: 2.85 6.74 28.93 61.22 10.00 45.34 61.78 5.75

#include <iostream>
 
#include "unorderedArrayListType.h"

using namespace std; 

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

    // //lets test insertAt here -STUB 
    // cout << "Insert item at a location (loc, num): " << endl;
    // cin >> loc;
    // cin >> num; 
    // numList.insertAt(loc, num);
    // numList.print();

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

    return 0;                                   
}
