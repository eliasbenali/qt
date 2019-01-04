#include <QtCore>
#include <QtGui>
#include <QtWidgets>

class MainWindow: public QMainWindow {
	private:
		QPushButton *m_button;
	public:
		MainWindow(QWidget *parent=nullptr): QMainWindow(parent) {
			m_button = new QPushButton("Store Content", this);
			setCentralWidget(m_button);
			connect(m_button, &QPushButton::clicked, this,
					&MainWindow::storeContent);
		}

		~MainWindow() {
		}
	public slots:
		void storeContent() {
			qDebug() << "Storing content...";
			QString message("Hello, World!\n");
			QFile file(QDir::current().absoluteFilePath("out.txt"));
			if (!file.open(QIODevice::WriteOnly))
				qWarning() << "Can not open file with write access";
			QTextStream stream(&file);
			stream << message;
		}
};

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	::MainWindow win;
	win.resize(320, 240);
	win.setVisible(true);

	return app.exec();
}
