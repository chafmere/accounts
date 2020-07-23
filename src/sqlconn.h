#include <stdio.h>
#include <libpq-fe.h>

PGconn *conn;


int sqlcon(){

  conn = PQconnectdb("user=postgres password=test1234 dbname=dvdrental");
  int status = PQstatus(conn);

  return status;

}
