#include <iostream>
#include <string>

int main ()
{
    int nCases;
    

    std::cin >> nCases;

    while (nCases--)
    {
        //Read string
        std::string s;
        std::cin >> s; 

        bool player = true; //true -- Alex; false -- Bob

        for (size_t i = 0; i < s.length(); i++)
        {
            if (player) //Alex
            {
                s[i] == 'a' ? s[i] = 'b' : s[i] = 'a';
                
            }
            else    //Bob
            {
                s[i] == 'z' ? s[i] = 'y' : s[i] = 'z';
            }

            player = !player; //switch player
            
        }

        std::cout << s << "\n";
        
    }
    
    return 0;
}