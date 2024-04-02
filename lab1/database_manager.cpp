// database_manager.cpp

#include "database_manager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString &path)
    : m_path(path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(m_path);

    if (!m_db.open())
    {
        qDebug() << "Error: Failed to open database:" << m_db.lastError().text();
    }
    else
    {
        qDebug() << "Database connection established successfully.";
    }
}
