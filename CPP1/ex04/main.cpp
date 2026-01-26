#include <iostream>
#include <fstream>
#include <string>

void	handmade_sed(std::string& line, std::string s1, std::string s2)
{
	size_t	pos;

	pos = line.find(s1);
	while (pos != std::string::npos)
	{
		line.erase(pos, s1.size());
		line.insert(pos, s2);
		pos = line.find(s1);
	}
}

int	main(int arc, char **arv)
{
	if (arc < 4)
	{
		std::cout << "Please enter valid number of parameters\n";
		return (0);
	}
	std::string		filename = arv[1];
	std::ifstream	input(filename.c_str());
	if (!input)
		return (1);
	std::string content;
	input.seekg(0, std::ios::end);
	content.reserve(input.tellg());
	input.seekg(0, std::ios::beg);
	std::string line;
	while (std::getline(input, line))
	{
		handmade_sed(line, arv[2], arv[3]);
		if (!input.eof())
			content += line + "\n";
	}
	filename.append(".replace");
	std::ofstream output(filename.c_str());
	if (!output)
	{
		std::cerr << "Error creating file\n";
		return (1);
	}
	output << content;
	return (0);
}
