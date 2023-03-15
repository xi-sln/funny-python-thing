#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>

class properties
{
    public:
    int lines = INT32_MAX;
    
    std::string getFile()
    {
        std::string fileName;
        std::cout << "Enter file name: ";
        std::cin >> fileName;
        fileName += ".py";
        return fileName;
    }
    
    std::string fileName = getFile();
};

void write()
{
    properties properties;
    int i = 0;

    double percentage = 0;
    int totalLines = INT32_MAX / 2; 

    std::ofstream outfile(properties.fileName);
    std::cout << "Creating solution for " << properties.fileName;

    if(outfile.is_open())
    {
        for(i = 0; i < properties.lines; i++)
        {
            if(i % 2 == 0)
            {
                outfile << "if number == " << i << ":\n \t print('" << i << " is even')" << std::endl;
            }
            else
            {
                outfile << "if number == " << i << ":\n \t print('" << i << " is odd')" << std::endl;
            }

            if(i % 10000 == 0)
            {
                percentage = static_cast<double>(i) / totalLines * 100.0;
                std::stringstream ss;
                ss << "Progress: " << percentage << "%";
                SetConsoleTitleA(ss.str().c_str());
                std::cout << "Line: " << i << std::endl;
            }
        }

        std::cout << "Generated " << i << " lines" << std::endl;
        outfile.close();
    }
}

int main()
{
    write();
    return 0;
}
