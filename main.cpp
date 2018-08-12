#include <iostream>
#include <string>
#include "lib/linenoise.h"

using namespace std;

class MyShell {
public:
    void handle_command(const string &line)
    {
	cout << "input command: " << line << endl;
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


