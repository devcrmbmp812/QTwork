#include <TreeFrogModel>
#include "mdconstituentstage.h"
#include "mdconstituentstageobject.h"
#include <ModelImport.h>
#include <ColumnMap.h>


ModelImport* MdConstituentStage::modelImport = nullptr;

MdConstituentStage::MdConstituentStage()
        : TAbstractModel(), d(new MdConstituentStageObject()) {
    d->id = 0;
    d->lock_revision = 0;
}

MdConstituentStage::MdConstituentStage(const MdConstituentStage &other)
        : TAbstractModel(), d(new MdConstituentStageObject(*other.d)) {}

MdConstituentStage::MdConstituentStage(const MdConstituentStageObject &object)
        : TAbstractModel(), d(new MdConstituentStageObject(object)) {}

MdConstituentStage::~MdConstituentStage() {
    // If the reference count becomes 0,
    // the shared data object 'MdConstituentStageObject' is deleted.
}

bool MdConstituentStage::load(QString &filename) {
    tDebug("MdConstituentStage::load");
    if (!modelImport) {
        QList<ColumnMap> list({
              {"bbgid",             ColumnType::string,  {"BBGID"}},
              {"constituentTicker", ColumnType::string,  {"ConstituentTicker"}},
              {"coupon",            ColumnType::string,  {"Coupon"}},
              {"cusip",             ColumnType::cusip,   {"CUSIP", "SEDOL", "Identifier", "ISIN", "ConstituentTicker"}},
              {"date",              ColumnType::string,  {"Date"}},
              {"industry",          ColumnType::string,  {"NAICSIndustry", "Industry", "GICSIndustry", "BBIndustry"}},
              {"industryGroup",     ColumnType::string,  {"IndustryGroup", "GICSIndustryGroup", "BloombergIndustryGroup"}},
              {"isin",              ColumnType::isin,    {"CUSIP", "SEDOL", "Identifier", "ISIN", "ConstituentTicker"}},
              {"ric",               ColumnType::string,  {"ReutersTicker", "ReuterTicker", "RIC"}},
              {"sector",            ColumnType::string,  {"Sector", "NAICSSector"}},
              {"sedol",             ColumnType::sedol,   {"CUSIP", "SEDOL", "Identifier", "ISIN", "ConstituentTicker"}},
              {"subindustry",       ColumnType::string,  {"SubIndustry", "NAICSSubIndustry"}},
              {"weight",            ColumnType::numeric, {"Weighting", "PerCent"}}
        });
        modelImport = new ModelImport(list, &MdConstituentStage::csvCallback);
    }
    modelImport->read(filename);
    return true;
}

bool MdConstituentStage::csvCallback(const QVariantMap &qVariantMap) {
    tDebug("MdConstituentStage::csvCallback");
    MdConstituentStage model;
    model.setProperties(qVariantMap);
    return model.d->create();
}

int MdConstituentStage::id() const {
    return d->id;
}

QString MdConstituentStage::date() const {
    return d->date;
}

void MdConstituentStage::setDate(const QString &date) {
    d->date = date;
}

QString MdConstituentStage::constituentTicker() const {
    return d->constituent_ticker;
}

void MdConstituentStage::setConstituentTicker(const QString &constituentTicker) {
    d->constituent_ticker = constituentTicker;
}

QString MdConstituentStage::coupon() const {
    return d->coupon;
}

void MdConstituentStage::setCoupon(const QString &coupon) {
    d->coupon = coupon;
}

QString MdConstituentStage::cusip() const {
    return d->cusip;
}

void MdConstituentStage::setCusip(const QString &cusip) {
    d->cusip = cusip;
}

QString MdConstituentStage::isin() const {
    return d->isin;
}

void MdConstituentStage::setIsin(const QString &isin) {
    d->isin = isin;
}

QString MdConstituentStage::sedol() const {
    return d->sedol;
}

void MdConstituentStage::setSedol(const QString &sedol) {
    d->sedol = sedol;
}

