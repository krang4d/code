#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

class myDialog : public QDialog
{
    Q_OBJECT

public:
    myDialog(QWidget *per = 0);
    ~myDialog();
private:
    QLabel *lbl;
    QLineEdit *line;
    QCheckBox *cb1;
    QCheckBox *cb2;
    QPushButton *ok;
    QPushButton *close;
private slots:
    void OkClicked();
    void TextChanged(QString str);
signals:
    void Register(QString str);
    void Invers(QString str);
    void Simple(QString str);
    void RegisterAndInvers(QString str);
};

class str : public QObject
{
    Q_OBJECT
public slots:
    void Simple(QString str)
    {
        QMessageBox msg;
        msg.setText(str);
        msg.exec();
    }
    void All(QString str)
    {
        QString result = str;
        for(int i=str.size(), j=0; i>=0; i--, j++)
            result[i]=str[j];

        for(int i=result.size(); i>=0; i--)
        {
            QChar c = result[i];
            if (c.isLower())
                result[i]=c.toUpper();
            if (c.isUpper())
                result[i]=c.toLower();
        }

        QMessageBox msg;
        msg.setText(result);
        msg.exec();
    }
    void Inversia(QString str)
    {
        QString result = str;
        for(int i=str.size(), j=0; i>=0; i--, j++)
            result[i]=str[j];
        QMessageBox msg;
        msg.setText(result);
        msg.exec();

    }
    void Register(QString str)
    {
        for(int i=str.size(); i>=0; i--)
        {
            QChar c = str[i];
            if (c.isLower())
                str[i]=c.toUpper();
            if (c.isUpper())
                str[i]=c.toLower();
        }
        QMessageBox msg;
        msg.setText(str);
        msg.exec();
    }
};

#endif // DIALOG_H
