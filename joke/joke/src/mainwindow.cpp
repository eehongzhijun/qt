#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "version.h"
#include "port/portmanager.h"
#include "controller.h"

#include <QtDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* to do */
    qDebug() << SOFTWARE_NAME;
    setWindowTitle(SOFTWARE_TITLE);

    m_port = new PortManager(ui->toolBar, ui->portSetAction);
    m_controller = new Controller(&m_docPath, this, ui->toolMenu,
                                  ui->actionOpen, ui->actionSave);
    m_controller->setPortManager(m_port);

    /* 状态栏设置 */
    m_rxCntLabel = new QLabel("RX: 0Bytes", this);
    m_txCntLabel = new QLabel("TX: 0Bytes", this);
    m_portInfoLabel = new QLabel("", this);
    m_rxCntLabel->setMinimumWidth(120);
    m_txCntLabel->setMinimumWidth(120);
    m_portInfoLabel->setMinimumWidth(120);
    ui->statusbar->addWidget(m_portInfoLabel);
    ui->statusbar->addWidget(m_rxCntLabel);
    ui->statusbar->addWidget(m_txCntLabel);


    /* 在轴和滚动条之间创建连接 */
    connect(ui->portRunAction, SIGNAL(triggered()), this, SLOT(changeRunFlag()));
    connect(ui->portSwitchOnAction, SIGNAL(triggered()), this, SLOT(onPortSwitchActionTriggered()));
    connect(ui->portSwitchOffAction, SIGNAL(triggered()), this, SLOT(onPortSwitchAction2Triggered()));
    connect(ui->clearAction, SIGNAL(triggered()), this, SLOT(clear()));

    m_timer.start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_rxCntLabel;
    delete m_txCntLabel;
    delete m_portInfoLabel;
}

void MainWindow::changeRunFlag()
{
    if (m_runFlag == true) {
        m_runFlag = false;
        QIcon icon(":/SerialTool/images/start.ico");
        ui->portRunAction->setIcon(icon);
        ui->portRunAction->setText(tr("Start Tx/Rx"));
    } else {
        m_runFlag = true;
        QIcon icon(":/SerialTool/images/pause.ico");
        ui->portRunAction->setIcon(icon);
        ui->portRunAction->setText(tr("Pause Tx/Rx"));
    }
    m_controller->setEnabled(m_runFlag);
}

// 打开串口槽函数
void MainWindow::onPortSwitchActionTriggered()
{
    if (ui->portRunAction->isEnabled() == true)
    {
        // 现在需要关闭端口
        closePort();
    }
    else
    {
        // 端口关闭时打开端口
        openPort();
    }
    m_port->autoOpen(false);
}

// 打开串口槽函数
void MainWindow::onPortSwitchAction2Triggered()
{
    if (ui->portRunAction->isEnabled() == true) { // 现在需要关闭端口
//        closePort();

        QIcon icon(":/SerialTool/images/connect.ico");

        ui->portSwitchOffAction->setIcon(icon);
        ui->portSwitchOffAction->setText(tr("Auto Restart Port"));

        dispPortStatus(); // 更新端口状态显示
        m_port->autoOpen(false);

    } else { // 端口关闭时打开端口
        openPort();
          qDebug() <<  (m_port->autoOpen(true)) ;
    }
}

void MainWindow::clear()
{
    m_controller->clear();
}

// 打开端口
void MainWindow::openPort()
{
    if (m_port->open()) {
        QIcon icon(":/SerialTool/images/close.ico");
        ui->portSwitchOnAction->setIcon(icon);
        ui->portSwitchOnAction->setText(tr("Close Port"));

//        QIcon icon2(":/SerialTool/images/connectyellow.ico");
        ui->portSwitchOffAction->setIcon(icon);
        ui->portSwitchOffAction->setText(tr("Manual Restart Port"));

        ui->portRunAction->setEnabled(true);
        m_controller->setEnabled(m_runFlag);
        dispPortStatus(); // 更新端口状态显示
    }
}

void MainWindow::closePort()
{
    if (m_port->isOpen()) {
        m_port->close();
    }
    QIcon icon(":/SerialTool/images/connect.ico");
    ui->portSwitchOnAction->setIcon(icon);
    ui->portSwitchOnAction->setText(tr("Open Port"));

    QIcon icon2(":/SerialTool/images/start.ico");
    ui->portSwitchOnAction->setIcon(icon2);
    ui->portSwitchOnAction->setText(tr("Auto Restart Port"));

    ui->portRunAction->setEnabled(false);
    m_controller->setEnabled(false);
    dispPortStatus(); // 更新端口状态显示
}

// 状态栏显示端口状态
void MainWindow::dispPortStatus()
{
    bool status = false;
    QString string;
    QPalette palette;

    status = m_port->portStatus(&string);
    palette.setColor(QPalette::WindowText, status ? Qt::darkGreen : Qt::red);
    m_portInfoLabel->setText(string);
    m_portInfoLabel->setPalette(palette);

}

