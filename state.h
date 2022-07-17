#ifndef STATE_H
#define STATE_H

/* State types are:
    EstMono -- The card has established that they are a monopoly, and request 
            all it's partners to toggle accordingly. This would be done using 
            an algorithm which would be discussed below. 

    DisMono -- The card has established that they are NO longer a monopoly,
            and therefore request all it's partners to toggle accordingly.

    Reply -- I have toggled as per the requirement.

    Block -- This state will be called when we are in a monopoly
            and we have now made an improvement. "Block" implies that 
            since we made an improvement in one of our buildings in 
            our monopoly, we have now some restrictions to deal with
*/
enum class StateType { EstMono, DisMono, Reply, Block };
enum class Direction { Right, Left };

struct State {
  StateType type;  // For Monopoly
  Direction direction;  // Relative Position of the piece
  Card * owner;
};

#endif
