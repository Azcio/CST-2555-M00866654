#include <iostream> //allows input and output stream
#include <vector> // allows me to use vectors
using namespace std; // allows us to not use std
 
//the  inputted value of processes
//i = processors
//e.g, 5 processors = P0 - P4
 int processors;

//the inputted value of resources
//j = resources
//4 resources = A B C D
int resources;

//The input needed to start the program. Will prompt the user
char start;

int main(){

    do //using a do while loop to loop the entire code for new users
    {
        //Prompt the user to create a process
     cout << "Welcome, will you like to create a process [y/n]: \n";
cin >> start;

if (start == 'y') {
  cout << "Enter the amount of resources that you will need:  \n";
cin >> resources;  
cout << "Enter the number of processors that you want: \n";
cin >> processors;

//allocation is an array showing the number of resources allocated to each process
int allocation[processors][resources];

//The user will input the resource allocated to each process
cout << "Enter the allocation:\n";
        for (int i = 0; i < processors; ++i) { //nested loop. i allows the user to iterate each processor and only the number of inputted processors.
            for (int j = 0; j < resources; ++j) { //nested loop. J iterates each resource for the current i/processor.
                cout << "Enter allocation for Processor " << i << " and Resource " << j << ": "; //A print statement to show the current processor and resource the user is inputting
                cin >> allocation[i][j]; //the user will enter a input for the allocation of the current processor and resource   

            //Validation to make sure that the inputted allocation is more then 0 and doesn't past the
            //inputted resources. e.g, if resource is 4 then the resource in allocation must be 0-4
if (allocation[i][j] < 0) {
cout << "You entered a invalid input. Allocation must not be below 0. \n";
j--;//re-enter the input untill a correct input is entered
}
else if (allocation[i][j] > resources) {
    cout << "You entered a invalid input. Allocation must not be over the inputted resource. \n";
    j--; //re-enter the input untill a correct input is entered
}
}
        }

// Display the allocation Array
        cout << "Allocation Array:\n";
        for (int i = 0; i < processors; ++i) {
            for (int j = 0; j < resources; ++j) {
                cout << allocation[i][j] << " ";
            }
            cout << '\n';
        }

//Max an array that shows the max demand of resources in each process
 int Max[processors][resources];

//User will input the max demand in each process
cout << "Enter the Max demand: \n";
for (int i = 0; i < processors; ++i){
for (int j = 0; j < resources; ++j) {
    cout << "Enter the Max demand for processor " << i << " and Resource " << j << ": ";
    cin >> Max[i][j];

//Validadation to make sure the inputted Max demand is not less then 0
if (Max[i][j] < 0) {
    cout << "You entered a invalid input. The Max must not be below 0 \n";
    j--;
}
}
}

//Display the Max demand array
cout << "Max demand Array: \n";
for (int i = 0; i < processors; ++i){
    for (int j = 0; j < resources; ++j){
        cout << Max[i][j] << " ";
    }
    cout << '\n';
}

//Available is a vector showing the number of available resources
//if Available[j] = k, 
//Must use vectors to show the available resources because wiki said to
vector<int> Available(resources);

//User must input available resources
cout << "Enter the number of available resources: \n";
for (int j = 0; j < resources; ++j) {
    cout << "Enter the available resources for resource " << j << ": ";
    cin >> Available[j];

    if (Available[j] < 0 ) {
        cout << "You entered a invalid input. Available resource must not be below 0 \n";
    }
}

//Display the available vector
cout << "Available Resources: \n";
for (int j = 0; j < resources; ++j){
    cout << Available[j] << " ";
}
cout << "\n";

// need  shows the remaining resources needed for each process
// need is the additional resources that a process may still need to be completed
//need = Max - Allocation
int Need[processors][resources];
for (int i = 0; i < processors; ++i) {
    for (int j = 0; j < resources; ++j) {
        Need[i][j] = Max[i][j] - allocation[i][j];
    }
}

//Display the need
cout << "Needed resources: \n";
for (int i = 0; i < processors; ++i){
    for (int j = 0; j < resources; ++j){
        cout << Need[i][j] << " ";
    }
    cout << '\n';
}

//Need to find out if the need is equal or less then the available resources
bool safe = true;

 for (int i = 0; i < processors; ++i) { //for loop to check over every process/i to see if the system will be in a safe state
    bool SafeProcess = true; //check if the processes being checked is safe
    vector<int> NewAvailable(Available); // get the value of the current Available and copy it
//NewAvailable will be updated by adding Allocation to the NewAvailable

    for (int j = 0; j < resources; ++j) {
        if (Need[i][j] > Available[j]) { //check if every resource/j needed by the process is less or equal to the available reources
            SafeProcess = false; // if the condition is not met set to process is not safe 
            cout << "Process " << i << " doesn't meet the condition \n";
            break; // break the inner loop if a resource value is not met
        }
    

    else { // if the safeProcess is true after checking the resources then calculate NewAvailable so that the next process can be checked
 NewAvailable[j] += allocation[i][j];
    }
}

if (SafeProcess) { //if both the process and resources are safe(SafeProcess) then announce the current process as safe
cout << "Process " << i << " is safe. \n";
Available = NewAvailable; //Update the Available to have the NewAvailable value so that the next process can be checked
}
else {
    safe = false; //if the process is not safe then set the boolean safe to false
}
}

if (safe) { //if all the processors are safe then the system/boolean is safe, print that the following print statement
    cout << "System is in a safe state. \n";
} else { //If one processor is not in a safe state then the system/boolean is not safe/false, print the following print statement
    cout << "System is not in a safe state. \n";
} 

} else if (start == 'n') { //if the user enters n when being prompt to start the system/code then the code will end
    cout << "You chose to not create a process";
    return 0; //end the program if user enters n
} while (start != 'y' && start != 'n') //if the user enters a value that isn't y or n then they will be asked to continue entering a input until it's n or y
{
    cout << "You entered a invalid value. Please enter Y or N \n";
    cin >> start;
}

    } while (start == 'y'); //while the input value is y then the program will continue to execute the code
    
return 0;

}