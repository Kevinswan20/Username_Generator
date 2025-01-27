#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

// Function to generate a valid username
std::string generateUsername() {
    const std::string allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
    std::string username = "";

    // Seed the random number generator
    std::srand(std::time(0));

    // Generate a 5-character username
    for (int i = 0; i < 5; ++i) {
        // Randomly pick a character from allowed_chars
        char random_char = allowed_chars[std::rand() % allowed_chars.length()];

        // Ensure that the username does not start or end with an underscore
        if (i == 0 || i == 4) {
            // Re-roll if it starts or ends with an underscore
            while (random_char == '_') {
                random_char = allowed_chars[std::rand() % allowed_chars.length()];
            }
        }

        username += random_char;
    }

    // Ensure there are no consecutive underscores
    for (int i = 1; i < username.length(); ++i) {
        if (username[i] == '_' && username[i - 1] == '_') {
            // Re-roll the character if there are consecutive underscores
            username[i] = allowed_chars[std::rand() % allowed_chars.length()];
        }
    }

    return username;
}

int main() {
    // Generate a username
    std::string username = generateUsername();
    
    // Output the generated username
    std::cout << "Generated Roblox username: " << username << std::endl;
    
    return 0;
}
