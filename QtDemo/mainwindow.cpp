#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardPaths>
#include <QDebug>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
 *https://doc.qt.io/qt-5/qresource-obsolete.html
 *
QResource

Detailed Description
The QResource class provides an interface for reading directly from resources.
QResource is an object that represents a set of data (and possibly children) relating to a single resource entity.
QResource gives direct access to the bytes in their raw format. In this way direct access allows reading data without
buffer copying or indirection. Indirection is often useful when interacting with the resource entity as if it is a file,
 this can be achieved with QFile. The data and children behind a QResource are normally compiled into an application/library,
 but it is also possible to load a resource at runtime. When loaded at run time the resource file will be loaded as one big
set of data and then given out in pieces via references into the resource tree.
��ϸ˵����
QResource����ʾһ��ֱ�Ӵ���Դ��ȡ�Ľӿڡ�
Qresource��һ�����󣬱�ʾ�뵥����Դʵ����ص�һ�����ݣ������������QResource��ԭʼ��ʽֱ�ӷ����ֽڡ����ַ�ʽ��ֱ�ӷ���������û�л�����������������¶�ȡ���ݡ�
������Դʵ�彻��ʱ����ӷ���ͨ�������ã��ͺ�������һ���ļ�һ���������ͨ��QFileʵ�֡�QResource��������ݺ�����ͨ�������뵽Ӧ�ó������У���Ҳ����������ʱ������Դ��
������ʱ����ʱ����Դ�ļ�����Ϊһ������ݼ��أ�Ȼ��ͨ�����÷��䵽��Դ���С�

A QResource can either be loaded with an absolute path, either treated as a file system rooted
with a / character, or in resource notation rooted with a : character. A relative resource can
also be opened which will be found in the list of paths returned by QDir::searchPaths().
QResource�ȿ��Լ��ؾ���·����Ҳ���Կ�����/�ֶ�Ϊ�����ļ�ϵͳ���������ԣ�Ϊ������Դ���š����Դ������Դ������Դ������QDir::serachPath()���ص�·���б����ҵ���

A QResource that is representing a file will have data backing it, this data can possibly be compressed,
in which case qUncompress() must be used to access the real data; this happens implicitly when accessed through a QFile.
A QResource that is representing a directory will have only children and no data.
һ�������ļ���QResource��������֧�֣������ݿ��ܱ�ѹ����������£�������qUncompress()ȥ������ʵ���ݣ���ʹ��QFile����ʱ����ʽ�����������
һ������Ŀ¼��QResourceֻ������û�����ݡ�

Dynamic Resource Loading
��̬��Դ����
A resource can be left out of an application's binary and loaded when it is needed at run-time by using the
registerResource() function. The resource file passed into registerResource() must be a binary resource as
created by rcc. Further information about binary resources can be found in The Qt Resource System documentation.
��Դ���Դ�Ӧ�ó���Ķ������ļ���ɾ����������Ҫʱ������ʱͨ��registerResource()�������ء����ݸ�registerResource()����Դ�ļ���������rcc�����Ķ������ļ���
������ڶ�������Դ����Ϣ�����Բ���Qt Resource System�ĵ���

This can often be useful when loading a large set of application icons that may change based on a setting,
or that can be edited by a user and later recreated. The resource is immediately loaded into memory, either as
a result of a single file read operation, or as a memory mapped file.
�����ش������ܸ������ø��ĵ�Ӧ�ó���ͼ�꣬�������û��༭���Ժ����´���ʱ����ͨ�������á���Դ���������ص��ڴ��У���Ϊ�����ļ���ȡ�����Ľ��������Ϊ�ڴ�ӳ���ļ���

This approach can prove to be a significant performance gain as only a single file will be loaded, and pieces of data
will be given out via the path requested in setFileName().
���ַ�ʽ��֤����һ��������������������Ϊֻ����һ���ļ���ͨ��setFileName()�����·���������ݡ�

The unregisterResource() function removes a reference to a particular file. If there are QResource objects that currently
reference resources related to the unregistered file, they will continue to be valid but the resource file itself will be
removed from the resource roots, and thus no further QResource can be created pointing into this resource data. The resource
itself will be unmapped from memory when the last QResource that points to it is destroyed.
unregisterResource()�����Ƴ�һ���ض��ļ������á������QResource����ǰ������δע���ļ���ص���Դ���������Ч��������Դ�ļ���������Դ�����Ƴ������
�����ٴ���ָ�����Դ���ݵ�QResource�������һ��ָ������QResource������ʱ����Դ�������ڴ���ȥ��ӳ�䡣


(���) Qt Resource System
*/

qDebug() << QDateTime::fromMSecsSinceEpoch(1551928492663).toString(QObject::tr("yyyy.M.d"));


showMinimized();

}

MainWindow::~MainWindow()
{
    delete ui;
}
