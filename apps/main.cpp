#include "document.hpp"
#include <iostream>

int main() {
    JsonReader reader;

    auto documents = reader.read("data/pets.json");

    for (const auto& doc : documents) {
        std::cout << "Title: " << doc.name << '\n';
        std::cout << "Content: " << doc.content << '\n';
        std::cout << "File: " << doc.path << "\n\n";
    }

    return 0;
}