#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>

// Enumeration of possible actions that can be performed by the user.
typedef enum OperationCode
{
    // 0- Used to indicate that the user wishes to exit the program.
    EXIT = 0,

    // USER ACTIONS
    // 1- Used to list all people (email and name) who have graduated in a certain course.
    LIST_BY_COURSE = 1,
    // 2- Used to list all people (email and name) who have a certain skill.
    LIST_BY_SKILL,
    // 3- Used to list all people (email, name, and course) who have graduated in a certain year.
    LIST_BY_YEAR,
    // 4- Used to list all the information of all profiles.
    LIST_ALL_PROFILES,
    // 5- Used to retrieve a profile's information based on its email.
    GET_PROFILE_BY_EMAIL,
    // 6- Used to download a profile's image based on its identifier (UDP only).
    DOWNLOAD_PROFILE_IMAGE,

    // ADMIN ACTIONS
    // 7- Used to remove a profile based on its email (admin only).
    REMOVE_PROFILE_BY_EMAIL,
    // 8- Used to create a new profile using an email as an identifier (admin only).
    NEW_PROFILE,
    // 9- Used to indicate that the user wishes to log in (admin only).
    LOGIN,
    // 10- Used to indicate that the user wishes to exit the program (admin only).
    LOGOUT
} OperationCode;

// Enumeration of possible status of the server response.
typedef enum StatusCode
{
    // Status code for successful action on the server
    SUCCESS = 200,

    // ERROR CODES
    // Status code for generic failure action on the server
    FAILURE = 400,
    // Status code for invalid password
    INVALID_PASSWORD = 401,
    // Status code for invalid session token
    INVALID_SESSION_TOKEN = 402,
    // Status code for failed profile registration
    REGISTRATION_FAILED = 403,
    // Status code for failed profile removal
    REMOVAL_FAILED = 404,
    // Status code for failed in the image recovering process
    RECOVER_IMAGE_FAILED = 405

} StatusCode;

// Some constants
#define OP_CODE_SIZE 1                                       // Size, in bytes, of the OperationCode
#define END_MESSAGE_POSITION_SIZE 4                          // Bytes to store the JSON's end in the message
#define HEADER_SIZE OP_CODE_SIZE + END_MESSAGE_POSITION_SIZE // Header size of the message, in bytes
#define IMAGES_DIRECTORY "images/"                           // Name of the images directory
#define UDP_MAX_CONTENT_DATA_SIZE 1024                       // Maximum size of the UDP packet content (without header)
#define IMAGE_HEADER_SIZE 8                                  // Size of the image's message header
#define DEFAULT_IMAGE_SIZE 6667                              // Size of the default image, in bytes
#define IMAGE_EXTENSION ".jpg"                               // The extension of the accepted images
#define MAX_LENGTH_IMAGE_NAME 111                            // 7("images/")+100(max email size)+4(".jpg")
#define MAXDATASIZE 64 * 1024                                // Max number of bytes we can get at once
#define PORT "4527"                                          // Peekaboo port number
#define SESSION_TOKEN_LENGTH 42                              // Session token length
#define MAX_SENT_PACKETS 256                                 // Max number of packets that can be sent in a single request
#define MAX_IMAGE_SIZE 250 * 1024                            // Max size of an image in bytes (250KB)
#define DEFAULT_IMAGE "default"                              // Name of the default image used for profiles without images
#define TCP_FLAG "--tcp"                                     // Flag to user server and client in TCP mode
#define HELP_FLAG "--help"                                   // Flag to acess the help info of server and client

typedef struct request
{
    OperationCode operation_code;
    char *data;
    int data_size;
} Request;

typedef struct response
{
    uint8_t *data;
    int data_size;
} Response;

#endif