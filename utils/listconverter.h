#ifndef LISTCONVERTER_H
#define LISTCONVERTER_H

#include <QList>

#include <film-flow-core/film-flow-core_global.h>

template<typename Derived, typename Base>
class FILMFLOWCORE_EXPORT ListConverter {
public:
    static QList<Base*> toList( QList<Derived*> values ) {
        // static_assert( std::is_base_of<Derived,Base>::value, "O Tipo atual precisa extender da base class");

        QList<Base*> bases = {};

        for( Base* base : values ) {
            bases.append( base );
        }

        return bases;
    };

    static QList<Derived> toList( const QList<Base>& bases, std::function<Derived( const Base base)> convertCallback) {

        QList<Derived> deriveds = {};

        for( const Base base : bases ) {
            deriveds.append( convertCallback( base ) );
        }

        return deriveds;
    }
};

#endif // LISTCONVERTER_H
