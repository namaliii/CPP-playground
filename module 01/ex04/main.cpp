/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:23:55 by anamieta          #+#    #+#             */
/*   Updated: 2024/10/28 13:50:10 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string findandreplace(std::string fileContent, const std::string& s1, const std::string& s2) {
	size_t startPos = 0;
	size_t foundPos;
	std::string result;
	while ((foundPos = fileContent.find(s1, startPos)) != std::string::npos) {
		result.append(fileContent, startPos, foundPos - startPos);
		result.append(s2);
		startPos = foundPos + s1.length();
	}
	result.append(fileContent, startPos, std::string::npos);
	return result;
}

void replace_file(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
		return;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty() || s2.empty()) {
		std::cerr << "Error: arguments cannot be empty" << std::endl;
		return;
	}
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string fileContent = buffer.str();
	file.close();
	if (fileContent.empty()) {
		std::cerr << "Error: File is empty" << std::endl;
		return;
	}
	std::cout << "File content:\n" << fileContent << std::endl;
	std::string modified = findandreplace(fileContent, s1, s2);
	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		std::cerr << "Error: Unable to create file " << outFilename << std::endl;
		return;
	}
	outFile << modified;
	outFile.close();
	std::cout << "\nFile: " << outFilename << " contains modified content:" << std::endl;
	std::cout << modified << std::endl;
}

int main(int argc, char** argv) {
	replace_file(argc, argv);
	return 0;
}