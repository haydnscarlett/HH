//
// Created by haydn on 26/10/2018.
//

#pragma once
#include <string>
#ifndef BASICREB0RN_VERBS_H
#define BASICREB0RN_VERBS_H


class Verbs {
public:
    std::string getVerb();
    void setVerb(std::string newVerb);

private:
    std::string verb;
};


#endif //BASICREB0RN_VERBS_H
