// signals.cpp
// contains signal handler funtions
// contains the function/s that set the signal handlers

/*******************************************/
#include "signals.h"

using namespace std;

extern Foreground Fg;

void sig_handler(int sig_number){
	if(sig_number==SIGINT){
		cout << "smash: caught ctrl-C" << endl;
	if (fg_empty()) {
		if (!kill(Fg.pid, SIGKILL)) {
			cout << "smash: process " << Fg.pid << " was killed" << endl;
			fg_clean();
		}
		else {
			perror("smash error: kill failed");
		}
	}
	else {
		printf("smash > ");
		fflush(stdout);

	}
	}
	else if (sig_number==SIGTSTP){
			cout << "smash: caught ctrl-Z" << endl;
	if (fg_empty()) {
		if (insert_job(Fg.pid, Fg.cmd, true,Fg.jid)) {
			if (!kill(Fg.pid, SIGSTOP)) {
				cout << "smash: process " << Fg.pid << " was stopped" << endl;
				fg_clean();
			}
			else {
				perror("smash error: kill failed");
			}
		}
		else {
			cerr << "smash error: insert_job failed\n";
		}
	}
	else {
		printf("smash > ");
		fflush(stdout);
	}
	}
}	
