//Data: 2.85 6.74 28.93 61.22 10.00 45.34 61.78 5.75

#include <iostream>
 
#include "unorderedArrayListType.h"

using namespace std; 

int main() 
{
    unorderedArrayListType<double> numList(25); 

    double num;                                

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

    return 0;                                   
}
