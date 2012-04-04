#include "connector.h"
#include <QUrl>

 const QString Connector::METHOD_SYSTEM_CONNECT = "system.connect";
 const QString Connector::METHOD_USER_LOGOUT = "user.logout";
 const QString Connector::METHOD_USER_LOGIN = "user.login";
 const QString Connector::METHOD_USER_CREATE = "user.create";
 const QString Connector::METHOD_FILE_SAVE = "file.save";
 const QString Connector::METHOD_TAXONOMY_GETTREE = "taxonomy_vocabulary.getTree";



Connector::Connector(const QString& url, QObject *parent):
    QObject(parent), m_isLogged(false)
{
    QUrl weburl(url);
    m_client.setHost(weburl.host(), 80, weburl.path());
    m_client.setUserAgent("Qt"); // Если нужен

    connect(&m_client, SIGNAL(done(int, QVariant)), this, SLOT(processResponse(int, QVariant)));
    connect(&m_client, SIGNAL(failed(int, int, QString)), this, SLOT(failed(int, int, QString)));
}

Connector::~Connector()
{

}

void Connector::connectService()
{
    int requestID = m_client.request(METHOD_SYSTEM_CONNECT);
    m_requests.insert(requestID, METHOD_SYSTEM_CONNECT);
}


void Connector::Login(const QString& username, const QString& password) {
   //if(!m_isConnected)
   //    connectService();

    //int requestID = m_client.request(METHOD_USER_LOGIN, username, password);
   // m_requests.insert(requestID, METHOD_USER_LOGIN);

    getPointers();
}

void Connector::getPointers()
{
    int requestID = m_client.request(METHOD_TAXONOMY_GETTREE, 1);
    m_requests.insert(requestID, METHOD_TAXONOMY_GETTREE);
}

void Connector::processResponse(int id, QVariant responce)
{
    QMap<int, QString>::Iterator it = m_requests.find(id);
    QMap<QString , QVariant> elements(responce.toMap());


     qDebug() << "responce:" << responce;

    if(it != m_requests.end()) {
        if(it.value() == METHOD_USER_LOGIN) {
            QString cookie = elements.value("session_name").toString();
            cookie.append("=");
            cookie.append(elements.value("sessid").toString());

            m_client.setCookie(cookie);
            m_isLogged = true;

             getPointers();
            // get pointers tree
        }else if(it.value() == METHOD_SYSTEM_CONNECT) {
            m_isConnected = true;
        }else if(it.value() == METHOD_TAXONOMY_GETTREE) {

        }

        m_requests.remove(id);
    }
}

void Connector::failed(int requestId, int faultCode, QString faultString)
{
    qDebug() << "failing request " << requestId << " error:" << faultString;
    QMap<int, QString>::Iterator it = m_requests.find(requestId);

    if(it != m_requests.end()) {
         m_requests.remove(requestId);
    }
}
