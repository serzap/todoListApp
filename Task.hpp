#ifndef CTASK_HPP
#define CTASK_HPP

#include <QString>
#include <QDateTime>

class Task
{
public:
    Task();
    Task(const QString& description);

    bool getStatus() const;
    void setStatus(bool status);

    const QString& getDescription() const;
    void setDescription(const QString& description);

    const QDateTime& getDeadline() const;
    void setDeadline(const QDateTime& deadline);

private:
    static int ID;
    int mCurrentId;
    QString mDescription;
    QDateTime mDeadline;
    bool mStatus;
};

#endif // CTASK_HPP
