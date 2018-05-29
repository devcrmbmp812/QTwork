//
// Created by carbone on 4/9/18.
//

#include <TGlobal>
#include "ModelImportProcessor.h"

//ModelImportProcessor::ModelImportProcessor() {
//    tDebug("ModelImportProcessor::ModelImportProcessor");
//}

ModelImportProcessor::ModelImportProcessor(QMap<QString, ColumnMap> mappings,
                                           bool (*callback)(const QVariantMap &columns)) {
//    tDebug("ModelImportProcessor::ModelImportProcessor");
    this->mappings = mappings;
    this->callback = callback;
}

void ModelImportProcessor::preProcessRawLine(QString &line) {
//    tDebug("ModelImportProcessor::preProcessRawLine");
//    tDebug("Line: %s", line.toUtf8().constData());
}

bool ModelImportProcessor::processRowElements(const QStringList &columns) {
    tDebug("ModelImportProcessor::processRowElements");
    QVariantMap qVariantMap;

    if (!this->headerInitialized) {
        return this->initializeHeaders(columns);
    }

    for (auto key: this->mappings.keys()) {
        qVariantMap[key] =  this->mappings[key].getData(columns);
    }

    return (*this->callback)(qVariantMap);
}

bool ModelImportProcessor::initializeHeaders(const QStringList &columns) {
    tDebug("ModelImportProcessor::initializeHeaders");
    this->headerInitialized = true;

    for (int columnNum = 0; columnNum < columns.size(); ++columnNum) {
        QString header = columns.at(columnNum);
        header = header.remove(QRegExp("[^A-Za-z]"));

        for (auto key: this->mappings.keys()) {
            this->mappings[key].mapColumn(columnNum, header);
        }
    }

    return true;
}

void ModelImportProcessor::debug() {
    tDebug("ModelImportProcessor::debug");

    QMapIterator<QString, ColumnMap> iter(this->mappings);
    while (iter.hasNext()) {
        iter.next();
        tDebug("Array index: %s", iter.key().toUtf8().constData());
        ColumnMap v = iter.value();
        v.debug();
    }
}