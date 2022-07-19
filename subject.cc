#include <iostream>
#include <vector>
#include <string>
#include "subject.h"
#include "observer.h"
// protected:
//     void setState(State newS);

// public:
//     void attach(Observer *o);
//     void notifyObservers();
//     State getState() const;

void Subject::setState(State newS)
{
    state = newS; // set the state to the new state
}

void Subject::attach(Observer *o)
{
    observers.push_back(o); // add the observer to the vector
}

void Subject::notifyObservers()
{
    for (int i = 0; i < observers.size(); i++)
    {
        observers[i]->notify(*this); // call the notify method on each observer
    }
}

State Subject::getState() const
{
    return state;
}
