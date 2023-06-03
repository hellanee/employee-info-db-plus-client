#include "basecombomodel.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

namespace
{
enum Columns
{
Id,
Data,
};
}

BaseComboModel::BaseComboModel( const QString& visualColumn, const QString& queryTail, const QString &idobj, QObject *parent) :
QSqlQueryModel( parent )
{
QSqlQuery query;
query.prepare( QString( "SELECT %1.%2, %3 FROM %4" ).arg( queryTail.split( ' ' ).first() ).arg(idobj).arg( visualColumn ).arg( queryTail ) );

query.exec();
QSqlQueryModel::setQuery( query );
}

QVariant BaseComboModel::dataFromParent( QModelIndex index, int column ) const
{
return QSqlQueryModel::data( QSqlQueryModel::index( index.row() // "- 1" because make first row empty
, column ) );
}

int BaseComboModel::rowCount(const QModelIndex &parent) const
{
return QSqlQueryModel::rowCount( parent ) ; // Add info about first empty row
}

QVariant BaseComboModel::data(const QModelIndex & item, int role /* = Qt::DisplayRole */) const
{
QVariant result;


switch( role )
{
case Qt::UserRole:
result = dataFromParent( item, Id );
break;
case Qt::DisplayRole:
result = dataFromParent( item, Data );
break;
default:
break;
}


return result;
}
