//
// Created by carbone on 4/9/18.
//

#ifndef ETFG_V1_MODELIMPORT_H
#define ETFG_V1_MODELIMPORT_H

class ModelImport {
private:
    QMap<QString, ColumnMap> mappings;
    bool (*callback)(const QVariantMap &columns);

public:
    ModelImport(QList<ColumnMap> list, bool (*callback)(const QVariantMap &columns));
    bool read(QString &filename);
};


#endif //ETFG_V1_MODELIMPORT_H
