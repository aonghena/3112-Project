//
// Created by Dawson Heide on 11/14/19.
//


#ifndef TODOS_URGENTTASK_H
#define TODOS_URGENTTASK_H

#include <string>
#include "Task.h"

using namespace std;

class UrgentTask: public Task {

private:

    int priority;

public:

    UrgentTask(const string &title, const string &description, int userId, int priority)
        : Task(title, description, userId) {
        this->priority = priority;
    }

    UrgentTask(int id, const string &title, const string &description, int userId, int completed, int priority)
            : Task(title, description, userId) {
        this->priority = priority;
        this->id = id;
        this->completed = completed;
    }

    int getPriority() const {
        return this->priority;
    }

    void setPriority(int priority) {
        this->priority = priority;
    }

    void save(Database *database) override {
        if(this->id == 0) {
            this->id = database->createTask(this->title, this->description, this->user_id, this->priority);
        } else {
            database->updateTask(this->id, this->title, this->description, this->completed, this->priority);
        }
    }

};


#endif //TODOS_URGENTTASK_H
