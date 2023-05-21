#pragma once

#define MAX_NAME_LENGTH 31
#define MAX_POST_LENGTH 255

/* Define post type below */
typedef struct post {
    char author[MAX_NAME_LENGTH + 1];
    int likes;
    char contents[MAX_POST_LENGTH + 1];
} post;



/* function prototypes; should be implemented in post.c */

/// creates a new post with the given fields;
/// will truncate author and contents if necessary
post create_post(char* author, int likes, char* contents);

/// true if post is "viral" (twice as many likes as length), 
/// false otherwise.
int post_is_viral(post* p);

/// prints a post to stdout
void print_post(post* p);
