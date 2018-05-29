#ifndef MDCONSTITUENTSTAGE_H
#define MDCONSTITUENTSTAGE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>
#include <utils/ColumnMap.h>
#include <utils/ModelImport.h>

class TModelObject;
class MdConstituentStageObject;
class QJsonArray;


class T_MODEL_EXPORT MdConstituentStage : public TAbstractModel
{
public:
    MdConstituentStage();
    MdConstituentStage(const MdConstituentStage &other);
    MdConstituentStage(const MdConstituentStageObject &object);
    ~MdConstituentStage();

    static bool load(QString &filename);
    static bool csvCallback(const QVariantMap &columns);
    static void processCSV();

    int id() const;
    QString date() const;
    void setDate(const QString &date);
    QString constituentTicker() const;
    void setConstituentTicker(const QString &constituentTicker);
    QString coupon() const;
    void setCoupon(const QString &coupon);
    QString cusip() const;
    void setCusip(const QString &cusip);
    QString isin() const;
    void setIsin(const QString &isin);
    QString sedol() const;
    void setSedol(const QString &sedol);
    QString bbgid() const;
    void setBbgid(const QString &bbgid);
    QString ric() const;
    void setRic(const QString &ric);
    QString industry() const;
    void setIndustry(const QString &industry);
    QString subindustry() const;
    void setSubindustry(const QString &subindustry);
    QString industryGroup() const;
    void setIndustryGroup(const QString &industryGroup);
    QString sector() const;
    void setSector(const QString &sector);
    QString weight() const;
    void setWeight(const QString &weight);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    MdConstituentStage &operator=(const MdConstituentStage &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static MdConstituentStage create(const QString &date, const QString &constituentTicker, const QString &coupon, const QString &cusip, const QString &isin, const QString &sedol, const QString &bbgid, const QString &ric, const QString &industry, const QString &subindustry, const QString &industryGroup, const QString &sector, const QString &weight);
    static MdConstituentStage create(const QVariantMap &values);
    static MdConstituentStage get(int id);
    static MdConstituentStage get(int id, int lockRevision);
    static int count();
    static QList<MdConstituentStage> getAll();
    static QJsonArray getAllJson();

private:
    static ModelImport* modelImport;
    QSharedDataPointer<MdConstituentStageObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const MdConstituentStage &model);
    friend QDataStream &operator>>(QDataStream &ds, MdConstituentStage &model);
};

Q_DECLARE_METATYPE(MdConstituentStage)
Q_DECLARE_METATYPE(QList<MdConstituentStage>)

#endif // MDCONSTITUENTSTAGE_H
