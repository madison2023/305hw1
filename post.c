//post.c makes the posts that are used in feed

#include <string.h>
#include "post.h"
#include <stdio.h>

/// creates a new post with the given fields;
/// will truncate author and contents if necessary
post create_post(char* author, int likes, char* contents){
    
    if (author == NULL){
        author = "";
    }
    if (contents == NULL){
        contents = "";
    }
    //makes a new post
    post p;
    
    //puts data from parameters in new post, will truncate to MAX_NAME_LENGTH or MAX_POST_LENGTH if necessary
    strncpy(p.author, author, MAX_NAME_LENGTH);
    
    strncpy(p.contents, contents, MAX_POST_LENGTH);
    
    //setting the likes for the new post equal to the likes parameter
    p.likes = likes;
    
    //returns the new post object
    return p;
}

/// true if post is "viral" (twice as many likes as length),
/// false otherwise.
int post_is_viral(post* p) {
    if (p == NULL) {
        return 0;
    }
    if(p->likes > 2*strlen(p->contents)) {
        return 1;
    }
    else {
        return 0;
    }
}

/// prints a post to stdout
void print_post(post* p) {
    if (p != NULL) {
        printf("** %s **\n %s \n %d x <3\n", p->author, p->contents, p->likes);
    }
}
