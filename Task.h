//
// Created by Dawson Heide on 11/14/19.
//

#include <string>

using namespace std;

#ifndef TODOS_TASK_H
#define TODOS_TASK_H

class Task {

protected:

    static int currentId;
    int id;
    string title;
    string description;
    int user_id;


public:

    Task(const string &title, const string &description, int userId) {
        this->title = title;
        this->description = description;
        this->user_id = userId;
        this->id=currentId;
        currentId++;
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

};

int Task::currentId = 1;

#endif //TODOS_TASK_H
