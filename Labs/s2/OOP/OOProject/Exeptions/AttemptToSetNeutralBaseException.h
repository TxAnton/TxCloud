//
// Created by anton on 6/2/20.
//

#ifndef OOPROJECT_ATTEMPTTOSETNEUTRALBASEEXCEPTION_H
#define OOPROJECT_ATTEMPTTOSETNEUTRALBASEEXCEPTION_H


#include <string>
#include <ostream>

namespace sException {

    class AttemptToSetNeutralBaseException {
    public:
        AttemptToSetNeutralBaseException(const std::string &where) : where(where) {}

        friend std::ostream &operator<<(std::ostream &os, const AttemptToSetNeutralBaseException &exception) {
            os << "At:\"" + exception.where + "\" attempted to set base with neutral devotion";
            return os;
        }

    private:
        std::string where;
    };
}























using namespace sException;

#endif //OOPROJECT_ATTEMPTTOSETNEUTRALBASEEXCEPTION_H
