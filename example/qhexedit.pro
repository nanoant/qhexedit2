greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS = \
    mainwindow.h \
    optionsdialog.h \
    ../src/qhexedit.h \
    ../src/chunks.h \
    ../src/commands.h \
    searchdialog.h


SOURCES = \
    main.cpp \
    mainwindow.cpp \
    optionsdialog.cpp \
    ../src/qhexedit.cpp \
    ../src/chunks.cpp \
    ../src/commands.cpp \
    searchdialog.cpp

RESOURCES = \
    qhexedit.qrc

FORMS += \
    optionsdialog.ui \
    searchdialog.ui

OTHER_FILES += \
    ../build-example.bat \
    ../build-python-bindings.bat \
    ../build-example.sh \
    ../build-python-bindings.sh \
    ../deploy.nsi \
    ../doc/release.txt \
    ../doc/howtorelease.txt \
    ../appveyor.yml \
    ../readme.md \
    ../setup.py \
    ../src/qhexedit.sip

TRANSLATIONS += \
    translations/qhexedit_cs.ts \
    translations/qhexedit_de.ts

DEFINES += QHEXEDIT_EXPORTS

macx {
    QMAKE_APPLICATION_BUNDLE_NAME = QHexEdit
    ICON = images/QHexEdit.icns
    QMAKE_POST_LINK += plutil -replace CFBundleName -string QHexEdit QHexEdit.app/Contents/Info.plist;
    QMAKE_POST_LINK += plutil -replace CFBundleDocumentTypes -json '\'[{\"CFBundleTypeExtensions\":[\"bin\"],\"CFBundleTypeRole\":\"Editor\"}]\'' QHexEdit.app/Contents/Info.plist;
}
