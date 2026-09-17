/**
 * @file storage.h
 * @author DargoDargonyx
 * @date 09/17/26
 */

#ifndef STORAGE_H
#define STORAGE_H

#include "external/cJSON.h"


// File paths
#define TEX_PROFILES_DATA_PATH "../data/tex_profiles.json"

// Tex profiles
typedef struct {
	int id;
	const char* name;
	const char* filepath;
} TexProfile;

void load_tex_profiles();
void store_tex_profiles();
void list_tex_profiles();

void set_tex_profile_name(int, const char*);

// Helper functions
int file_exists(const char*);
char* read_json(const char*);
int write_json(const cJSON*, const char*);

cJSON* tex_profile_to_json(TexProfile*);
int json_to_tex_profile(const cJSON*, TexProfile*);


#endif // STORAGE_H
