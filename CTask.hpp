#ifndef CTASK_HPP
#define CTASK_HPP

#include <string>

class CTask
{
public:
    CTask();
    CTask(std::string description);

    bool getStatus() const;
    void setStatus(bool status);

    std::string getDescription() const;
    void setDescription(const std::string &description);

private:
    std::string mDescription;
    bool mStatus;
};



#endif // CTASK_HPP
