#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define SQL_LEN 128

int isok(void *data,int colnum,char **ctext,char **cname)
{
	/*
	printf("colnum:%d\n",colnum);
	if (colnum != 1) {
		exit(1);
	}
	printf("ctext:%s\n",*ctext);
	printf("cname:%s\n",*cname);
	*/
	if (colnum != 1 ) {
		exit(1);
	}
	if (memcmp(*ctext,getenv("password"),strlen(getenv("password")))) {
		exit(1);
	}
	exit (0);
}

int main(int argc,char *argv[])
{
	/*
	setenv("username","ll",0);
	setenv("password","ll",0);
	*/
	const char *username = getenv("username");
	const char *password = getenv("password");
	const char *sqlite_file = "auth.db";
	char *sql_str = malloc(SQL_LEN);
	if (!(username && password)) {
		return 1;
	}
	sqlite3 *sql;
	if (sqlite3_open("auth.db",&sql) != SQLITE_OK) {
		return 1;
	}
	memset(sql_str,0,SQL_LEN);
	snprintf(sql_str,SQL_LEN -1,"%s%s%s",\
	"select password from auth where username='",\
	username,\
	"' limit 1;");
	/*printf("%s\n",sql_str);*/
	if (sqlite3_exec(sql,sql_str,isok,NULL,NULL) != SQLITE_OK) {
		return 1;
	}
	return 1;
}
