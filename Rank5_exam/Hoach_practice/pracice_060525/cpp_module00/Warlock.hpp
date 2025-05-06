#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

typedef std::string str;


class Warlock
{
    private:
        str _name;
        str _title;

        Warlock();
        Warlock(Warlock& other);
        Warlock& operator=(Warlock& other);

    public:
        Warlock(str name, str title);
        ~Warlock();

        str const& getName() const;
        str const& getTitle() const;

        void setTitle(str const& title);
        void introduce() const; 
};

#endif
