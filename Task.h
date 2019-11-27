//
// Created by Dawson Heide on 11/14/19.
//


#ifndef TODOS_TASK_H
#define TODOS_TASK_H

#include <string>
#include "Database.h"

using namespace std;

class Task {

protected:

    int id;
    string title;
    string description;
    int user_id;
    int completed = 0;

public:

    Task(const string &title, const string &description, int userId) {
        this->title = title;
        this->description = description;
        this->user_id = userId;
    }

    int getId() const {
        return id;
    }

    const string &getTitle() const {
        return title;
    }

    void setTitle(const string &title) {
        Task::title = title;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &description) {
        Task::description = description;
    }

    int getUserId() const {
        return user_id;
    }

    void setUserId(int userId) {
        user_id = userId;
    }

    int isCompleted() const {
        return completed;
    }

    void complete() {
        this->completed = !this->completed;
    }

    virtual void save(Database *database) {
        cout << "Task Save" << endl;
        if(this->id == 0) {
            this->id = database->createTask(this->title, this->description, this->user_id);
        } else {
            database->updateTask(this->id, this->title, this->description, this->completed);
        }
    }



};

#endif //TODOS_TASK_H
