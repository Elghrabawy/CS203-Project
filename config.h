//
// Created by hima1 on 5/30/2024.
//

#ifndef OOP_PROJECT_CONFIG_H
#define OOP_PROJECT_CONFIG_H

#define DATABASE_PATH "../resources/database/project.db"
static const SQLite::Database db = SQLite::Database(DATABASE_PATH, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

#endif //OOP_PROJECT_CONFIG_H
