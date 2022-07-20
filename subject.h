#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "state.h" // StateType

/*
    * A note on InfoType and StateType:
    *
    *   We have separated the collection of fields into two parts:  its Info
    *   and its State.
    * 
    *   Info is for the parts of the subjject inherent to what it is:  its position
    *   and its colour.
    * 
    *   State is for the parts of the subject that, when changed, trigger
    *   notifications.  This is the information that the Observer "gets" when it
    *   calls getState on the subject.  It comprises the type of state, a direction,
    *   and a colour.  For more details, see state.h.
*/

// DO NOT MODIFY THIS FILE!

class Observer;
struct Info; // forward declaration
class Subject
{
    std::vector<Observer *> observers;
    State state;

protected:
    void setState(State newS);

public:
    virtual Info getInfo() = 0;
    int getLen() const; // returns the number of observers.  Used for testing.
    void attach(Observer *o);
    void notifyObservers();
    State getState() const;
};

#endif