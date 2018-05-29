#ifndef MDCONSTITUENTSTAGECONTROLLER_H
#define MDCONSTITUENTSTAGECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MdConstituentStageController : public ApplicationController
{
    Q_OBJECT
public:
    MdConstituentStageController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void load();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // MDCONSTITUENTSTAGECONTROLLER_H
