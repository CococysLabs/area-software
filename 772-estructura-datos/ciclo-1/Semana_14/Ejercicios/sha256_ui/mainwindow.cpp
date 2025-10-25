#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QCryptographicHash>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Transformar_clicked()
{
    // Obtener el texto de entrada
    QString entrada = ui->entrada->text();  // Asumiendo que 'entrada' es un QLineEdit

    if (entrada.isEmpty()) {
        QMessageBox::warning(this, "Entrada vacía", "Por favor, ingrese texto para transformar.");
        return;
    }

    // Calcular el hash SHA-256
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(entrada.toUtf8());
    QString salida = hash.result().toHex();

    // Mostrar el resultado en el campo de salida
    ui->salida->setText(salida);  // Asumiendo que 'salida' es un QLineEdit
}


