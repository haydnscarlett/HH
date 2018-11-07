//
// Created by haydn on 26/10/2018.
//

#include "Verbs.h"
/**
*   @brief   Gets the Verb
*   @details This function is designed to get the Verb name as a string
*   @return  std::string
*/
std::string Verbs::getVerb()
{
    return verb;
}

/**
*   @brief   Sets the Verb
*   @details This function is designed to set the Verb name as a string
*   @return  void
*/
void Verbs::setVerb(std::string newItem)
{
    verb = newItem;
}