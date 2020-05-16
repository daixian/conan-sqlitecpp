#include <cstdlib>
#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <stdio.h>

int main()
{
    std::cout << "SQLite3 version " << SQLite::VERSION << " (" << SQLite::getLibVersion() << ")" << std::endl;
    remove("test.db3"); //删除存在的文件

    SQLite::Database db("test.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    db.rekey("123456"); //设置加密
    db.exec("DROP TABLE IF EXISTS sys_info");
    db.exec("DROP TABLE IF EXISTS stereo_camera");
    db.exec("DROP TABLE IF EXISTS cam_rt");

    db.exec("CREATE TABLE sys_info (id INTEGER PRIMARY KEY, dev_id INTEGER, dev_id_byte BLOB, dev_id_base64 TEXT, dev_ver TEXT, soft_ver TEXT, calib_ver TEXT)");
    db.exec("CREATE TABLE stereo_camera (id INTEGER PRIMARY KEY, name TEXT,M1 TEXT, D1 TEXT, M2 TEXT,D2 TEXT,R TEXT,T TEXT,E TEXT,F TEXT,R1 TEXT,R2 TEXT,P1 TEXT,P2 TEXT,Q TEXT)");
    db.exec("CREATE TABLE cam_rt (id INTEGER PRIMARY KEY,name TEXT, MSRT0 TEXT, MSRT1 TEXT)");

    db.exec("PRAGMA synchronous = OFF;");
    db.exec("PRAGMA locking_mode = EXCLUSIVE;");
    //db.exec("PRAGMA cache_size = 4000;");
    //db.exec("PRAGMA temp_store = FILE;");

    int nb = db.exec("INSERT INTO stereo_camera VALUES (NULL,'stereo0',?,?,?,?,?,?,?,?,?,?,?,?,?)");
    nb = db.exec("INSERT INTO stereo_camera VALUES (NULL,'stereo1',?,?,?,?,?,?,?,?,?,?,?,?,?)");
    nb = db.exec("INSERT INTO cam_rt VALUES (NULL,'camera_rt_mat',?,?)");

    return EXIT_SUCCESS;
}
