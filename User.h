//
// Created by Dawson Heide on 11/14/19.
//

#include <string>
#include <vector>
#include "Task.h"

using namespace std;

#ifndef TODOS_USER_H
#define TODOS_USER_H

class User {

private:

    static int currentId;
    int id;
    string name;
    string email;
    string password;
    vector<Task> tasks;

public:

    User(string name, string email, string password) {
        this->name = name;
        this->email = email;
        this->password = password;
        this->id = currentId;
        currentId++;
    }

    int getId() const {
        return id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        this->email = email;
    }

    const string &getPassword() const {
        return password;
    }

    void setPassword(const string &password) {
        this->password = password;
    }

    const vector<Task> &getTasks() const {
        return tasks;
    }

};

int User::currentId = 1;

#endif //TODOS_USER_H
