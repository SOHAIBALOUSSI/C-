#include "Dog.hpp"

Dog::Dog() : Animal(), brain(NULL)
{
    std::cout << "Dog's Default constuctor called\n";
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog's copy constuctor called\n";
    type = other.type;
    brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog's copy assignment operator called\n";

    if (this != &other) {
        if (brain)
            delete brain;
        type = other.type;
        brain = new Brain(*(other.brain));
    }   
    return *this;
}

Dog::~Dog()
{
    if (brain)
        delete brain;
    std::cout << "Dog's Destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Haw Haw\n";
}

Brain* Dog::getBrain()
{
    return brain;
}