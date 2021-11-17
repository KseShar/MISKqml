#include "datasource.h"

/*DataSource::DataSource(QObject *parent) : QObject(parent)
{

}*/

DataSource * DataSource::p_instance = 0;
DataSourceDestroyer DataSource::destroyer;

DataSourceDestroyer::~DataSourceDestroyer() {
    delete p_instance;
}
void DataSourceDestroyer::initialize( DataSource* p ) {
    p_instance = p;
}
DataSource& DataSource::getInstance() {
    if(!p_instance)     {
        p_instance = new DataSource();
        destroyer.initialize( p_instance);
    }
    return *p_instance;
}
