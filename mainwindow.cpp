#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    textEditor = new QPlainTextEdit(centralWidget);
    layout->addWidget(textEditor);
    setCentralWidget(centralWidget);

    textEditor->setObjectName("textEditor");

    createActions();
    createMenuBar();
    createToolBar();
    createStatusBar();
    setupConnections();

    setWindowTitle("QuickPad - Текстовий редактор");
    resize(900, 600);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    actionNew = new QAction("&New", this);
    actionNew->setShortcut(QKeySequence::New);
    actionNew->setStatusTip("Create a new document");
    actionNew->setObjectName("actionNew");

    actionOpen = new QAction("&Open...", this);
    actionOpen->setShortcut(QKeySequence::Open);
    actionOpen->setStatusTip("Open an existing file");
    actionOpen->setObjectName("actionOpen");

    actionSave = new QAction("&Save", this);
    actionSave->setShortcut(QKeySequence::Save);
    actionSave->setStatusTip("Save the current document");
    actionSave->setObjectName("actionSave");

    actionSaveAs = new QAction("Save &As...", this);
    actionSaveAs->setShortcut(QKeySequence::SaveAs);
    actionSaveAs->setStatusTip("Save the document with a new name");
    actionSaveAs->setObjectName("actionSaveAs");

    actionExit = new QAction("E&xit", this);
    actionExit->setShortcut(QKeySequence::Quit);
    actionExit->setStatusTip("Exit the application");
    actionExit->setObjectName("actionExit");

    actionCut = new QAction("Cu&t", this);
    actionCut->setShortcut(QKeySequence::Cut);
    actionCut->setStatusTip("Cut the selected text");
    actionCut->setObjectName("actionCut");

    actionCopy = new QAction("&Copy", this);
    actionCopy->setShortcut(QKeySequence::Copy);
    actionCopy->setStatusTip("Copy the selected text");
    actionCopy->setObjectName("actionCopy");

    actionPaste = new QAction("&Paste", this);
    actionPaste->setShortcut(QKeySequence::Paste);
    actionPaste->setStatusTip("Paste text from clipboard");
    actionPaste->setObjectName("actionPaste");

    actionSelectAll = new QAction("Select &All", this);
    actionSelectAll->setShortcut(QKeySequence::SelectAll);
    actionSelectAll->setStatusTip("Select all text");
    actionSelectAll->setObjectName("actionSelectAll");

    actionAbout = new QAction("&About", this);
    actionAbout->setStatusTip("Show information about QuickPad");
    actionAbout->setObjectName("actionAbout");
}

void MainWindow::createMenuBar()
{
    QMenuBar *menuBar = this->menuBar();

    QMenu *fileMenu = menuBar->addMenu("&File");
    fileMenu->addAction(actionNew);
    fileMenu->addAction(actionOpen);
    fileMenu->addAction(actionSave);
    fileMenu->addAction(actionSaveAs);
    fileMenu->addSeparator();
    fileMenu->addAction(actionExit);

    QMenu *editMenu = menuBar->addMenu("&Edit");
    editMenu->addAction(actionCut);
    editMenu->addAction(actionCopy);
    editMenu->addAction(actionPaste);
    editMenu->addSeparator();
    editMenu->addAction(actionSelectAll);

    QMenu *helpMenu = menuBar->addMenu("&Help");
    helpMenu->addAction(actionAbout);
}

void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar("Main Toolbar");
    toolBar->setObjectName("mainToolBar");

    toolBar->addAction(actionNew);
    toolBar->addAction(actionOpen);
    toolBar->addAction(actionSave);
    toolBar->addSeparator();
    toolBar->addAction(actionCut);
    toolBar->addAction(actionCopy);
    toolBar->addAction(actionPaste);
    toolBar->setMovable(true);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage("Ready", 2000);
    statusBar()->setObjectName("statusBar");
}

void MainWindow::setupConnections()
{
    connect(actionNew, &QAction::triggered, this, &MainWindow::onNewDocument);
    connect(actionOpen, &QAction::triggered, this, &MainWindow::onOpen);
    connect(actionSave, &QAction::triggered, this, &MainWindow::onSave);
    connect(actionSaveAs, &QAction::triggered, this, &MainWindow::onSaveAs);
    connect(actionExit, &QAction::triggered, this, &MainWindow::onExit);
    connect(actionCut, &QAction::triggered, this, &MainWindow::onCut);
    connect(actionCopy, &QAction::triggered, this, &MainWindow::onCopy);
    connect(actionPaste, &QAction::triggered, this, &MainWindow::onPaste);
    connect(actionSelectAll, &QAction::triggered, this, &MainWindow::onSelectAll);
    connect(actionAbout, &QAction::triggered, this, &MainWindow::onAbout);
}

void MainWindow::onNewDocument()
{
    bool ok;
    QString docName = QInputDialog::getText(this, "New Document",
                                            "Document name:",
                                            QLineEdit::Normal,
                                            "Untitled",
                                            &ok);

    if (ok && !docName.trimmed().isEmpty()) {
        textEditor->clear();
        statusBar()->showMessage(QString("Created new document: %1").arg(docName), 3000);
    } else if (ok && docName.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Document name cannot be empty!");
    }
}

void MainWindow::onOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open File",
                                                    "",
                                                    "Text Files (*.txt);;All Files (*)");

    if (!fileName.isEmpty()) {
        statusBar()->showMessage(QString("Opening file: %1").arg(fileName), 3000);
    }
}

void MainWindow::onSave()
{
    if (textEditor->toPlainText().isEmpty()) {
        QMessageBox::information(this, "Save", "Nothing to save!");
        return;
    }
    statusBar()->showMessage("Document saved (demo)", 2000);
}

void MainWindow::onSaveAs()
{
    if (textEditor->toPlainText().isEmpty()) {
        QMessageBox::information(this, "Save As", "Nothing to save!");
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Save File As",
                                                    "",
                                                    "Text Files (*.txt);;All Files (*)");

    if (!fileName.isEmpty()) {
        statusBar()->showMessage(QString("Saving to: %1").arg(fileName), 3000);
    }
}

void MainWindow::onExit()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                              "Exit",
                                                              "Are you sure you want to exit?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        close();
    }
}

void MainWindow::onCut()
{
    textEditor->cut();
    statusBar()->showMessage("Text cut", 1000);
}

void MainWindow::onCopy()
{
    textEditor->copy();
    statusBar()->showMessage("Text copied", 1000);
}

void MainWindow::onPaste()
{
    textEditor->paste();
    statusBar()->showMessage("Text pasted", 1000);
}

void MainWindow::onSelectAll()
{
    textEditor->selectAll();
    statusBar()->showMessage("All text selected", 1000);
}

void MainWindow::onAbout()
{
    QMessageBox::about(this,
                       "About QuickPad",
                       "<h2>QuickPad 1.0</h2>"
                       "<p>A simple text editor built with Qt.</p>"
                       "<p><b>Features:</b></p>"
                       "<ul>"
                       "<li>Create new documents</li>"
                       "<li>Open and save text files</li>"
                       "<li>Basic text editing operations</li>"
                       "</ul>"
                       "<p><i>Practical work #4 - UI Design</i></p>");
}
