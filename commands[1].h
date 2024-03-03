#ifndef _COMMANDS_H
#define _COMMANDS_H
#include <unistd.h> 
#include <stdio.h>
#include <cstdio>
#include <cerrno>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>    
#include <iostream>

#define MAX_LINE_SIZE 80
#define MAXARGS 20

using namespace std;

typedef struct Foreground {
	pid_t pid;
	string cmd;
	int jid;
}Foreground;

extern Foreground Fg;

extern char prev_path[];
extern char cur_path[];
class job{
public:
	pid_t pid;
	string cmd;
	bool is_stopped;
	time_t entered_time; // the time the job entered the list
	job();
	job(pid_t pidx,string cmdx,bool is_stoppedx,time_t entered_timex);
	job(const job& new_job);
	job& operator=(const job& new_job);
	~job();
};
void update_jobs_list();
bool check_if_built_in_cmd(string command);
int break_cmd_to_args(string input, string(&args)[MAXARGS], string delim = " \t\n");
bool insert_job(pid_t pID, string cmd, bool is_stopped = false, int job_id = -1);
int search_job(string& arg);
int find_stopped_job();
void fg_replace(pid_t pidx, string cmdx, int jidx = -1);
void fg_clean();
bool fg_empty();
bool is_number(string& str);
int BgCmd(string args[MAXARGS], int args_count, string command);
int ExeCmd(string args[MAXARGS], int args_count, string command);
int ExeExternal(string args[MAXARGS], int args_count, string command);
#endif

