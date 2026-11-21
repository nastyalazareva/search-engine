
#include "document.hpp"
#include <iostream>

int main() {
    ExcelReader reader;

    auto documents = reader.read("data/pets.xlsx");

    for (const auto& doc : documents) {
        std::cout << "Title: " << doc.name << '\n';
        std::cout << "Content: " << doc.content << '\n';
        std::cout << "File: " << doc.path << "\n\n";
    }

    return 0;
}
