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