QString MdConstituentStage::bbgid() const {
    return d->bbgid;
}

void MdConstituentStage::setBbgid(const QString &bbgid) {
    d->bbgid = bbgid;
}

QString MdConstituentStage::ric() const {
    return d->ric;
}

void MdConstituentStage::setRic(const QString &ric) {
    d->ric = ric;
}

QString MdConstituentStage::industry() const {
    return d->industry;
}

void MdConstituentStage::setIndustry(const QString &industry) {
    d->industry = industry;
}

QString MdConstituentStage::subindustry() const {
    return d->subindustry;
}

void MdConstituentStage::setSubindustry(const QString &subindustry) {
    d->subindustry = subindustry;
}

QString MdConstituentStage::industryGroup() const {
    return d->industry_group;
}

void MdConstituentStage::setIndustryGroup(const QString &industryGroup) {
    d->industry_group = industryGroup;
}

QString MdConstituentStage::sector() const {
    return d->sector;
}

void MdConstituentStage::setSector(const QString &sector) {
    d->sector = sector;
}

QString MdConstituentStage::weight() const {
    return d->weight;
}

void MdConstituentStage::setWeight(const QString &weight) {
    d->weight = weight;
}

QDateTime MdConstituentStage::createdAt() const {
    return d->created_at;
}

QDateTime MdConstituentStage::updatedAt() const {
    return d->updated_at;
}

int MdConstituentStage::lockRevision() const {
    return d->lock_revision;
}

MdConstituentStage &MdConstituentStage::operator=(const MdConstituentStage &other) {
    d = other.d;  // increments the reference count of the data
    return *this;
}

MdConstituentStage
MdConstituentStage::create(const QString &date, const QString &constituentTicker, const QString &coupon,
                           const QString &cusip, const QString &isin, const QString &sedol, const QString &bbgid,
                           const QString &ric, const QString &industry, const QString &subindustry,
                           const QString &industryGroup, const QString &sector, const QString &weight) {
    MdConstituentStageObject obj;
    obj.date = date;
    obj.constituent_ticker = constituentTicker;
    obj.coupon = coupon;
    obj.cusip = cusip;
    obj.isin = isin;
    obj.sedol = sedol;
    obj.bbgid = bbgid;
    obj.ric = ric;
    obj.industry = industry;
    obj.subindustry = subindustry;
    obj.industry_group = industryGroup;
    obj.sector = sector;
    obj.weight = weight;
    if (!obj.create()) {
        return MdConstituentStage();
    }
    return MdConstituentStage(obj);
}

MdConstituentStage MdConstituentStage::create(const QVariantMap &values) {
    MdConstituentStage model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

MdConstituentStage MdConstituentStage::get(int id) {
    TSqlORMapper<MdConstituentStageObject> mapper;
    return MdConstituentStage(mapper.findByPrimaryKey(id));
}

MdConstituentStage MdConstituentStage::get(int id, int lockRevision) {
    TSqlORMapper<MdConstituentStageObject> mapper;
    TCriteria cri;
    cri.add(MdConstituentStageObject::Id, id);
    cri.add(MdConstituentStageObject::LockRevision, lockRevision);
    return MdConstituentStage(mapper.findFirst(cri));
}

int MdConstituentStage::count() {
    TSqlORMapper<MdConstituentStageObject> mapper;
    return mapper.findCount();
}

QList<MdConstituentStage> MdConstituentStage::getAll() {
    return tfGetModelListByCriteria<MdConstituentStage, MdConstituentStageObject>(TCriteria());
}

QJsonArray MdConstituentStage::getAllJson() {
    QJsonArray array;
    TSqlORMapper<MdConstituentStageObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<MdConstituentStageObject> i(mapper); i.hasNext();) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(MdConstituentStage(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *MdConstituentStage::modelData() {
    return d.data();
}

const TModelObject *MdConstituentStage::modelData() const {
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const MdConstituentStage &model) {
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MdConstituentStage &model) {
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(MdConstituentStage)
