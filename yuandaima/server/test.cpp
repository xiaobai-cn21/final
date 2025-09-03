#include "auth.h"
#include <iostream>

int main() {
    std::string username, password, email, company, role;

    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    std::cout << "Enter email: ";
    std::getline(std::cin, email);

    std::cout << "Enter company: ";
    std::getline(std::cin, company);

    std::cout << "Enter role (admin/factory/expert/auditor): ";
    std::getline(std::cin, role);

    AuthResult regResult = registerUser(username, password, email, company, role);
    std::cout << "Register: ok=" << regResult.ok << ", error=" << regResult.error << ", userId=" << regResult.userId << std::endl;

     std::cout << "ssasdasd <<" << std::endl;
    AuthResult loginResult = authenticateUser(username, password, role);
    std::cout << "Login: ok=" << loginResult.ok << ", error=" << loginResult.error << ", userId=" << loginResult.userId << ", token=" << loginResult.token << std::endl;

    if (loginResult.ok && !loginResult.token.empty()) {
        AuthResult tokenResult = validateToken(loginResult.token);
        std::cout << "ValidateToken: ok=" << tokenResult.ok << ", error=" << tokenResult.error << ", userId=" << tokenResult.userId << ", role=" << tokenResult.role << std::endl;
    }

    return 1;
}