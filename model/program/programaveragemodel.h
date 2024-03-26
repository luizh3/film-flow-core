#ifndef PROGRAMAVERAGEMODEL_H
#define PROGRAMAVERAGEMODEL_H

#include <QString>
#include <QObject>

#include <film-flow-core/film-flow-core_global.h>

class FILMFLOWCORE_EXPORT ProgramAverageModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString nrRating READ nrRating CONSTANT )
public:
    ProgramAverageModel( const QString& nrRating );

    QString nrRating() const;
    void setNrRating( const QString& nrRating ) ;

private:
    QString _nrRating;
};

#endif // PROGRAMAVERAGEMODEL_H
