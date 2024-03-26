#ifndef PROGRAMSEARCHMODEL_H
#define PROGRAMSEARCHMODEL_H

#include <QList>
#include <QString>

class ProgramSearchModel {
public:
    ProgramSearchModel();

    bool isSearchByName() const;
    void setFgSearchByName( const bool fgSearchByName );

    QList<QString> ids() const;
    void setIds(const QList<QString> &newIds);

    QList<QString> names() const;
    void setNames(const QList<QString> &newNames);

private:
    bool _fgSearchByName;

    QList<QString> _ids;
    QList<QString> _names;
};

#endif // PROGRAMSEARCHMODEL_H
