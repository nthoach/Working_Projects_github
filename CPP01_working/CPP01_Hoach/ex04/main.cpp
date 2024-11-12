#include <fstream>
#include <iostream>
#include <string>

void replacewrite(std::ifstream& iFile, std::ofstream& oFile, const std::string s1, const std::string s2)
{
	std::string line;
    while (std::getline(iFile, line))
	{
        size_t pos = 0;

        // Loop to find and replace all occurrences of s1 with s2
        while ((pos = line.find(s1, pos)) != std::string::npos)
		{
            // Create the new string with the replacement
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.size());
			pos += s2.size(); // Move past the replaced string
        }

        // Write the modified line to the output file
        oFile << line << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::string fname;
    std::string s1;
    std::string s2;

    if (argc != 4)
        return std::cerr << "Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl, 1;

    fname = argv[1];
    s1 = argv[2];
    s2 = argv[3];

    if (fname.empty() || s1.empty() || s2.empty())
        return std::cerr << "Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl, 1;

    // Open input file
    std::ifstream iFile(fname.c_str());
    if (!iFile.is_open())
        return std::cerr << "Error: Unable to open " << fname << std::endl, 1;

    // Open output file
    std::ofstream oFile((fname + ".replace").c_str());
    if (!oFile.is_open())
        return std::cerr << "Error: Unable to create " << fname << ".replace" << std::endl, 1;

    // Process each line of the input file
	replacewrite(iFile, oFile, s1, s2);

	//safety close
    iFile.close();
    oFile.close();

    return 0;
}
