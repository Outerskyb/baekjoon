#include <iostream>
#include <string>
char**map;

int main() 
{
    std::string key;
    std::string code;

    std::cin >> key;
    std::cin >> code;
    
    const int width = key.length();
    const int height = code.length() / width;

    map = (char**)malloc(sizeof(char*)*height);
    for (int i = 0; i < height; i++) {
        map[i] = (char*)malloc(sizeof(char)*width);
        for (int j = 0; j < width; j++) {
            map[i][j] = code[i*width + j];
        }
    }

    
}