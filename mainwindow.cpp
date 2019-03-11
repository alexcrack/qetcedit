#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "consts.h"
#include "aboutdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    settings(new QSettings())
{
    ui->setupUi(this);

    setupWindow();
    setupEditor();
    setupHosts();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete highlighter;
    delete hostsMapper;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveWindow();

    event->accept();
}

void MainWindow::setupWindow()
{
    setWindowTitle(QString("%1 - v%2").arg(APP_NAME).arg(APP_VERSION));

    settings->beginGroup("MainWindow");
    resize(settings->value("size", QSize(1000, 500)).toSize());
    move(settings->value("pos", QPoint(10, 10)).toPoint());
    ui->splitter->restoreState(settings->value("splitter").toByteArray());
    settings->endGroup();
}

void MainWindow::saveWindow()
{
    settings->beginGroup("MainWindow");
    settings->setValue("size", this->size());
    settings->setValue("pos", this->pos());
    settings->setValue("splitter", ui->splitter->saveState());
    settings->endGroup();
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    ui->textEdit->setFont(font);
    highlighter = new Highlighter(ui->textEdit->document());
}

void MainWindow::setupHosts()
{
    model = new HostsListModel(this);
    hostsMapper = new QDataWidgetMapper(this);

    ui->hostGroupsListView->setModel(model);

    hostsMapper->setModel(model);
    hostsMapper->addMapping(ui->textEdit, HostsListItem::Field::Hosts, "plainText");
    hostsMapper->toFirst();

    connect(ui->hostGroupsListView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::hostsSelectionChanged);

//    ui->hostGroupsListView->selectionModel()->select();
}

void MainWindow::hostsSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndex index = ui->hostGroupsListView->selectionModel()->currentIndex();
    hostsMapper->setCurrentModelIndex(index);
}

void MainWindow::on_action_Save_triggered()
{
    model->save();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_action_About_triggered()
{
    AboutDialog *about = new AboutDialog(this);

    about->show();
}
