#include "mdconstituentstagecontroller.h"
#include "mdconstituentstage.h"

#include <QtCore/QDataStream>

void MdConstituentStageController::index()
{
    auto mdConstituentStageList = MdConstituentStage::getAll();
    texport(mdConstituentStageList);
    render();
}

void MdConstituentStageController::show(const QString &id)
{
    auto mdConstituentStage = MdConstituentStage::get(id.toInt());
    texport(mdConstituentStage);

    QVariantMap x = mdConstituentStage.toVariantMap();

    QMapIterator<QString, QVariant> iter(x);
    while (iter.hasNext()) {
        iter.next();
//        tDebug("iter.key: %s data: %s", iter.key().toUtf8().constData(), iter.value().toString().toUtf8().constData());
        QVariant v = iter.value();
    }
    render();
}

void MdConstituentStageController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto mdConstituentStage = httpRequest().formItems("mdConstituentStage");
        auto model = MdConstituentStage::create(mdConstituentStage);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(mdConstituentStage);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void MdConstituentStageController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = MdConstituentStage::get(id.toInt());
        if (!model.isNull()) {
            session().insert("mdConstituentStage_lockRevision", model.lockRevision());
            auto mdConstituentStage = model.toVariantMap();
            texport(mdConstituentStage);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("mdConstituentStage_lockRevision").toInt();
        auto model = MdConstituentStage::get(id.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto mdConstituentStage = httpRequest().formItems("mdConstituentStage");
        model.setProperties(mdConstituentStage);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(mdConstituentStage);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void MdConstituentStageController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto mdConstituentStage = MdConstituentStage::get(id.toInt());
    mdConstituentStage.remove();
    redirect(urla("index"));
}

void MdConstituentStageController::load() {
    tDebug("MdConstituentStageController::load");
    switch (httpRequest().method()) {
        case Tf::Get: {
            render();
            break;
        }

        case Tf::Post: {
//            tDebug("MdConstituentStageController::load POST");
            TMultipartFormData &formdata = httpRequest().multipartFormData();
            QString filename = "/home/carbone/CLionProjects/etfg_v1/uploads/ee.csv";
            bool r = formdata.renameUploadedFile("csv", filename, true);
            //QString filename = formdata.originalFileName("csv");
            if (r) {
                bool r = MdConstituentStage::load(filename);
                if (r) {
                    QString notice = "Upload completed successfully.";
                    texport(notice);
                } else {
                    QString error = "Failed to import.";
                    texport(error);
                }
            } else {
                QString error = "Failed to upload.";
                texport(error);
            }
            render();
            break;
        }

        default:
            renderErrorResponse(Tf::NotFound);
            break;
    }
}

// Don't remove below this line
T_DEFINE_CONTROLLER(MdConstituentStageController)
