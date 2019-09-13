#ifndef CTASK_HPP
#define CTASK_HPP

#include <QString>
#include <QDateTime>

class Task
{
public:
    Task();
    Task(QString description);

    bool getStatus() const;
    void setStatus(bool status);

    QString getDescription() const;
    void setDescription(const QString &description);

    QDateTime getDeadline() const;
    void setDeadline(const QDateTime &deadline);

private:
    QString mDescription;
    QDateTime mDeadline;
    bool mStatus;
};



#endif // CTASK_HPP
