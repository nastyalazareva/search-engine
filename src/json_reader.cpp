#include "document.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
#include <stdexcept>

std::vector<Document> JsonReader::read(const std::filesystem::path& path) const {
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open JSON file");
    }

    nlohmann::json data;
    file >> data;

    if (!data.is_array()) {
        throw std::runtime_error("JSON must contain an array");
    }

    std::vector<Document> documents;

    for (const auto& item : data) {
        Document doc;

        doc.name = item.at("title").get<std::string>();
        doc.content = item.at("content").get<std::string>();
        doc.path = path;

        documents.push_back(doc);
    }

    return documents;
}
