#ifndef PROGRAMMODEL_H
#define PROGRAMMODEL_H

#include <QString>
#include <QObject>

#include <film-flow-core/film-flow-core_global.h>

#include "programaveragemodel.h"

// TODO esse cara herda do QObject apenas para o DTO do ui não precisar implementar todos os atributos novamente
// Mas a nivel de LIB isso não eh o ideal, ajustar depois
class FILMFLOWCORE_EXPORT ProgramModel : public QObject {
public:
    ProgramModel();
    ~ProgramModel();

    QString dsName() const;
    void setDsName( const QString& dsName );

    QString dsImageUrl() const;
    void setDsImageUrl( const QString& dsImageUrl );

    QString dsSummary() const;
    void setDsSummary( const QString& dsSummary );

    QStringList genres() const;
    void setGenres( const QStringList& genres );

    ProgramAverageModel* average() const;
    void setAverage( ProgramAverageModel* average );

private:
    ProgramAverageModel* _average;

    QString _dsName;
    QString _dsImageUrl;
    QString _dsSummary;
    QStringList _genres;
};

#endif // PROGRAMMODEL_H
