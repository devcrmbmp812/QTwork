#ifndef MDCONSTITUENTSTAGEOBJECT_H
#define MDCONSTITUENTSTAGEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT MdConstituentStageObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString date;
    QString constituent_ticker;
    QString coupon;
    QString cusip;
    QString isin;
    QString sedol;
    QString bbgid;
    QString ric;
    QString industry;
    QString subindustry;
    QString industry_group;
    QString sector;
    QString weight;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision {0};

    enum PropertyIndex {
        Id = 0,
        Date,
        ConstituentTicker,
        Coupon,
        Cusip,
        Isin,
        Sedol,
        Bbgid,
        Ric,
        Industry,
        Subindustry,
        IndustryGroup,
        Sector,
        Weight,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QLatin1String("md_constituent_stage"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString date READ getdate WRITE setdate)
    T_DEFINE_PROPERTY(QString, date)
    Q_PROPERTY(QString constituent_ticker READ getconstituent_ticker WRITE setconstituent_ticker)
    T_DEFINE_PROPERTY(QString, constituent_ticker)
    Q_PROPERTY(QString coupon READ getcoupon WRITE setcoupon)
    T_DEFINE_PROPERTY(QString, coupon)
    Q_PROPERTY(QString cusip READ getcusip WRITE setcusip)
    T_DEFINE_PROPERTY(QString, cusip)
    Q_PROPERTY(QString isin READ getisin WRITE setisin)
    T_DEFINE_PROPERTY(QString, isin)
    Q_PROPERTY(QString sedol READ getsedol WRITE setsedol)
    T_DEFINE_PROPERTY(QString, sedol)
    Q_PROPERTY(QString bbgid READ getbbgid WRITE setbbgid)
    T_DEFINE_PROPERTY(QString, bbgid)
    Q_PROPERTY(QString ric READ getric WRITE setric)
    T_DEFINE_PROPERTY(QString, ric)
    Q_PROPERTY(QString industry READ getindustry WRITE setindustry)
    T_DEFINE_PROPERTY(QString, industry)
    Q_PROPERTY(QString subindustry READ getsubindustry WRITE setsubindustry)
    T_DEFINE_PROPERTY(QString, subindustry)
    Q_PROPERTY(QString industry_group READ getindustry_group WRITE setindustry_group)
    T_DEFINE_PROPERTY(QString, industry_group)
    Q_PROPERTY(QString sector READ getsector WRITE setsector)
    T_DEFINE_PROPERTY(QString, sector)
    Q_PROPERTY(QString weight READ getweight WRITE setweight)
    T_DEFINE_PROPERTY(QString, weight)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // MDCONSTITUENTSTAGEOBJECT_H
