/************************************************** Description
 * *******************************************************/
/*
    File : main.cpp
    Programmer : Mohammad Lotfi
    Used : main
    Design Pattern : none
    Types of memory : Heap & Stack
    Total Tread : Nothing
    Site : https://www.mahsen.ir
    Tel : +989124662703
    Email : info@mahsen.ir
    Last Update : 2025/2/6
*/
/************************************************** Warnings
 * **********************************************************/
/*
    Nothing
*/
/************************************************** Wizards
 * ***********************************************************/
/*
    Nothing
*/
/************************************************** Includes
 * **********************************************************/
#include "Module/Print.hpp"
#include <sqlite3.h> // SQLite header
/************************************************** Defineds
 * **********************************************************/
/*
    Nothing
*/
/************************************************** Names
 * *************************************************************/
/*
    Nothing
*/
/************************************************** Variables
 * *********************************************************/
/*
    Nothing
*/
/************************************************** Opjects
 * ***********************************************************/
/*
    Nothing
*/
/************************************************** Functions
 * *********************************************************/
// Callback function to process query results
static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        Print((char*)azColName[i]);
        Print((char*)" = ");
        Println((char*)(argv[i] ? argv[i] : "NULL"));
    }
    Println((char*)"----------------------");
    return 0;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* The main function start of program in cpp language */
int main() {
    Println((char *)"Application: Start");

    sqlite3* db;
    char* errorMessage = 0;

    // Open database (creates if not exists)
    if (sqlite3_open("database.db", &db)) {
        Print((char*)"Error opening database: ");
        Println((char*)sqlite3_errmsg(db));
        return 1;
    }

    // SQL commands
    const char* sqlClearData = "DELETE FROM Users;";
    const char* sqlCreateTable = "CREATE TABLE IF NOT EXISTS Users (ID INTEGER PRIMARY KEY, Name TEXT, Age INTEGER);";
    const char* sqlInsertData = "INSERT INTO Users (Name, Age) VALUES ('Mohammad', 21), ('Zohre', 20);";
    const char* sqlSelectData = "SELECT * FROM Users;";

    // Execute SQL statements
    sqlite3_exec(db, sqlClearData, 0, 0, &errorMessage);
    sqlite3_exec(db, sqlCreateTable, 0, 0, &errorMessage);
    sqlite3_exec(db, sqlInsertData, 0, 0, &errorMessage);
    sqlite3_exec(db, sqlSelectData, callback, 0, &errorMessage);

    // Close database
    sqlite3_close(db);
    return 0;
}
/************************************************** Tasks
 * *************************************************************/
/*
    Nothing
*/
/************************************************** Vectors
 * ***********************************************************/
/*
    Nothing
*/
/**********************************************************************************************************************/
