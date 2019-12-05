//
// Created by Dawson Heide on 11/14/19.
//

#ifndef TODOS_DATABASE_H
#define TODOS_DATABASE_H

#include <iostream>
#include <string>
#include <sqlite3.h>
#include <vector>

using namespace std;

/**
 * UserData
 * used for turning sql data into User objects
 */
struct UserData {
    int id;
    string name;
    string email;
    string password;
};

/**
 * TaskData
 * used for turning sql query data into Task objects
 */
struct TaskData {
    int id;
    string title;
    string description;
    int user_id;
    int completed;
    string created_at;
    int priority;
};


class Database {
private:
    //// sqlite database object
    sqlite3 *db;

    /**
     * Creates a user table in the database if not created
     */
    void createUserTable() {

        char *messageError;
        int exit;
        string qry = "CREATE TABLE User("
                     "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                     "name           TEXT    NOT NULL, "
                     "email          TEXT     NOT NULL, "
                     "password       TEXT     NOT NULL); ";
        exit = sqlite3_exec(db, qry.c_str(), nullptr, nullptr, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << messageError << std::endl;
            sqlite3_free(messageError);
        }

    }

    /**
     * Creates a task table in the database if not created
     */
    void createTaskTable() {
        char *messageError;
        int exit;
        string qry = "CREATE TABLE Task("
                     "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                     "title           TEXT    NOT NULL, "
                     "description     TEXT    NOT NULL,  "
                     "user_id         INT     NOT NULL,"
                     "created_at            TEXT    NOT NULL,"
                     "completed  INT NOT NULL DEFAULT 0,"
                     "priority INT DEFAULT 0);";

        exit = sqlite3_exec(db, qry.c_str(), nullptr, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << messageError << std::endl;
            sqlite3_free(messageError);
        }
    }

public:

    /**
     * Constructor for a Database object
     * creates and opens the database file if not already created
     */
    Database() {
        char *messageError;
        int exit = sqlite3_open("todos.db", &db);

        if (exit) std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
        else std::cout << "Opened Database Successfully!" << std::endl;

        this->createUserTable();
        this->createTaskTable();
    }

    /**
     * Gets all users from the database
     * @param qry - a custom qry for the database
     * @return a vector of UserData objects
     */
    vector<UserData *> getUserData(string qry = "") {

        if (qry == "") qry = "SELECT * FROM User";
        cout << qry << endl;
        vector<UserData *> users;
        char *messageError;

        sqlite3_stmt *stmt;
        int exit = sqlite3_prepare_v2(db, qry.c_str(), -1, &stmt, NULL);

        if (exit != SQLITE_OK) {
            cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
        }
        while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
            UserData *user = new UserData();
            user->id = sqlite3_column_int(stmt, 0);
            user->name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            user->email = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            user->password = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
            // let's assume number can be NULL:
            users.push_back(user);
        }

        if (exit != SQLITE_DONE) {
            cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
        }
        sqlite3_finalize(stmt);
        return users;

    }

    /**
     * Gets all the tasks in the database
     * @return a vector of TaskData objects
     */
    vector<TaskData *> getTaskData() {

        string qry = "SELECT * FROM Task";
        vector<TaskData *> tasks;
        char *messageError;

        sqlite3_stmt *stmt;
        int exit = sqlite3_prepare_v2(db, qry.c_str(), -1, &stmt, NULL);

        if (exit != SQLITE_OK) {
            cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
        }
        while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
            TaskData *task = new TaskData();
            task->id = sqlite3_column_int(stmt, 0);
            task->title = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            task->description = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            task->user_id = atoi(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)));
            task->created_at = atoi(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));
            task->completed = atoi(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5)));
            task->priority = atoi(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6)));
            // let's assume number can be NULL:
            tasks.push_back(task);
        }

        if (exit != SQLITE_DONE) {
            cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
        }
        sqlite3_finalize(stmt);
        return tasks;

    }

    /**
     * Takes user information and creates a user in the database
     *
     * @param name
     * @param email
     * @param password
     * @return
     */
    int createUser(string &name, string &email, string &password) {
        string qry = "INSERT INTO User (name, email, password)"
                     " VALUES(\"" + name + "\",\"" + email + "\",\"" + password + "\");";


        char *messageError;
        int exit = sqlite3_exec(this->db, qry.c_str(), nullptr, nullptr, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << messageError << std::endl;
            sqlite3_free(messageError);
            return 0;
        }

        int last_id = sqlite3_last_insert_rowid(this->db);
        return last_id;
    }

    /**
     * Takes task information and creates a task in the database
     *
     * @param title
     * @param description
     * @param user_id
     * @param created_at
     * @param priority
     * @return The new Task id
     */
    int createTask(string &title, string &description, int user_id, string created_at, int priority = 0) {

        string qry;
        if (priority != 0) {
            qry = "INSERT INTO Task (title, description, user_id, created_at, priority)"
                  " VALUES(\"" + title + "\",\""
                  + description + "\",\""
                  + to_string(user_id) + "\",\""
                  + created_at + "\",\""
                  + to_string(priority) + "\");";
        } else {
            qry = "INSERT INTO Task (title, description, created_at, user_id)"
                  " VALUES(\"" + title + "\",\""
                  + description + "\",\""
                  + created_at + "\",\""
                  + to_string(user_id) + "\");";
        }

        char *messageError;
        int exit = sqlite3_exec(this->db, qry.c_str(), nullptr, nullptr, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << messageError << std::endl;
            sqlite3_free(messageError);
            return 0;
        }

        int last_id = sqlite3_last_insert_rowid(this->db);
        return last_id;
    }

    /**
     * Updates a task in the database using a sql query
     *
     * @param id of a task
     * @param title of a task
     * @param description
     * @param completed
     * @param priority
     */
    void updateTask(int id, string &title, string &description, int completed, int priority = 0) {

        cout << "update task" << endl;
        string qry;
        if (priority != 0) {
            qry = "UPDATE Task SET title=\"" + title + "\","
                  + "description=\"" + description + "\","
                  + "completed=" + to_string(completed) + ","
                  + "priority=" + to_string(priority) + " "
                  + "WHERE id=" + to_string(id) + ";";
        } else {
            qry = "UPDATE Task SET title=\"" + title + "\","
                  + "description=\"" + description + "\","
                  + "completed=" + to_string(completed) + " "
                  + "WHERE id=" + to_string(id) + ";";
        }

        cout << "qry: " << qry << endl;

        char *messageError;
        int exit = sqlite3_exec(this->db, qry.c_str(), nullptr, nullptr, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << messageError << std::endl;
            sqlite3_free(messageError);
        }
    }

    /**
     *
     * Deletes a task from the database using an sql query
     * @param id of a task
     */
    void deleteTask(int id) {

        cout << "delete task" << endl;
        string qry;

        qry = "DELETE FROM Task WHERE id=" + to_string(id) + ";";

        cout << "qry: " << qry << endl;

        char *messageError;
        int exit = sqlite3_exec(this->db, qry.c_str(), nullptr, nullptr, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << messageError << std::endl;
            sqlite3_free(messageError);
        }
    }
};


#endif //TODOS_DATABASE_H
