#include "queue.h"
#include <vector>
#include <cstdlib> // for random so that i can create random times
#include <time.h> //for random so that i can create random times

void shiftForward(std::vector<nodespace::QList> &l){
    for(int i = 0; i < 5; i++){
        int holder = l[i].front() - 1;
        l[i].pop();
        if(holder > 0)
            l[i].push(holder);
        if(!l[i].empty()){
            for(int j = 0; j < l[i].size() - 1; j++){
                l[i].push(l[i].front());
                l[i].pop();
            }
        }
    }
}


void swapOver(std::vector<nodespace::QList> &l){
    bool isDone = false;
    while(!isDone){
        int posSmall = 99;
        int small = 99;
        for(int i = 0; i < 5; i++){
            if(l[i].size() < small){
                small = l[i].size();
                posSmall = i;
            }
        }
        int posLarge = 0;
        int large = 0;
        for(int i = 0; i < 5; i++){
            if(l[i].size() > large){
                large = l[i].size();
                posLarge = i;
            }
        }
        
        if(large - small > 1){
            //first i get the last customer to the front of the queue
            for(int i = 0; i < l[posLarge].size() - 1; i++){
                int temp = l[posLarge].front();
                l[posLarge].push(temp);
                l[posLarge].pop();
            }
            
            std::cout << "A customer of check-out time " << l[posLarge].front() << "-minutes has swapped over to line " << posSmall + 1 << " from line " << posLarge + 1 << "\n";
            l[posSmall].push(l[posLarge].front());
            l[posLarge].pop();
            for(int i = 0; i < 5; i++){
                l[i].functionIMadeForPrinting();
            }
            std::cout << "\n";
        }
        else
            isDone = true;
    }
}

void groceryStore(){
 
    srand(time(NULL));
    std::vector<nodespace::QList> lines;
    for(int i = 0; i < 5; i++){
        nodespace::QList temp;
        lines.push_back(temp);
    }
    //was not sure how long this program should run for so i
    //let the user enter decide
    char cont = 'y';
    while(cont == 'y'){
       
        int numberOfCustomers = rand() % 5 + 1;
        std::cout << "\n\n\n";
        std::cout << "-----------------------------------------------------------------------------------------------------------------------";
        std::cout << "\n\n\n";
        std::cout << numberOfCustomers << " new customers are ready to check-out:\n\n";
        for(int i = 0; i < numberOfCustomers; i++){
            //creating a customer of a wait time between 1 and 3
            int customer = rand() % 10 + 1;
            //this gets the position of the shortest line in the queue
            //if they are all the same then the first line is chosen
            int pos = 99;
            int shortest = 99;
            for(int i = 0; i < 5; i++){
                if(lines[i].size() < shortest){
                    shortest = lines[i].size();
                    pos = i;
                }
            }
            //shortest line is at lines[pos]
            std::cout << "Customer with a check-out time needed of " << customer << "-minutes joined line " << pos+1 << "\n";
            lines[pos].push(customer);
            for(int i = 0; i < 5; i++){
                lines[i].functionIMadeForPrinting();
            }
            std::cout << "\n";
        }
        //calls the function to simulate a minute passing
        std::cout << "One minute has passed\n";
        shiftForward(lines);
        for(int i = 0; i < 5; i++){
            lines[i].functionIMadeForPrinting();
        }
        std::cout << "\n";    
        //calling the function that lets customers swap over to shorter lines
        swapOver(lines);
        //asking the user if they want to continue
        std::cout << "Continue simulation? (y/n) ";
        std::cin >> cont;
    }
}

int main(){
    //note that the printed numbers are lines from left to right with the 
    //left-most number being the start of that line
    std::cout << "The program currently has the following properties:\nA random number of customers will join the lines every \"minute\"\n";
    std::cout << "The customers will have random values which represents the minutes they will take once they get to the register\n";
    std::cout << "The new customers will join the shortest line, if all are of equal length they will join the first one\n";
    std::cout << "The existing customers will all look for a line that is two or more customers shorter than their line and swap to it\n";
    std::cout << "Customers in the end of the longest lines will be prioritized when choosing who to move to the shorter lines\n";
    std::cout << "Enjoy the grocery shopping simulation:";
    groceryStore();
}
