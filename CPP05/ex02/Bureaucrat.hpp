#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string  _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &bureaucrat);
        Bureaucrat &operator=(Bureaucrat const &bureaucrat);
        ~Bureaucrat();

        const std::string getName() const;
        int  getGrade() const;
        void incrementGrade();
        void decrementGrade();

        void signForm(AForm& form);
        void executeForm(AForm const & form);
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class  GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator << (std::ostream &out, Bureaucrat& b);

#endif