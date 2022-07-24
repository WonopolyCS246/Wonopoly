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
class Ownable;
struct Info;    // forward declaration
class Property; // forward declaration

class Subject
{

    State state;

protected:
    void setState(State newS);
    std::vector<Ownable *> observers;

public:
    Subject(State s);
    virtual Info getInfo() = 0;
    int getLen() const; // returns the number of observers.  Used for testing.

    // we can't call subject::observers.info directly, so we do this.
    void attach(Property *o);

    void notifyObservers();
    State getState() const;
};

#endif