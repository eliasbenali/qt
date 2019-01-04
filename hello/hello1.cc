#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QTextStream>

int main(int argc, char **argv) {
	QCoreApplication app(argc, argv);

	QString message("Hello, World!\n");

	QFile file(QDir::current().absoluteFilePath("out.txt"));
	if (!file.open(QIODevice::WriteOnly)) {
		qWarning() << "Can not open file with write access";
		return -1;
	}

	QTextStream stream(&file);
	stream << message;

	// app.exec()
	return 0;
}
