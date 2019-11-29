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

struct UserData {
    int id;
    string name;
    string email;
    string password;
};

struct TaskData {
    int id;
    string title;
    string description;
    int user_id;
    int completed;
    int priority;
};


class Database {
private:
    sqlite3 *db;

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

    void createTaskTable() {
        char *messageError;
        int exit;
        string qry = "CREATE TABLE Task("
                     "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                     "title           TEXT    NOT NULL, "
                     "description     TEXT     NOT NULL,  "
                     "user_id         INT     NOT NULL,"
                     "completed  INT NOT NULL DEFAULT 0,"
                     "priority INT DEFAULT 0);";

        exit = sqlite3_exec(db, qry.c_str(), nullptr, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << messageError << std::endl;
            sqlite3_free(messageError);
        }
    }

public:

    Database() {
        char *messageError;
        int exit = sqlite3_open("todos.db", &db);

        if (exit) std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
        else std::cout << "Opened Database Successfully!" << std::endl;

        this->createUserTable();
        this->createTaskTable();
    }

    vector<UserData *> getUserData(string qry = "") {

        if(qry == "") qry = "SELECT * FROM User";
        cout << qry << endl;
        vector<UserData *> users;
        char *messageError;

        sqlite3_stmt *stmt;
        int exit = sqlite3_prepare_v2(db, qry.c_str(),-1, &stmt, NULL);

        if (exit != SQLITE_OK) {
            cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
        }
        while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
            UserData *user = new UserData();
            user->id = sqlite3_column_int(stmt, 0);
            user->name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            user->email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            user->password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            // let's assume number can be NULL:
            users.push_back(user);
        }

        if (exit != SQLITE_DONE) {
            cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
        }
        sqlite3_finalize(stmt);
        return users;

    }

    vector<TaskData *> getTaskData() {

        string qry = "SELECT * FROM Task";
        vector<TaskData *> tasks;
        char *messageError;

        sqlite3_stmt *stmt;
        int exit = sqlite3_prepare_v2(db, qry.c_str(),-1, &stmt, NULL);

        if (exit != SQLITE_OK) {
            cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
        }
        while ((exit = sqlite3_step(stmt)) == SQLITE_ROW) {
            TaskData *task = new TaskData();
            task->id = sqlite3_column_int(stmt, 0);
            task->title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            task->description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            task->user_id = atoi(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
            task->completed = atoi(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
            task->priority = atoi(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
            // let's assume number can be NULL:
            tasks.push_back(task);
        }

        if (exit != SQLITE_DONE) {
            cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
        }
        sqlite3_finalize(stmt);
        return tasks;

    }

    int createUser(string& name, string& email, string& password) {
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

    int createTask(string& title, string& description, int user_id, int priority = 0) {

        string qry;

        if(priority != 0) {
            qry = "INSERT INTO Task (title, description, user_id, priority)"
                         " VALUES(\"" + title + "\",\"" + description + "\"," + to_string(user_id) + "," + to_string(priority) + ");";
        } else {
            qry = "INSERT INTO Task (title, description, user_id)"
                         " VALUES(\"" + title + "\",\"" + description + "\",\"" + to_string(user_id) + "\");";
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

    void updateTask(int id, string& title, string& description, int completed, int priority = 0) {

        cout << "update task" << endl;
        string qry;
        if(priority != 0) {
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

};


#endif //TODOS_DATABASE_H
