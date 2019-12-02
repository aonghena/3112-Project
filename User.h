//
// Created by Dawson Heide on 11/14/19.
//

//using namespace std;

#ifndef TODOS_USER_H
#define TODOS_USER_H

#include <string>
#include <vector>
#include "Task.h"
#include "UrgentTask.h"
#include "Database.h"

class User {

private:
    int id = 0;
    string name;
    string email;
    string password;

public:
    /**
     * User
     * Constructor
     * @param name
     * @param email
     * @param password
     */
    User(string name, string email, string password) {
        this->name = name;
        this->email = email;
        this->password = password;
    }
    /**
     * User
     * @param id - User ID
     * @param name
     * @param email
     * @param password
     */
    User(int id, string name, string email, string password){
        this->id = id;
        this->name = name;
        this->email = email;
        this->password = password;
    }
    /**
     * getId
     * @return id
     */
    int getId() const {
        return id;
    }
    /**
     * getName
     * @return name
     */
    const string &getName() const {
        return name;
    }
    /**
     * setName
     * @param name
     */
    void setName(const string &name) {
        this->name = name;
    }
    /**
     * getEmail
     * @return email
     */
    const string &getEmail() const {
        return email;
    }
    /**
     * setEmail
     * @param email
     */
    void setEmail(const string &email) {
        this->email = email;
    }
    /**
     * getPassword
     * @return password
     */
    const string &getPassword() const {
        return password;
    }
    /**
     * setPassword
     * @param password
     */
    void setPassword(const string &password) {
        this->password = password;
    }
    /**
     * save
     * Saves user to db
     * @param database
     */
    void save(Database *database) {
        if(this->id == 0) {
            this->id = database->createUser(this->name, this->email, this->password);
        }
    }
    /**
     * getTasks
     * get User Tasks
     * @param database
     * @return vector of user tasks
     */
    vector<Task *> getTasks(Database *database) {
        vector<Task *> tasks;
        vector<TaskData *> data = database->getTaskData();

        for(auto & x: data) {
            if(x->user_id == this->id) {
                if(x->priority == 0) {
                    tasks.push_back(new Task(x->id, x->title, x->description, x->user_id, x->completed, x->created_at));
                }
            }
        }
        return tasks;
    }
    /**
     * getUTask
     * get users urgent tasks
     * @param database
     * @return vector of user Urgent Tasks
     */
    vector<UrgentTask *> getUTasks(Database *database) {

        vector<UrgentTask *> tasks;
        vector<TaskData *> data = database->getTaskData();

        for(auto & x: data) {
            if(x->user_id == this->id) {
                if(x->priority > 0) {
                    tasks.push_back(new UrgentTask(x->id, x->title, x->description, x->user_id, x->completed, x->priority, x->created_at));
                }
            }
        }
        return tasks;
    }
    /**
     * createTask
     * create task for user
     * @param database
     * @param title
     * @param description
     * @param priority
     */
    void createTask(Database *database, string title, string description, int priority = 0) {
        if(priority > 0) {
            UrgentTask *task = new UrgentTask(title, description, this->id, priority);
            task->save(database);
        } else {
            Task *task = new Task(title, description, this->id);
            task->save(database);
        }

    }
    /**
     * getAll
     * get all users
     * @param database
     * @return all users
     */
    static vector<User *> getAll(Database *database) {
        vector<User *> users;
        vector<UserData *> data = database->getUserData();
        users.reserve(data.size());
        for(int x = 0; x < data.size(); x++) {
            users.push_back(new User(data[x]->id, data[x]->name, data[x]->email, data[x]->password));
        }
        return users;
    }
    /**
     * getByEmailAndPassword
     * get user by email and password
     * @param database
     * @param email
     * @param password
     * @return User Object
     */
    static User* getByEmailAndPassword(Database *database, string email, string password) {

        vector<UserData *> data = database->getUserData("SELECT * FROM User"
                                                        " WHERE email=\"" + email +
                                                        "\" and password=\"" + password +"\";");

        if(data.size() > 1 || data.empty()) {
            return nullptr;
        }
        return new User(data[0]->id, data[0]->name, data[0]->email, data[0]->password);

    }

    static User* getByEmail(Database *database, string email) {
        vector<UserData *> data = database->getUserData("SELECT * FROM User"
                                                        " WHERE email=\"" + email +"\";");

        if(data.size() > 1 || data.empty()) {
            return nullptr;
        }
        return new User(data[0]->id, data[0]->name, data[0]->email, data[0]->password);
    }

};

#endif //TODOS_USER_H
