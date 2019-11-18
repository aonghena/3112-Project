//
// Created by Dawson Heide on 11/14/19.
//

#include <iostream>
#include <string>
#include <sqlite3.h>

using namespace std;

#ifndef TODOS_DATABASE_H
#define TODOS_DATABASE_H

class Database {
private:
    sqlite3 *db;

public:

    Database() {
        char *messageError;
        int exit = sqlite3_open("todos.db", &db);

        if (exit) std::cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
        else std::cout << "Opened Database Successfully!" << std::endl;

        int fkeyConstraintsEnabled;
        exit = sqlite3_db_config(db, SQLITE_DBCONFIG_ENABLE_FKEY, 1, &fkeyConstraintsEnabled, &messageError);
        if( exit != SQLITE_OK ) {
            std::cerr << "Something went wrong" << std::endl;
            sqlite3_free(messageError);
        }
        printf( "Constraints now enabled: %d\r\n", fkeyConstraintsEnabled );

        string qry = "CREATE TABLE Users("
                 "id INT PRIMARY KEY     NOT NULL, "
                 "name           TEXT    NOT NULL, "
                 "email          TEXT     NOT NULL, "
                 "password            TEXT     NOT NULL); ";
        exit = sqlite3_exec(db, qry.c_str(), nullptr, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << "Users table already created." << std::endl;
            sqlite3_free(messageError);
        }

        qry = "CREATE TABLE Task("
              "id INT PRIMARY KEY     NOT NULL, "
              "title           TEXT    NOT NULL, "
              "description     TEXT     NOT NULL,  "
              "user_id         INT     NOT NULL);";

        exit = sqlite3_exec(db, qry.c_str(), nullptr, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << "Task table already created." << std::endl;
            sqlite3_free(messageError);
        }
    }
};


#endif //TODOS_DATABASE_H
