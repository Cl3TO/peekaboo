#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../../lib/sqlite3/sqlite3.h"

#include "../../model/profile.h"
#include "../../utils/constants.h"

// Store the profile in the database using sqlite3
// Returns 0 if the profile was stored successfully
// Returns -1 if the profile was not stored
int store_profile(Profile *profile);

// Get all the profiles by academic degree from the database using sqlite3
// The information retrived is the name, last name and email
// Returns the number of profiles were retrieved successfully
// Returns -1 if the profiles were not retrieved
int get_profiles_by_course(Profile *profiles, char *course);

// List all the profiles from the database that have the skills
// The information retrived is the name, last name and email
// Returns the number of profiles were retrieved successfully
// Returns -1 if the profiles were not retrieved
int get_profiles_by_skill(Profile *profiles, char *skills);

// List all the profiles from the database that have the year of degree
// The information retrived is the name, last name , email and academic degree
// Returns the number of profiles were retrieved successfully
// Returns -1 if the profiles were not retrieved
int get_profiles_by_year_of_degree(Profile *profiles, int year_of_degree);

// List all profiles from the database
// Returns the number of profiles were retrieved successfully
// Returns -1 if the profiles were not retrieved
int get_profiles(Profile *profiles);

// Get the profile from the database using sqlite3
// Returns the number of profiles were retrieved successfully
// Returns -1 if the profile was not retrieved
int get_profile_by_email(Profile *profile, char *email);

// Delete the profile from the database that have the email
// Returns 0 if the profile was deleted successfully
// Returns -1 if the profile was not deleted
int delete_profile_by_email(char *email);

// Get the image size of the given email's profile using sqlite3
// Returns the profile's image size were retrieved successfully
// Returns 0 if the profile exists but haven't image
// Returns -1 if error or profile not exists
int get_image_size_by_email(char *email);

#endif