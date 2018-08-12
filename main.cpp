#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include "lib/linenoise.h"

using namespace std;

class MyShell {
public:
    void handle_command(const string &line)
    {
	int status = 0;
	int options = 0;
	cout << "input command: " << line << endl;
	pid_t pid;
	pid = fork();
	if (pid == 0) {
	    execl("/bin/sh", "sh", "-c", line.c_str(), NULL);
	} else {
	    waitpid(pid, &status, options);
	}
	/*
	 * Or you can directly call system command which will
	 * do same as above. Check man system
	 */
	//system(line.c_str());
    }

    void run()
    {
	char *line = NULL;
	while ((line = linenoise("rshell> ")) != NULL) {
	    handle_command(line);
	    linenoiseHistoryAdd(line);
	    linenoiseFree(line);
	}
    }
};

int main(int argc, char *argv[])
{
    MyShell rshell;
    rshell.run();
    return 0;
}


