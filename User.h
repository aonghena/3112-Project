//
// Created by Dawson Heide on 11/14/19.
//

//using namespace std;

#ifndef TODOS_USER_H
#define TODOS_USER_H

#include <string>
#include <vector>
#include "Task.h"
#include "Database.h"

class User {

private:

    int id = 0;
    string name;
    string email;
    string password;
    vector<Task> tasks;

public:

    User(string name, string email, string password) {
        this->name = name;
        this->email = email;
        this->password = password;
    }

    User(int id, string name, string email, string password){
        this->id = id;
        this->name = name;
        this->email = email;
        this->password = password;
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

    void save(Database *database) {
        if(this->id == 0) {
            this->id = database->createUser(this->name, this->email, this->password);
        }
    }

    static vector<User *> getAll(Database *database) {
        vector<User *> users;
        vector<UserData *> data = database->getUserData();
        users.reserve(data.size());
        for(int x = 0; x < data.size(); x++) {
            users.push_back(new User(data[x]->id, data[x]->name, data[x]->email, data[x]->password));
        }
        return users;
    }

};

#endif //TODOS_USER_H
