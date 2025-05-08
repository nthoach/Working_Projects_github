#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

class Warlock
{
    private:
        std:: string _name;
        std:: string _title;
        Warlock();
        Warlock(Warlock const &other);
        Warlock & operator=(Warlock const &other);

    public:
        Warlock(str const &name, str const &title);
        ~Warlock();

        const str  & getName()  const;
        const str  & getTitle() const;
        void setTitle(const str &title);
        void introduce() const;
            
};

# endif