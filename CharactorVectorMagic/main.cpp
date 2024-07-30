//
//  main.cpp
//  CharactorVectorMagic
//
//  Created by Aniket Sedhai on 7/4/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void print_chars_from_vector(std::vector <char>& char_vector);
void print_char_from_char_ptr_vector(std::vector<char*>& char_ptr_vector);

int main(void) 
{
    // Create a vector of characters with "abcde" in it
    std::vector<char> vector_with_chars {'a', 'b', 'c', 'd', 'e'};
    
    // Add "f" through "z" to it
    for (char i = 'f'; i <= 'z'; ++i)
    {
        vector_with_chars.push_back(i);
    }
    
    // Print it
    print_chars_from_vector(vector_with_chars);
    
    // Shuffle it
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vector_with_chars.begin(), vector_with_chars.end(), g);
    
    // Print it
    print_chars_from_vector(vector_with_chars);
    
    // Find the 'z' and erase it
    vector_with_chars.erase(std::find(vector_with_chars.begin(), vector_with_chars.end(), 'z'));
    
    // Print it
    print_chars_from_vector(vector_with_chars);
    
    // Randomly remove five more letters from it
    for (int i = 0; i < 5; ++i)
    {
        int random_index = rand() % vector_with_chars.size();
        vector_with_chars.erase(vector_with_chars.begin() + random_index);
    }
    
    // Print it
    print_chars_from_vector(vector_with_chars);
    
    // Sort it
    std::sort(vector_with_chars.begin(), vector_with_chars.end());
    
    // Print it
    print_chars_from_vector(vector_with_chars);
    
    // Create a fresh vector of character pointers with nothing in it
    std::vector<char*> char_ptr_vector;
    
    // Reserve five spaces in it
    char_ptr_vector.reserve(5);
    
    // Dynamically copy the first five characters from the vector of characters and into it
    for (int i = 0; i < 5; ++i)
    {
        char my_char = vector_with_chars[i];
        char_ptr_vector.push_back(new char(my_char));
    }
    
    // Vector of pointers, print it
    print_char_from_char_ptr_vector(char_ptr_vector);
    
    // Vector of pointers, shuffle it
    std::shuffle(char_ptr_vector.begin(), char_ptr_vector.end(), g);
    
    // Vector of pointers, print it
    print_char_from_char_ptr_vector(char_ptr_vector);
    
    // Vector of pointers, re-sort it
    std::sort(char_ptr_vector.begin(), char_ptr_vector.end(), [](char* a, char* b) {
        return *a < *b;
    });
    
    // Vector of pointers, print it
    print_char_from_char_ptr_vector(char_ptr_vector);
    
    // Vector of pointers, delete all the pointers in it
    for (char* char_pointer: char_ptr_vector)
    {
        delete char_pointer;
    }
    
    // Vector of pointers, clear it
    char_ptr_vector.clear();
    
    // Vector of pointers, print it
    print_char_from_char_ptr_vector(char_ptr_vector);
    
    // Print Done it!
    std::cout << "Done it!" << std::endl;
    
    return 0;
}

void print_chars_from_vector(std::vector <char>& char_vector)
{
    for (char character: char_vector)
    {
        std::cout << character;
    }
    
    std::cout << std::endl;
    
    return;
}

void print_char_from_char_ptr_vector(std::vector<char*>& char_ptr_vector)
{
    for (char* char_ptr: char_ptr_vector)
    {
        std::cout << *char_ptr;
    }
    
    std::cout << std::endl;
    
    return;
}
