#ifndef PROGRAMREPOSITORY_H
#define PROGRAMREPOSITORY_H

#include <QMap>
#include <QString>

#include <model/program/programsearchmodel.h>

class ProgramRepository {
public:
    ProgramSearchModel* findProgramsSearch() const;
};

#endif // PROGRAMREPOSITORY_H
