#include "glow432.h"
#include "ui_glow432.h"
#include "floatingbutton.h"
#include <QIcon>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QShortcut>
#include <QKeySequence>

Glow432::Glow432(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Glow432)
{
    ui->setupUi(this);

    // Setează icoana aplicației
    QIcon appIcon(":/icon.ico");
    setWindowIcon(appIcon);

    // Opacitate 0 pentru a fi invizibilă dar prezentă în taskbar
    this->setWindowOpacity(0);
    this->show();

    // Floating button
    FloatingButton *floatingButton = new FloatingButton(this);
    floatingButton->show();

    // Creează system tray icon
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(appIcon);

    // Meniu contextual pentru tray
    trayMenu = new QMenu(this);
    QAction *quitAction = new QAction("Ieșire", this);
    connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);
    trayMenu->addAction(quitAction);

    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();

    // Shortcut global: Ctrl+Q pentru închidere
    QShortcut *quitShortcut = new QShortcut(QKeySequence("Ctrl+Q"), this);
    connect(quitShortcut, &QShortcut::activated, qApp, &QApplication::quit);
}

Glow432::~Glow432()
{
    delete ui;
}
