#include "logger.h"

Logger::Logger(QObject *parent, QString fileName, QPlainTextEdit *editor) : QObject(parent) {
 m_editor = editor;
 m_showDate = true;
 if (!fileName.isEmpty()) {
  file = new QFile;
  file->setFileName(fileName);
  file->open(QIODevice::Append | QIODevice::Text);
 }
}

void Logger::write(const QString &value) {
    write(value, "INFO");
}

void Logger::writeInfo(const QString &value) {
    write(value, "INFO");
}

void Logger::writeWarn(const QString &value) {
    write(value, "WARN");
}

void Logger::writeError(const QString &value) {
    write(value, "ERROR");
}

void Logger::write(const QString &value, const QString type = "INFO") {
 QString text = value;// + "";
 if (m_showDate)
  text = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss ") + "[" + type  + "] " + text + "\n";
 QTextStream out(file);
 out.setCodec("UTF-8");
 if (file != 0) {
  out << text;
 }
 if (m_editor != 0)
  m_editor->appendPlainText(text);
}

void Logger::setShowDateTime(bool value) {
 m_showDate = value;
}

Logger::~Logger() {
 if (file != 0)
 file->close();
}
