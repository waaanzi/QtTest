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
详细说明：
QResource类提示一个直接从资源读取的接口。
Qresource是一个对象，表示与单个资源实体相关的一组数据（可能有子项）。QResource以原始格式直接访问字节。这种方式下直接访问允许在没有缓冲区拷贝或简介情况下读取数据。
当与资源实体交互时，间接放在通常很有用，就好像它是一个文件一样，这可以通过QFile实现。QResource背后的数据和子项通常被编译到应用程序或库中，但也可以在运行时加载资源。
在运行时加载时，资源文件将作为一组大数据加载，然后通过引用分配到资源树中。

A QResource can either be loaded with an absolute path, either treated as a file system rooted
with a / character, or in resource notation rooted with a : character. A relative resource can
also be opened which will be found in the list of paths returned by QDir::searchPaths().
QResource既可以加载绝对路径，也可以看做以/字段为根的文件系统，或者是以：为根的资源符号。可以打开相对资源，该资源可以在QDir::serachPath()返回的路径列表中找到。

A QResource that is representing a file will have data backing it, this data can possibly be compressed,
in which case qUncompress() must be used to access the real data; this happens implicitly when accessed through a QFile.
A QResource that is representing a directory will have only children and no data.
一个代表文件的QResource会有数据支持，该数据可能被压缩，该情况下，必须用qUncompress()去访问真实数据；在使用QFile访问时会隐式发生该情况。
一个代表目录的QResource只有子项没有数据。

Dynamic Resource Loading
动态资源加载
A resource can be left out of an application's binary and loaded when it is needed at run-time by using the
registerResource() function. The resource file passed into registerResource() must be a binary resource as
created by rcc. Further information about binary resources can be found in The Qt Resource System documentation.
资源可以从应用程序的二进制文件中删除，并被需要时在运行时通过registerResource()函数加载。传递给registerResource()的资源文件必须是由rcc创建的二进制文件。
更多关于二进制资源的信息，可以参阅Qt Resource System文档。

This can often be useful when loading a large set of application icons that may change based on a setting,
or that can be edited by a user and later recreated. The resource is immediately loaded into memory, either as
a result of a single file read operation, or as a memory mapped file.
当加载大量可能根据设置更改的应用程序图标，或者由用户编辑并稍后重新创建时，这通常很有用。资源将立即加载到内存中，作为单个文件读取操作的结果或者作为内存映射文件。

This approach can prove to be a significant performance gain as only a single file will be loaded, and pieces of data
will be given out via the path requested in setFileName().
这种方式能证明是一种显著的性能提升，因为只加载一个文件，通过setFileName()请求的路径发送数据。

The unregisterResource() function removes a reference to a particular file. If there are QResource objects that currently
reference resources related to the unregistered file, they will continue to be valid but the resource file itself will be
removed from the resource roots, and thus no further QResource can be created pointing into this resource data. The resource
itself will be unmapped from memory when the last QResource that points to it is destroyed.
unregisterResource()函数移除一个特定文件的引用。如果有QResource对象当前引用与未注册文件相关的资源，会继续有效，但是资源文件本身会从资源根中移除，因此
不能再创建指向该资源数据的QResource。当最后一个指向它的QResource被销毁时，资源本身将从内存中去掉映射。


(相关) Qt Resource System
*/

qDebug() << QDateTime::fromMSecsSinceEpoch(1551928492663).toString(QObject::tr("yyyy.M.d"));


showMinimized();

}

MainWindow::~MainWindow()
{
    delete ui;
}
