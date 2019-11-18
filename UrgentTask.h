//
// Created by Dawson Heide on 11/14/19.
//

#include <string>
#include "Task.h"

using namespace std;

#ifndef TODOS_URGENTTASK_H
#define TODOS_URGENTTASK_H

class UrgentTask: public Task {

private:


public:

    UrgentTask(const string &title, const string &description, int userId, int priority) : Task(title, description, userId) {}

};


#endif //TODOS_URGENTTASK_H
