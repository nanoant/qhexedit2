#include <QApplication>
#include <QIcon>
#include <QFileOpenEvent>

#include "mainwindow.h"

class Application : public QApplication
{
public:
    Application(int &argc, char **argv) : QApplication(argc, argv) {}

    bool event(QEvent *event) override
    {
        if (event->type() == QEvent::FileOpen)
        {
            QFileOpenEvent *openEvent = static_cast<QFileOpenEvent *>(event);
            MainWindow *mainWindow = getMainWindow();
            if (mainWindow != nullptr)
                mainWindow->loadFile(openEvent->file());
        }
        return QApplication::event(event);
    }

private:
    MainWindow *getMainWindow()
    {
        foreach (QWidget *w, qApp->topLevelWidgets())
            if (MainWindow* mainWin = qobject_cast<MainWindow*>(w))
                return mainWin;
        return nullptr;
    }
};

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(qhexedit);
    Application app(argc, argv);
    app.setApplicationName("QHexEdit");
    app.setOrganizationName("QHexEdit");
#ifndef Q_OS_MACOS
    app.setWindowIcon(QIcon(":images/qhexedit.ico"));
#endif

    // Identify locale and load translation if available
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qhexedit_") + locale);
    app.installTranslator(&translator);

    QCommandLineParser parser;
    parser.addPositionalArgument("file", "File to open");
    parser.addHelpOption();
    parser.process(app);
    MainWindow *mainWin = new MainWindow;
    if(!parser.positionalArguments().isEmpty())
        mainWin->loadFile(parser.positionalArguments().at(0));
    mainWin->show();

    return app.exec();
}
