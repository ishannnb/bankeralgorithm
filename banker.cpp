// Name : Ishan Bhandari 
// Date : 11/29/2023


#include <fstream>
#include <string>
#include <sstream>
#include "banker.hpp"
#include<unistd.h>      // for linux 

int main(){

    
    Banker_Algorithm Bank; 
    std::fstream my_file;
    my_file.open("resource.txt");
    if(!my_file){
        std::cout << "File could not open properly!" << std::endl;
    }else{
        std::string ch;
        int i = 0;
        while(std::getline(my_file,ch)){
          

            std::istringstream iss(ch);
            std::vector<int> intVector;
            std::vector<std::vector<int> > bigVector;
            
            

            int num;
            while (iss >> num) {
                intVector.push_back(num);
            }
            
            sleep(1);
            
            std::cout << "Allocating P" << i << std::endl;
            Bank.setAllocation(intVector[0], intVector[1], intVector[2]); //allocate the resource
            Bank.setMax(intVector[3],intVector[4],intVector[5]); //setting the max resources needed
            ++i;
        }

    }
    my_file.close();
    sleep(1);
    Bank.Allocation(); 
    Bank.Max();  
    sleep(1);
    Bank.Need(); 
    sleep(1);
    Bank.Available();  
    Bank.Need();
    sleep(1);
     
    std::cout << "Is this sequence safe?" << std::endl;
    sleep(1);
    if(Bank.isSafe()){
        std::cout <<  "The system is in safe state" << std::endl;
        sleep(1);
        Bank.safeSequence();
    }else{
        std::cout << "No" << std::endl;
    }
    
}
