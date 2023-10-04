#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str) {
    std::string cleanedStr;
    
    // remove character non-alphanumeric & change string to lower case
    for (char c : str) {
        if (std::isalnum(c)) {
            cleanedStr += std::tolower(c);
        }
    }
    
    std::string reversedStr = cleanedStr;
    std::reverse(reversedStr.begin(), reversedStr.end());
    
    return cleanedStr == reversedStr;
}

int main() {
    std::string inputStr = "civic"; // change input
    
    if (isPalindrome(inputStr)) {
        std::cout << inputStr << " is palindrome." << std::endl;
    } else {
        std::cout << inputStr << " not palindrome." << std::endl;
    }
    
    return 0;
}
