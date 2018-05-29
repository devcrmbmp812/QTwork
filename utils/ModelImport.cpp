//
// Created by carbone on 4/9/18.
//

#include "ColumnMap.h"
#include <TreeFrogModel>
#include <QtCore/QFile>
#include "ModelImport.h"
#include "ModelImportProcessor.h"

#include "qtcsv/reader.h"
#include "qtcsv/writer.h"
#include "qtcsv/stringdata.h"
#include "qtcsv/variantdata.h"

/*
 * ModelImport::ModelImport
 */
ModelImport::ModelImport(QList<ColumnMap> list, bool (*callback)(const QVariantMap &columns)) {
    foreach(ColumnMap s, list)  this->mappings[s.getKey()] = s;
    this->callback = callback;
}

bool ModelImport::read(QString &filename) {
    tDebug("ModelImport::read: %s", filename.toUtf8().constData());
    ModelImportProcessor processor(this->mappings, this->callback);

    if (!QtCSV::Reader::readToProcessor(filename, processor)) {
        tDebug("Failed to open %s", filename.toUtf8().constData());
        return false;
    }
    return true;
}
