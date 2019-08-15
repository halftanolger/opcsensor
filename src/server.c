#include <signal.h>
#include "open62541.h" 
//The library includes several basic types used in the OPC-UA standard. When possible it is best to use these types.
UA_Boolean running = true; 
//Handler that allows to stop server running when doing a ctrl-c in the command line
static void stopHandler(int sig) {
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Received ctrl-c");
	running = false;
}
int main(void) { 
	signal(SIGINT, stopHandler);
	signal(SIGTERM, stopHandler); 
	//Create a new server with default configuration
	UA_ServerConfig *config = UA_ServerConfig_new_default();
	UA_Server *server = UA_Server_new(config); 
	//This line runs the server in a loop while the running variable is true. It's important that initializations and other things done in our code are before this function call.
	UA_StatusCode retval = UA_Server_run(server, &running); 
	//When the server stops running we free the resources
	UA_Server_delete(server);
	UA_ServerConfig_delete(config);
	return (int)retval;
}