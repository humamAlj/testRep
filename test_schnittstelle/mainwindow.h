#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void getWindow(){}

signals:
  // void dirSelected(QString selectedDir);

private slots:
  void buildStatusReceived(QNetworkReply *reply);

  void on_startBtn_clicked();

  void on_selectBtn_clicked();

private:
  Ui::MainWindow *ui;
  void setVisibleParameter(bool state);
  void choose_jenkinsFile(QString pfad);
  void checkServerCertificate();

  QNetworkAccessManager *networkManager;
  void startJenkinsJob(const QString &jobName);
  void getJenkinsJobStatus(const QString &jobName);
  QString selectedDir;
};
#endif // MAINWINDOW_H
