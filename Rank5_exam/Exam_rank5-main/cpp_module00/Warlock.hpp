#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

using std::cout;
typedef std::string str;

class Warlock {
    str name;
    str title;

    Warlock(Warlock const &copy);
    Warlock &operator=(Warlock const &copy);
public:
    Warlock(str const &Name, str const &Title);
    ~Warlock();

    str const &getName() const;
    str const &getTitle() const;
    void setTitle(str const &Title);

    void introduce() const;
};

#endif
