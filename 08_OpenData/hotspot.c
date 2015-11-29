#include "hotspot.h"
#include <string.h>


void getLat(const char* in, char* out) {
	char buffer[MAXLEN];
	char *ptr;
	strcpy(buffer, in);
	strtok(buffer, " (");
	ptr = strtok(NULL, " (");
	strcpy(out, ptr);


}
void getLon(const char* in, char* out) {
	char buffer[MAXLEN];
	char *ptr;
	strcpy(buffer, in);
	strtok(buffer, " ()");
	strtok(NULL, " ()");
	ptr = strtok(NULL, " ()");
	strcpy(out, ptr);

}
void getTitle(const char* in, char* out) {
	char buffer[MAXLEN];
	char *ptr;
	strcpy(buffer, in);
	strtok(buffer, ",");
	strtok(NULL, ",");
	strtok(NULL, ",");
	ptr = strtok(NULL, ",");
	strcpy(out, ptr);

}
void getDescription(const char* in, char* out) {
	char buffer[MAXLEN];
	char *ptr;
	strcpy(buffer, in);
    strtok(buffer, ",");
	strtok(NULL, ",");
	strtok(NULL, ",");
	strtok(NULL, ",");
	ptr = strtok(NULL, ",");
	strcpy(out, ptr);
}
