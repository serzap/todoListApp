#ifndef CTASK_HPP
#define CTASK_HPP

#include <string>
#include <QDateTime>

class Task
{
public:
    Task();
    Task(std::string description);

    bool getStatus() const;
    void setStatus(bool status);

    std::string getDescription() const;
    void setDescription(const std::string &description);

    QDateTime getDeadline() const;
    void setDeadline(const QDateTime &deadline);

private:
    std::string mDescription;
    bool mStatus;
    QDateTime mDeadline;
};



#endif // CTASK_HPP
