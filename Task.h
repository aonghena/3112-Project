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

    int id = 0;
    string title;
    string description;
    int user_id;
    int completed = 0;
    string created_at;

public:
    /**
     * Task
     * Constructor
     * @param title - title of task
     * @param description -description of task
     * @param userId - user id
     */
    Task(const string &title, const string &description, int userId) {
        this->title = title;
        this->description = description;
        this->user_id = userId;
        time_t t ;
        struct tm *tmp ;
        char MY_TIME[50];
        time( &t );
        tmp = localtime( &t );
        strftime(MY_TIME, sizeof(MY_TIME), "%D %R", tmp);
        this->created_at = MY_TIME;
    }

    /**
     * Task
     * Constructor
     * @param id - task id
     * @param title - title of task
     * @param description - description of task
     * @param userId - user Id task owner
     * @param completed - completed or not
     * @param created_at - created time
     */
    Task(int id, const string &title, const string &description, int userId, int completed, string created_at) {
        this->id = id;
        this->title = title;
        this->description = description;
        this->user_id = userId;
        this->completed = completed;
        this->created_at = created_at;
    }
    /**
     * getId
     * @return id
     */
    int getId() const {
        return id;
    }
    /**
     * getCreatedAt
     * @return  created_at
     */
    const string &getCreatedAt() const {
        return created_at;
    }
    /**
     * getTitle
     * @return title
     */
    const string &getTitle() const {
        return title;
    }
    /**
     * setTitle
     * @param title - task title
     */
    void setTitle(const string &title) {
        Task::title = title;
    }
    /**
     * getDescription
     * @return description
     */
    const string &getDescription() const {
        return description;
    }
    /**
     * setDescription
     * @param description - task desc
     */
    void setDescription(const string &description) {
        Task::description = description;
    }
    /**
     * getUserId
     * @return userId
     */
    int getUserId() const {
        return user_id;
    }

    void setUserId(int userId) {
        user_id = userId;
    }
    /**
     * isCompleted
     * @return if completed
     */
    int isCompleted() const {
        return completed;
    }
    /**
     * complete
     * setTask to be complete or not
     */
    void complete() {
        this->completed = !this->completed;
    }
    /**
     * save
     * saves task to database
     * @param database
     */
    virtual void save(Database *database) {
        if(this->id == 0) {
            this->id = database->createTask(this->title, this->description, this->user_id, this->created_at);
        } else {
            database->updateTask(this->id, this->title, this->description, this->completed);
        }
    }
    /**
     * getTasks
     * @param database
     * @return vector of normal tasks
     */
    static vector<Task*> getTasks(Database *database) {

        vector<Task*> tasks;
        vector<TaskData*> taskData = database->getTaskData();

        for(int x = 0; x < taskData.size(); x++) {
            tasks.push_back(new Task(taskData[x]->id, taskData[x]->title, taskData[x]->description,
                                     taskData[x]->user_id, taskData[x]->completed, taskData[x]->created_at));
        }

        return tasks;

    }

};

#endif //TODOS_TASK_H
