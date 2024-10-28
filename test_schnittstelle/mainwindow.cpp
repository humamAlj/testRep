#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      networkManager(new QNetworkAccessManager(this)) {
  ui->setupUi(this);

  /////***********************//////
  // QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
  // QList<QSslCertificate> caCertificates = sslConfig.caCertificates();
  // caCertificates.append(
  //     QSslCertificate::fromPath("../zertifikat/enders-pro.pem"));
  // sslConfig.setCaCertificates(caCertificates);
  // QSslConfiguration::setDefaultConfiguration(sslConfig);
  //////////************************//////////////


}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::setVisibleParameter(bool state) {}

void MainWindow::on_startBtn_clicked() {
  QString jobName = ui->jobName_line->text();
  startJenkinsJob(jobName);
}

void MainWindow::startJenkinsJob(const QString &jobName) {

  QString url = ui->URL_line->text().append("/job/%1/").arg(jobName);
  QNetworkRequest request((QUrl(url)));
  request.setRawHeader("Authorization")
 // QSslConfiguration sslConfig = request.sslConfiguration();
  //sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
  //request.setSslConfiguration(sslConfig);
    QString logInData = ui->username_line->text() + ":" +
    ui->passW_line->text();
   QByteArray authData = "Basic" + logInData.toLocal8Bit().toBase64();
   request.setRawHeader("Authorization", authData);
  QByteArray data;
  QNetworkReply *reply = networkManager->post(request, data); // QByteArray()
  qDebug() << reply->errorString() << "\n";
}

void MainWindow::getJenkinsJobStatus(const QString &jobName) {
  QString url = ui->URL_line->text().arg(jobName);
  QNetworkRequest request((QUrl(url)));
  networkManager->get(request);
}

void MainWindow::buildStatusReceived(QNetworkReply *reply) {
  //checkServerCertificate();
  qDebug() << reply->errorString() << "\n";
  if (reply->error() == QNetworkReply::NoError) {
    QByteArray response = reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
    QJsonObject jsonObj = jsonDoc.object();
    QString status = jsonObj["result"].toString();

    ui->status_lbl->setText("Build Status: " + status);
  } else {
    ui->status_lbl->setText("Error: " + reply->errorString());
  }
  reply->deleteLater();
}

void MainWindow::on_selectBtn_clicked() {
  selectedDir = QFileDialog::getExistingDirectory(this, tr("open Directory"));
  // emit dirSelected(selectedDir);
  selectedDir.append("/");
}

void MainWindow::checkServerCertificate() {
  QNetworkAccessManager *manager = new QNetworkAccessManager();
  QNetworkRequest request(QUrl("https://jenkins.enders.pro:8443"));

  // Eine einfache GET-Anfrage, um die SSL-Verbindung zu initiieren
  QNetworkReply *reply = manager->get(request);

  connect(reply, &QNetworkReply::finished, [reply]() {
    // SSL-Konfiguration und Zertifikate auslesen
    QSslConfiguration sslConfig = reply->sslConfiguration();
    QList<QSslCertificate> certificates = sslConfig.peerCertificateChain();

    if (!certificates.isEmpty()) {
      // Das Server-Zertifikat ist in der Regel das erste Zertifikat in der
      // Liste
      QSslCertificate cert = certificates.first();

      // Informationen über das Zertifikat auslesen
      QStringList issuer = cert.issuerInfo(QSslCertificate::CommonName);
      QStringList subject = cert.subjectInfo(QSslCertificate::CommonName);
      QByteArray fingerprint =
          cert.digest(QCryptographicHash::Sha256)
              .toHex(); // Fingerprint als Hex-String (SHA-256)

      qDebug() << "Zertifikat Ausgestellt von:" << issuer;
      qDebug() << "Zertifikat Ausgestellt an (Subject):" << subject;
      qDebug() << "Zertifikat Fingerprint (SHA-256):" << fingerprint;
      qDebug() << "Zertifikat gültig von:" << cert.effectiveDate();
      qDebug() << "Zertifikat gültig bis:" << cert.expiryDate();

      // Beispiel einer Überprüfung: Sicherstellen, dass der Fingerprint dem
      // erwarteten Wert entspricht
      QByteArray expectedFingerprint =
          "46ee5fded352bfe7b6b05be98c47ca2831631ee1f484"
          "bff035ed553c6f50aefe";
      expectedFingerprint.removeAt(':');
      if (fingerprint == expectedFingerprint) {
        qDebug() << "Das richtige Zertifikat wurde verwendet.";
      } else {
        qDebug() << "WARNUNG: Ein unerwartetes Zertifikat wurde verwendet!";
      }
    } else {
      qDebug() << "Kein Zertifikat gefunden!";
    }

    // Speicher freigeben
    reply->deleteLater();
  });
}
