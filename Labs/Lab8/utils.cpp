/*********************************************************************
 ** Program name: Searching and Sorting
 ** Author: Joel Huffman
 ** Date: 2/28/2018
 ** Description:
 *********************************************************************/

#include "utils.hpp"
#include "readFileToArray.hpp"
#include "searchFor.hpp"
#include "bubbleSort.hpp"
#include <vector>
using std::vector;

/*********************************************************************
 ** intValidation:
 ** Checks cin if input is an integer within the minimum and maximum
 ** values. Returns the integer if it is acceptable, lists prompt and
 ** asks again if input is invalid.
 *********************************************************************/
int intValidation(int min, int max, string prompt)
{
    string input;
    int validInt;
    
    while (true)
    {
        cout << prompt;
        
        //get inut from user
        getline(cin, input);
        
        stringstream ss(input);
        
        //if input has an int and nothing after that
        if (ss >> validInt && !(ss >> input))
        {
            //check if within bounds
            if (validInt > max || validInt < min)
            {
                cout << "\nInvalid int. Must be between "
                << min << " and " << max << ".\n\n";
            }
            
            //if valid integer
            else
            {
                return validInt;
            }
        }
        
        //if noninteger value entered
        else
        {
            cout << "\nInvalid input. Please enter an integer.\n\n";
        }
        
    }
}

/*********************************************************************
 ** menu():
 ** guides user through searching, sorting and outputing files of integers
 *********************************************************************/
int menu()
{
    int targetValue;
    string outputFileName;
    string prompts[] = {
        "Welcome to the searching and sorting program\n",
        "What target value should we search the files for?\n",
        "what would you like to name the output file?\n",
        "What target value should we search the files for using binary search?\n"
    };

    //welcome message
    cout << prompts[0];
    
    //create vectors for .txt files
    vector<int> numArray;
    vector<int> earlyArray;
    vector<int> midArray;
    vector<int> endArray;
    
    //create pointers to vectors
    vector<int>* ptrNum = &numArray;
    vector<int>* ptrEarly = &earlyArray;
    vector<int>* ptrMid = &midArray;
    vector<int>* ptrEnd = &endArray;
    
    //populate vectors with values from .txt files
    readFileToArray("num.txt", ptrNum);
    readFileToArray("early.txt", ptrEarly);
    readFileToArray("mid.txt", ptrMid);
    readFileToArray("end.txt", ptrEnd);
    
    //ask for target value
    targetValue = intValidation(-99, 99, prompts[1]);
    
    //print out results of search
    cout << "num.txt: " << searchFor(targetValue, ptrNum);
    cout << "early.txt: " << searchFor(targetValue, ptrEarly);
    cout << "mid.txt: " << searchFor(targetValue, ptrMid);
    cout << "end.txt: " << searchFor(targetValue, ptrEnd);
    
    //get output filename for numArray
    cout << "For first file, " << prompts[2];
    cin >> outputFileName;
    //sort vector
    bubbleSort(ptrNum);
    //print sorted vector
    printSorted(ptrNum);
    //write vector to outputfile
    outputSorted(ptrNum, outputFileName);
    
    //get output filename for earlyArray
    cout << "For second file, " << prompts[2];
    cin >> outputFileName;
    //sort vector
    bubbleSort(ptrEarly);
    //print sorted vector
    printSorted(ptrEarly);
    //write vector to outputfile
    outputSorted(ptrEarly, outputFileName);
    
    //get output filename for midArray
    cout << "For third file, " << prompts[2];
    cin >> outputFileName;
    //sort vector
    bubbleSort(ptrMid);
    //print sorted vector
    printSorted(ptrMid);
    //write vector to outputfile
    outputSorted(ptrMid, outputFileName);
    
    //get output filename for endArray
    cout << "For fourth file, " << prompts[2];
    cin >> outputFileName;
    //sort vector
    bubbleSort(ptrEnd);
    //print sorted vector
    printSorted(ptrEnd);
    //write vector to outputfile
    outputSorted(ptrEnd, outputFileName);
    
    cout << "Results for binary search of target value:\n";
    
    //run binary search for target value
    cout << "num.txt: " << binarySearch(targetValue, ptrNum);
    cout << "early.txt: " << binarySearch(targetValue, ptrEarly);
    cout << "mid.txt: " << binarySearch(targetValue, ptrMid);
    cout << "end.txt: " << binarySearch(targetValue, ptrEnd);
    
    return 0;
}
