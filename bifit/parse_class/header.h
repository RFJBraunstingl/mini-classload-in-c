#include <stdio.h>
#include <stdlib.h>

void guess_java_version(char *major_version, char *target);

/**
 * Read the first 8 bytes from the class file
 * which provide information about the java version
 *
 * @param data
 */
void parse_class_header(const uint8_t data[]) {
    LOG_DEBUG("magic number is '%02x%02x %02x%02x'\n",
           data[0],
           data[1],
           data[2],
           data[3]
    );

    LOG_DEBUG("minor version: %02x%02x\n", data[4], data[5]);
    char major_version[5];
    sprintf(major_version, "%02x%02x", data[6], data[7]);
    LOG_DEBUG("major version: %s\n", major_version);

    char java_version_description[10];
    guess_java_version(major_version, java_version_description);
    LOG_DEBUG("guessing java version: %s\n", java_version_description);
}

void guess_java_version(char *major_version, char *target) {
    int version_number = (int) strtol(major_version, NULL, 16);
    LOG_DEBUG("major version number is %d\n", version_number);

    int java_version = version_number - 44;

    sprintf(target, "Java %d", java_version);
}