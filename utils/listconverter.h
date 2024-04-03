#ifndef LISTCONVERTER_H
#define LISTCONVERTER_H

#include <QList>

#include <film-flow-core/film-flow-core_global.h>

template<typename First, typename Second>
class FILMFLOWCORE_EXPORT ListConverter {
public:
    static QList<Second*> toList( QList<First*> values ) {
        // static_assert( std::is_base_of<Derived,Base>::value, "O Tipo atual precisa extender da base class");

        QList<Second*> baseValues = {};

        for( Second* value : values ) {
            baseValues.append( value );
        }

        return baseValues;
    };

    static QList<First> toList( const QList<Second>& values, std::function<First( const Second value)> convertCallback) {

        QList<First> newValues = {};

        for( const Second value : values ) {
            const First newValue = convertCallback( value );
            if( newValue != nullptr ) {
                newValues.append( newValue );
            }
        }

        return newValues;
    }
};

#endif // LISTCONVERTER_H
