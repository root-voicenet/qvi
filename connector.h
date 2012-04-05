#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <xmlrpc/client.h>
#include <QString>
#include <QMap>
#include "pointermodel.h"

class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(const QString &url, QObject *parent = 0);
    ~Connector();

    void Login(const QString& username, const QString& password);

    PointerModel& getPointers() { return m_pointers; }
private:
    //To allow to return pointers to signals
    typedef void (Connector::*Signal)();

    void connectService();
    void addRequest(int requestID, const QString& method);
    void sendPostRequest(const QString& method);
    Signal parseReplyData(const QString& method, QVariant *resp);

    xmlrpc::Client m_client;
    bool m_isLogged;
    bool m_isConnected;
    QMap<int, QString> m_requests;
    PointerModel m_pointers;
    QMutex requestListMutex;

    // methods
    static const QString METHOD_SYSTEM_CONNECT;
    static const QString METHOD_USER_LOGOUT;
    static const QString METHOD_USER_LOGIN;
    static const QString METHOD_USER_CREATE;
    static const QString METHOD_FILE_SAVE;
    static const QString METHOD_TAXONOMY_GETTREE;


signals:
    /* Indicates user logged in and a session was received - ie successful log in */
    void logInFinished();

    /* Idicates that taxonomy tree is loaded */
    void pointersLoaded();

    /* Indicates photo upload request was sent and a reply received.
        For status check use isPhotoUploadSuccessful() */
    void photoUploadFinished();


public slots:
    void processResponse(int id, QVariant responce);
    void failed( int requestId, int faultCode, QString faultString );
};

#endif // CONNECTOR_H
