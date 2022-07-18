#include <iostream>
#include <string>
#include <vector>

int main ()
{
    int nCases;
    std::cin >> nCases;

    while (nCases--)
    {
        int M, X;
        int N = 0;

        std::cin >> M; //read number of piles 

        for (int i = 0; i < M; i++)  //Read sizes
        {
            int size;
            std::cin >> size;

            //Calculate Xor
            i == 0 ? X = size : X = X ^ size;
        }

        //Calculate winner
        X == 0 ? N = 1 : N = 0;
        
        std::cout << N << "\n";
        
    }
    
    return 0;
}