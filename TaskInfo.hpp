#ifndef TASKINFO_HPP
#define TASKINFO_HPP

#include <QString>

class TaskInfo
{
public:
    TaskInfo();
    TaskInfo(QString description);

    const QString& getDescription() const;
    void setDescription(const QString& description);

private:
    QString mDescription;
};

inline const QString& TaskInfo::getDescription() const
{
    return mDescription;
}

inline void TaskInfo::setDescription(const QString& description)
{
    mDescription = description;
}

#endif // TASKINFO_HPP
