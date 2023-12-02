// Ishan Bhandari
// Date: 11/29/2023

#ifndef BANKER_ALGORITHM
#define BANKER_ALGORITHM

#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h> 
class Banker_Algorithm
{

public:
    // printing the available instances
    void Available()
    {
        std::cout << "Available: ";
        for (auto a : Available_res)
        {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
    // allocating the resources
    void setAllocation(int A, int B, int C)
    {
        std::vector<int> alloc_inst;
        if (A <= Available_res[0] && B <= Available_res[1] && C <= Available_res[2])
        {
            alloc_inst.push_back(A);
            Available_res[0] -= A;
            alloc_inst.push_back(B);
            Available_res[1] -= B;
            alloc_inst.push_back(C);
            Available_res[2] -= C;
            Allocation_of_data.push_back(alloc_inst);
        }
        else
        {
            std::cout << "Allocation resources exceeds the available resource!" << std::endl;
            return;
        }
    }
    // printing the allocated resources to each process
    void Allocation()
    {
        std::cout << "Allocation: " << std::endl;
        for (auto data : Allocation_of_data)
        {
            for (int i = 0; i < data.size(); i++)
            {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    void setMax(int A, int B, int C)
    {
        std::vector<int> alloc_inst;
        alloc_inst.push_back(A);
        alloc_inst.push_back(B);
        alloc_inst.push_back(C);
        Max_data.push_back(alloc_inst);
    }

    // printing the maximum resources each process requires
    void Max()
    {
        std::cout << "Max: " << std::endl;
        for (auto data : Max_data)
        {
            for (int i = 0; i < data.size(); i++)
            {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    // setting the need of the resources 
    void setNeed()
    {
        for (int i = 0; i < Allocation_of_data.size(); i++)
        {
            std::vector<int> alloc_inst;
            for (int j = 0; j < Allocation_of_data[i].size(); j++)
            {
                alloc_inst.push_back(Max_data[i][j] - Allocation_of_data[i][j]);
            }
            Need_data.push_back(alloc_inst);
        }
    }
    // printing the required resources for each processes
    void Need()
    {
        if (Need_data.empty())
        {
            setNeed();
        }
        std::cout << "Need: " << std::endl;
        for (auto data : Need_data)
        {
            for (int i = 0; i < data.size(); i++)
            {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    // deadlock safety algorithm
    bool isSafe()
    {
        // return false;
        int Work[3];
        std::copy(std::begin(Available_res), std::end(Available_res), std::begin(Work));
        int Finish[5] = {false};
        std::vector<int> safe_sequence;

        int i = 0;
        while (i < Need_data.size())
        {

            if ((Need_data[i][0] <= Work[0] && Need_data[i][1] <= Work[1] && Need_data[i][2] <= Work[2]) && (Finish[i] == false))
            {
                Finish[i] = true;
                bool found = false;
                for (int k = 0; k < safe_sequence.size(); k++)
                {
                    if (safe_sequence[k] == Work[i])
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    Work[0] += Allocation_of_data[i][0];
                    Work[1] += Allocation_of_data[i][1];
                    Work[2] += Allocation_of_data[i][2];
                    safe_sequence.push_back(i);
                }
            }

            if (i == 4 && safe_sequence.size() != 5)
            {
                i = -1;
            }
            ++i;
        }

        safe_Sequence = safe_sequence;
        bool safe = true;
        for (int l = 0; l < 5; l++)
        {
            if (Finish[l] == false)
            {

                safe = false;
                break;
            }
        }
        return safe;
    }

    // Printing the safe state sequence
    void safeSequence()
    {
        std::cout << "Safe Sequence: ";
        for (int i = 0; i < safe_Sequence.size(); i++)
        {

            std::cout << "P" << safe_Sequence[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int Available_res[3] = {10, 5, 7};
    std::vector<std::vector<int>> Allocation_of_data;
    std::vector<std::vector<int>> Max_data;
    std::vector<std::vector<int>> Need_data;
    std::vector<int> safe_Sequence;
};

#endif
