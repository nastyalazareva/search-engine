
#include "document.hpp"
#include <OpenXLSX.hpp>
#include <stdexcept>
#include <iostream>

std::vector<Document> ExcelReader::read(const std::filesystem::path& path) const {
    OpenXLSX::XLDocument file;
    file.open(path.string());

    auto sheet = file.workbook().worksheet(1);
    std::vector<Document> documents;

    int titleCol = -1;
    int contentCol = -1;

    // Ищем колонки по заголовкам
    for (uint16_t col = 1; col <= sheet.columnCount(); ++col) {
        std::string header = sheet.cell(1, col).value().get<std::string>();
        if (header == "title") {
            titleCol = col;
        }
        if (header == "content") {
            contentCol = col;
        }
    }

    if (titleCol == -1 || contentCol == -1) {
        throw std::runtime_error(
            "Excel file must contain title and content columns"
        );
    }

    // Читаем документы, начиная со второй строки
    for (uint32_t row = 2; row <= sheet.rowCount(); ++row) {
        Document doc;

        doc.name = sheet.cell(row, titleCol).value().get<std::string>();

        doc.content = sheet.cell(row, contentCol).value().get<std::string>();

        doc.path = path;

        documents.push_back(doc);
    }

    file.close();
    return documents;
}
