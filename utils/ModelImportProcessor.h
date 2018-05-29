//
// Created by carbone on 4/9/18.
//

#ifndef ETFG_V1_MODELIMPORTPROCESSOR_H
#define ETFG_V1_MODELIMPORTPROCESSOR_H


#include <qtcsv/reader.h>
#include "ColumnMap.h"

class ModelImportProcessor : public QtCSV::Reader::AbstractProcessor {
public:
    ModelImportProcessor(QMap<QString, ColumnMap>, bool (*callback)(const QVariantMap &columns));
    void preProcessRawLine(QString &line);
    bool processRowElements(const QStringList &columns);
    void debug();
private:
    QMap<QString, ColumnMap> mappings;
    bool (*callback)(const QVariantMap &columns);
    bool headerInitialized = false;
    bool initializeHeaders(const QStringList &columns);
};


#endif //ETFG_V1_MODELIMPORTPROCESSOR_H
