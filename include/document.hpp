#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
struct Document{
    std::string name, content;
    std::filesystem::path path;
};
class DocumentReader {
    public:
        virtual ~DocumentReader() = default;
        virtual std::vector<Document> read(const std::filesystem::path& path) const = 0;
};
class JsonReader: public DocumentReader{
    public:
        std::vector<Document> read(const std::filesystem::path& path) const override;
};
class CSVReader: public DocumentReader{
    public:
        std::vector<Document> read(const std::filesystem::path& path) const override;
};
class ExcelReader: public DocumentReader{
    public:
        std::vector<Document> read(const std::filesystem::path& path) const override;
};