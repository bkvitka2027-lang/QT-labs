#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNewDocument();
    void onOpen();
    void onSave();
    void onSaveAs();
    void onExit();
    void onCut();
    void onCopy();
    void onPaste();
    void onSelectAll();
    void onAbout();

private:
    QPlainTextEdit *textEditor;

    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionExit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSelectAll;
    QAction *actionAbout;

    void createActions();
    void createMenuBar();
    void createToolBar();
    void createStatusBar();
    void setupConnections();
};

#endif
