#ifndef RANDNAME_H
#define RANDNAME_H

#include <QObject>

class RandName : public QObject
{
    Q_OBJECT
public:
    explicit RandName(QObject *parent = nullptr);

    ///
    /// \brief 产生随机-姓
    /// \return
    ///
    QString randFirstName();

    ///
    /// \brief 产生随机-名
    /// \param gender  0, 女  1， 男
    /// \return
    ///
    QString randName(int gender);

    ///
    /// \brief 产生随机的姓名
    /// \param count     产生姓名的个数
    /// \return
    ///
    //QStringList randName(int count = 10);

private:
    void loadDB();

    ///
    /// \brief 百家姓的字符串
    ///
    QString m_first_name;
    int m_first_name_len;

    ///
    /// \brief 男孩名的字符串
    ///
    QString m_boy_name;
    QStringList m_boy_name_list;
    int m_boy_name_list_len;

    ///
    /// \brief 女孩名的字符串
    ///
    QString m_gril_name;
    QStringList m_gril_name_list;
    int m_gril_name_list_len;


private:

    ///
    /// \brief 读取文件内容
    /// \param fileName
    /// \return
    ///
    QString readFile(QString fileName);

    ///
    /// \brief 打印百家姓
    ///
    void print_first_name();

    ///
    /// \brief 打印男孩名
    ///
    void print_boy_name();
    ///
    /// \brief 打印女孩名
    ///
    void print_gril_name();


signals:

public slots:
};

#endif // RANDNAME_H
