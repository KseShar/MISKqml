#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>

class DataSource;

class DataSourceDestroyer
{
  private:
    DataSource* p_instance;
  public:
    ~DataSourceDestroyer();
    void initialize( DataSource* p );
};

class DataSource : public QObject
{
    Q_OBJECT
private:
  static DataSource* p_instance;
  static DataSourceDestroyer destroyer;
protected:
  DataSource() { }
  DataSource( const DataSource& );
  DataSource& operator=( DataSource& );
 ~DataSource() { }
  friend class DataSourceDestroyer;
public:
  static DataSource& getInstance();
};

#endif // DATASOURCE_H


